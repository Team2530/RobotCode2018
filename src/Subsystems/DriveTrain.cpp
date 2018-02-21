#include "DriveTrain.h"
#include "../RobotMap.h"
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Drive/DifferentialDrive.h>
#include <Spark.h>
#include <math.h>
#include <networktables/NetworkTableInstance.h>
#include <Commands/SkidStearWithJoystick.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrainSubsystem"),
	ahrs(nullptr), // obtained from OI later
	leftLastMeasurement(0),
	rightLastMeasurement(0),
	currentPositionX(0),
	currentPositionY(0),
	previousPositionX(0),
	previousPositionY(0),
	previousAngle(0),
	angleAdjustment(0) {

	frontLeftController = new WPI_TalonSRX(kFrontLeftChannel);
	//frontLeftController -> SetInverted(true);
	frontLeftController -> SetInverted(false);
	frontRightController = new WPI_TalonSRX(kFrontRightChannel);
	frontRightController -> SetInverted(true);
	backLeftController = new WPI_VictorSPX(kBackLeftChannel);
	//backLeftController -> SetInverted(true);
	backLeftController -> SetInverted(false);
	backLeftController->Follow(*frontLeftController);
	backRightController = new WPI_VictorSPX(kBackRightChannel);
	backRightController -> SetInverted(true);
	backRightController->Follow(*frontRightController);
	robotDrive = new DifferentialDrive(*frontLeftController, *frontRightController); //pointer to reference again :)

	frontLeftController->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	frontRightController->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0,0);
	//leftEncoder->SetDistancePerPulse(ticksPerRevolution*diameter*pi);
	//rightEncoder->SetDistancePerPulse(ticksPerRevolution*diameter*pi);
	//ROBOT 27.5inch by 32.5inch, drives long end front

	nt::NetworkTableInstance nti;
	table = nti.GetTable("robotPosition");
	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new SkidStearWithJoystick());

	leftLastMeasurement = 0;
	rightLastMeasurement = 0;
}

void DriveTrain::Drive(Joystick* stick) {
	double stickY = stick->GetY();
	double stickZ = stick->GetZ();
	double stickY2 = DriveFunction(stickY);
	double stickZ2 = DriveFunction(stickZ);
	robotDrive->ArcadeDrive(stickY2, stickZ2);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveStraight(Joystick* stick) {
	double stickY = stick->GetY();

	robotDrive->ArcadeDrive(stickY, 0);
}
void DriveTrain::DriveStraight(double speed){
	robotDrive->ArcadeDrive(speed, 0);
}
void DriveTrain::DriveStraightAuto(double distance){
	distance = distance*360/pi/diameter;//WE MUST CHECK THIS GWUYS
	double startingDistance = GetEncoderDistance();
	while((GetEncoderDistance()-startingDistance)<distance){
		double power = (((GetEncoderDistance()-startingDistance)-distance)/10)*minPower;
		DriveStraight(power);
	}
}
void DriveTrain::Stop(){
	robotDrive->ArcadeDrive(0,0);
}
void DriveTrain::Turn(double degrees){
		if(degrees>0){
			robotDrive->ArcadeDrive(0, .1);//.1 is a guess of how much power wanted for turn. Can change
		}
		else{
			robotDrive->ArcadeDrive(0,-.1);//see above
		}
}

double DriveTrain::DriveFunction(double inSpeed) {
	double outSpeed = .25*pow(inSpeed, 3) + .75*inSpeed;
	SmartDashboard::PutNumber("FY", outSpeed);
	return outSpeed;
}
void DriveTrain::StartTracking(double initialX, double initialY, double initialAngle){
	currentPositionX = initialX;
	currentPositionY = initialY;
	angleAdjustment = initialAngle;
	if (ahrs != nullptr) {
		ahrs->Reset();
	}
}
double DriveTrain::GetEncoderDistance(){
	return (frontLeftController->GetSelectedSensorPosition(0) + frontRightController->GetSelectedSensorPosition(0))/2;
}
void DriveTrain::UpdatePosition(){
	double left = frontLeftController->GetSelectedSensorPosition(0);
	double right = frontRightController->GetSelectedSensorPosition(0);
	double distanceLeft = left - leftLastMeasurement;
	double distanceRight = right - rightLastMeasurement;
	currentAngle=GetCurrentAngle();
	// Only do our calculations if at least one encoder's value has changed
	if (distanceLeft != 0 || distanceRight != 0) {
		leftLastMeasurement = left;
		rightLastMeasurement = right;
		double rad = currentAngle * pi / 180;
		averageEncoder = (left+right)/2;
		double changeInX = sin(rad)*averageEncoder;
		double changeInY = cos(rad)*averageEncoder;
		currentPositionX += changeInX;
		currentPositionY += changeInY;
	}
	table->PutNumber("x", currentPositionX);
	table->PutNumber("y", currentPositionY);
	table->PutNumber("angle", currentAngle);
}
double DriveTrain::GetCurrentAngle(){
	double angle =  ahrs != nullptr ? ahrs->GetYaw()+angleAdjustment : 0.01;
	// Rotate the output around by a full resolution if it is outside of +/-180
	// (This will only occur if angleAdjustment is nonzero, as GetYaw is always in that range)
	while (angle > 180) angle -= 360;
	while (angle < -180) angle += 360;
	return angle;
}
