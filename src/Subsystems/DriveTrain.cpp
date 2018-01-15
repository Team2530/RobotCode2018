#include "DriveTrain.h"
#include "../RobotMap.h"
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Drive/DifferentialDrive.h>
#include <Spark.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrainSubsystem") {
	frontLeftController = new VictorSPX(kFrontLeftChannel);
	frontRightController = new VictorSPX(kFrontRightChannel);
	backLeftController = new VictorSPX(kBackLeftChannel);
	backRightController = new VictorSPX(kBackRightChannel);
	leftSide = new SpeedControllerGroup(frontLeftController, backLeftController);
	rightSide = new SpeedControllerGroup(frontRightController, backRightController);
	robotDrive = new DifferentialDrive(leftSide, -rightSide);
	//frc::SpeedControllerGroup leftSide{frontLeftController, backLeftController};
	//frc::SpeedControllerGroup rightSide{frontRightController, backRightController};
	//frc::DifferentialDrive robotDrive{leftSide, -rightSide};
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
