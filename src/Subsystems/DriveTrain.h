#ifndef DriveTrain_H
#define DriveTrain_H
#include <VictorSP.h>
#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <Joystick.h>
#include <ctre/Phoenix.h>
#include "HAL/HAL.h"
#include <Encoder.h>


class DriveTrain : public Subsystem {
private:
	static constexpr int kFrontLeftChannel = 1;
	static constexpr int kBackLeftChannel = 2;
	static constexpr int kFrontRightChannel = 0;
	static constexpr int kBackRightChannel = 3;
	static constexpr double ticksPerRevolution = 1/1000;
	static constexpr double diameter = 6; //inches
	static constexpr double pi = 2*acos(0.0);

	WPI_TalonSRX* frontLeftController;
	WPI_VictorSPX* backLeftController;
	WPI_TalonSRX* frontRightController;
	WPI_VictorSPX* backRightController;
	SpeedControllerGroup* leftSide;
	SpeedControllerGroup* rightSide;
	DifferentialDrive* robotDrive;

	frc::Encoder* leftEncoder;
	frc::Encoder* rightEncoder;

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
