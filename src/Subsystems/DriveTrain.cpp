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


double constexpr kF = .001;
double constexpr kP = .01;

DriveTrain::DriveTrain() : Subsystem("DriveTrainSubsystem"),
ahrs(nullptr), // obtained from OI later
leftLastMeasurement(0),
rightLastMeasurement(0),
currentPositionX(0),
currentPositionY(0),
previousPositionX(0),
previousPositionY(0),
previousAngle(0),
angleAdjustment(0)
{

	frontLeftController = new WPI_TalonSRX(kFrontLeftChannel);
	//frontLeftController -> SetInverted(true);
	//frontLeftController -> SetInverted(false);
	frontRightController = new WPI_TalonSRX(kFrontRightChannel);
	//frontRightController -> SetInverted(true);
	backLeftController = new WPI_VictorSPX(kBackLeftChannel);
	//backLeftController -> SetInverted(true);
	//backLeftController -> SetInverted(false);
	backLeftController->Follow(*frontLeftController);
	backRightController = new WPI_VictorSPX(kBackRightChannel);
	//backRightController -> SetInverted(true);
	backRightController->Follow(*frontRightController);
	robotDrive = new DifferentialDrive(*frontLeftController, *frontRightController); //pointer to reference again :)

	frontLeftController->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	frontRightController->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0,0);

	ResetPIDs();
	//frontLeftController->SetSelectedSensorPosition(frontLeftController->GetSelectedSensorPosition(0), 0,0);
/*	frontLeftController->ConfigNominalOutputForward(0,kTimeoutMs);
	frontLeftController->ConfigNominalOutputReverse(0, kTimeoutMs);
	frontLeftController->ConfigPeakOutputForward(1, kTimeoutMs);
	frontLeftController->ConfigPeakOutputReverse(-1, kTimeoutMs);
	//frontLeftController->SetSensorPhase(true);

	//frontRightController->SetSelectedSensorPosition(frontRightController->GetSelectedSensorPosition(0), 0,0);
	frontRightController->ConfigNominalOutputForward(0,kTimeoutMs);
	frontRightController->ConfigNominalOutputReverse(0, kTimeoutMs);
	frontRightController->ConfigPeakOutputForward(1, kTimeoutMs);
	frontRightController->ConfigPeakOutputReverse(-1, kTimeoutMs);

	frontLeftController->Config_kF(kPIDLoopIdx, kF, kTimeoutMs);
	frontLeftController->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	frontLeftController->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	frontLeftController->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

	frontRightController->Config_kF(kPIDLoopIdx, kF, kTimeoutMs);
	frontRightController->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	frontRightController->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	frontRightController->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);*/

	//SmartDashboard::PutNumber("Left encoder start: ", frontLeftController->GetSelectedSensorPosition(0));
	//SmartDashboard::PutNumber("Right Encoder start: ", frontRightController->GetSelectedSensorPosition(0));
	//update=0;
	//leftEncoder->SetDistancePerPulse(ticksPerRevolution*diameter*pi);
	//rightEncoder->SetDistancePerPulse(ticksPerRevolution*diameter*pi);
	//ROBOT 27.5inch by 32.5inch, drives long end front

	nt::NetworkTableInstance nti;
	table = nti.GetTable("robotPosition");
	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();



	robotDrive->SetSafetyEnabled(false);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new SkidStearWithJoystick());

	leftLastMeasurement = 0;
	rightLastMeasurement = 0;
}

void DriveTrain::TankDrive(Joystick* stick1, Joystick* stick2){
	robotDrive->TankDrive(stick1->GetY(), stick2->GetY(), 0);
}

