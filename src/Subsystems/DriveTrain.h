#ifndef DriveTrain_H
#define DriveTrain_H
#include <VictorSP.h>
#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <Joystick.h>
#include <ctre/Phoenix.h>
#include "HAL/HAL.h"


class DriveTrain : public Subsystem {
private:
	static constexpr int kFrontLeftChannel = 1;
	static constexpr int kBackLeftChannel = 2;
	static constexpr int kFrontRightChannel = 0;
	static constexpr int kBackRightChannel = 3;

	WPI_TalonSRX* frontLeftController;
	WPI_VictorSPX* backLeftController;
	WPI_TalonSRX* frontRightController;
	WPI_VictorSPX* backRightController;
	SpeedControllerGroup* leftSide;
	SpeedControllerGroup* rightSide;
	DifferentialDrive* robotDrive;

public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive(Joystick* stick);
	void TeleopPeriodic();
	void DriveStraight(Joystick* stick);
	void Stop();
	double DriveFunction(double inSpeed);
};

#endif  // DriveTrain_H
