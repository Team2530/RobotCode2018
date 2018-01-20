#include "DriveTrain.h"
#include "../RobotMap.h"
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Drive/DifferentialDrive.h>
#include <Spark.h>
#include <math.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrainSubsystem") {
	frontLeftController = new WPI_TalonSRX(kFrontLeftChannel);
	frontRightController = new WPI_TalonSRX(kFrontRightChannel);
	backLeftController = new WPI_VictorSPX(kBackLeftChannel);
	backRightController = new WPI_VictorSPX(kBackRightChannel);
	leftSide = new SpeedControllerGroup(*frontLeftController, *backLeftController);//CHANGE POINTER TO REFERENCE = *
	rightSide = new SpeedControllerGroup(*frontRightController, *backRightController);
	robotDrive = new DifferentialDrive(*leftSide, *rightSide); //pointer to reference again :)

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new SkidStearWithJoystick());

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

void DriveTrain::Stop(){
	robotDrive->ArcadeDrive(0,0);
}

double DriveFunction(double inSpeed) {
	double outSpeed = pow(inSpeed, 3) + .1*inSpeed;
	return outSpeed;
}

