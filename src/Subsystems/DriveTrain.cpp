#include "DriveTrain.h"
#include "../RobotMap.h"
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Drive/DifferentialDrive.h>
#include <Spark.h>

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
void DriveTrain::Drive(Joystick* stick){
	double stickY = stick->GetY();
	double stickZ = stick->GetZ();
	robotDrive->ArcadeDrive(stickY, stickZ);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveStraight(Joystick* stick) {
	double stickY = stick->GetY();
	robotDrive->ArcadeDrive(stickY, 0);
}
