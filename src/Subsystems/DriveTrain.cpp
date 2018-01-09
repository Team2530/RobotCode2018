#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrainSubsystem") {
	frontLeftController = new VictorSP(kFrontLeftChannel);
	rearLeftController = new VictorSP(kRearLeftChannel);
	frontRightController = new VictorSP(kFrontRightChannel);
	rearRightController = new VictorSP(kRearRightChannel);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