void DriveTrain::Drive(Joystick* stick) {
	double stickY = stick->GetY();
	double stickZ = stick->GetZ();
	double stickY2 = DriveFunction(stickY);
	double stickZ2 = DriveFunction(stickZ);
	SmartDashboard::PutNumber("y: ", stickY);
	SmartDashboard::PutNumber("encoders:  ", GetEncoderDistance());
	//SmartDashboard::PutNumber("Right Encoder2: ", frontRightController->GetSelectedSensorPosition(0));
	//update +=1;
	//SmartDashboard::PutNumber("update: ", update);
	robotDrive->ArcadeDrive(stickY2, -stickZ2);//inverted is quick fix
	frontLeftController->GetSelectedSensorVelocity(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveStraight(Joystick* stick, double StartingAngle) {
	double angle = GetCurrentAngle();
	double turn = 0;

	if(StartingAngle > angle) {
		//frontLeftController power +
		//frontRightController power -
		turn = 0.1*(StartingAngle-angle);
	} else if (StartingAngle < angle) {
		//frontLeftController power -
		//frontRightController power +
		turn = -0.1*(angle-StartingAngle);
	}

	double stickY = stick->GetY();
	SmartDashboard::PutNumber("encoders:  ", GetEncoderDistance());
	robotDrive->ArcadeDrive(stickY, turn);
}
void DriveTrain::DriveStraight(double rotations, double StartingAngle){
	double angle = Robot::drivetrain->GetCurrentAngle();

	double error = 0.1*ModAngle(StartingAngle-angle);
			SmartDashboard::PutNumber("Error: ", error);
	if(error < 0) {
		//frontLeftController power +
		//frontRightController power -
		double power=1+(error);
		frontLeftController->ConfigPeakOutputForward(1, kTimeoutMs);
		frontLeftController->ConfigPeakOutputReverse(-1, kTimeoutMs);
		frontRightController->ConfigPeakOutputForward(power, kTimeoutMs);
		frontRightController->ConfigPeakOutputReverse(-power, kTimeoutMs);
		frontLeftController->Config_kP(kPIDLoopIdx, kP*(1-error), kTimeoutMs);
		frontRightController->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	}
//		frontLeftController->Config_kF(kPIDLoopIdx, kF*(1-error), kTimeoutMs);
	else if (error > 0) {
		//frontLeftController power -
		//frontRightController power +
		double power=1-(error);
		frontLeftController->ConfigPeakOutputForward(power, kTimeoutMs);
		frontLeftController->ConfigPeakOutputReverse(-power, kTimeoutMs);
		frontRightController->ConfigPeakOutputForward(1, kTimeoutMs);
		frontRightController->ConfigPeakOutputReverse(-1, kTimeoutMs);
		frontRightController->Config_kP(kPIDLoopIdx, kP*(1+error), kTimeoutMs);
		frontLeftController->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	}
	frontLeftController->ConfigNominalOutputForward(.2, kTimeoutMs);
	frontLeftController->ConfigNominalOutputReverse(-.2, kTimeoutMs);
	frontRightController->ConfigNominalOutputForward(.2, kTimeoutMs);
	frontRightController->ConfigNominalOutputReverse(-.2, kTimeoutMs);

	frontLeftController->Set(ControlMode::Position, -rotations);
	frontRightController->Set(ControlMode::Position, rotations);
	//robotDrive->ArcadeDrive(speed, 0);
	SmartDashboard::PutNumber("encoders:  ", GetEncoderDistance());
	SmartDashboard::PutNumber("encoder right: ", frontRightController->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("encoder left: ", -frontLeftController->GetSelectedSensorPosition(0));
}
/*void DriveTrain::DriveStraightAuto(double distance){
	distance = distance*(360/(pi*diameter));//WE MUST CHECK THIS GWUYS ticks = inches*(360/circumference)
	double startingDistance = GetEncoderDistance();
	while((GetEncoderDistance()-startingDistance)<distance){
		double power = (((GetEncoderDistance()-startingDistance)-distance)/10)*minPower;
		DriveStraight(power);
	}
}*/
void DriveTrain::Stop(){
	robotDrive->ArcadeDrive(0,0);
}
void DriveTrain::Turn(double fix){

	robotDrive->ArcadeDrive(0,fix);//see above //inverted is quick fix

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
	return (-frontLeftController->GetSelectedSensorPosition(0) + frontRightController->GetSelectedSensorPosition(0))/2;
}
void DriveTrain::SetEncoderDistance(double value){
	frontLeftController->SetSelectedSensorPosition(value, 0,0);
	frontRightController->SetSelectedSensorPosition(value, 0,0);
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
	double angle =  ahrs != nullptr ? ahrs->GetYaw() : 0.01;
	// Rotate the output around by a full resolution if it is outside of +/-180
	// (This will only occur if angleAdjustment is nonzero, as GetYaw is always in that range)
	return -ModAngle(angle);
}
double DriveTrain::ModAngle(double angle){
	while (angle > 180) angle -= 360;
	while (angle < -180) angle += 360;
	return angle;
}
void DriveTrain::InitIdealAngle(){
	ahrs->ZeroYaw();
	while(GetCurrentAngle()!=0);
	idealAngle = GetCurrentAngle();
	SmartDashboard::PutNumber("initial ideal", idealAngle);
}
double DriveTrain::GetIdealAngle(){
	return idealAngle;
}
void DriveTrain::AddToIdealAngle(double degrees){
	idealAngle = ModAngle(idealAngle+degrees);
}
void DriveTrain::ResetPIDs(){
	frontLeftController->ConfigNominalOutputForward(0,kTimeoutMs);
	frontLeftController->ConfigNominalOutputReverse(0, kTimeoutMs);
	frontLeftController->ConfigPeakOutputForward(1, kTimeoutMs);
	frontLeftController->ConfigPeakOutputReverse(-1, kTimeoutMs);
	//frontLeftController->SetSensorPhase(true);

	//frontRightController->SetSelectedSensorPosition(frontRightController->GetSelectedSensorPosition(0), 0,0);
	frontRightController->ConfigNominalOutputForward(0,kTimeoutMs);
	frontRightController->ConfigNominalOutputReverse(0, kTimeoutMs);
	frontRightController->ConfigPeakOutputForward(1, kTimeoutMs);
	frontRightController->ConfigPeakOutputReverse(-1, kTimeoutMs);

	frontLeftController->Config_kF(kPIDLoopIdx, kF, kTimeoutMs);
	frontLeftController->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	frontLeftController->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	frontLeftController->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

	frontRightController->Config_kF(kPIDLoopIdx, kF, kTimeoutMs);
	frontRightController->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	frontRightController->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	frontRightController->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);
}
