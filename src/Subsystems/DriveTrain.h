#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <Joystick.h>
#include <VictorSPX.h>

class DriveTrain : public Subsystem {
private:
	static constexpr int kFrontLeftChannel = 1;
	static constexpr int kBackLeftChannel = 2;
	static constexpr int kFrontRightChannel = 0;
	static constexpr int kBackRightChannel = 3;

	VictorSPX* frontLeftController;
	VictorSPX* backLeftController;
	VictorSPX* frontRightController;
	VictorSPX* backRightController;
	SpeedControllerGroup* leftSide;
	SpeedControllerGroup* rightSide;
	DifferentialDrive* robotDrive;

public:
	DriveTrain();
	void InitDefaultCommand();

	void TeleopPeriodic() {
		robotDrive.ArcadeDrive(stick.GetY(), stick.GetX());
	}
};

#endif  // DriveTrain_H
