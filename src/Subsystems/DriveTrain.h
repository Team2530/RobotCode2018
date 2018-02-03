#ifndef DriveTrain_H
#define DriveTrain_H
#include <VictorSP.h>
#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <Joystick.h>
#include <ctre/Phoenix.h>
#include "HAL/HAL.h"
#include <Encoder.h>
#include <AHRS.h>


class DriveTrain : public Subsystem {
private:
	static constexpr int kFrontLeftChannel = 1;
	static constexpr int kBackLeftChannel = 2;
	static constexpr int kFrontRightChannel = 0;
	static constexpr int kBackRightChannel = 3;
	static constexpr double ticksPerRevolution = 1/1000;
	static constexpr double diameter = 6; //inches
	static constexpr double pi = 2*acos(0.0);
	AHRS* ahrs;

	WPI_TalonSRX* frontLeftController;
	WPI_VictorSPX* backLeftController;
	WPI_TalonSRX* frontRightController;
	WPI_VictorSPX* backRightController;
	SpeedControllerGroup* leftSide;
	SpeedControllerGroup* rightSide;
	DifferentialDrive* robotDrive;

	frc::Encoder* leftEncoder;
	frc::Encoder* rightEncoder;
	double leftLastMeasurement;
	double rightLastMeasurement;
	double currentPositionX; // Right
	double currentPositionY; // Forward
	double currentAngle;//angle
	double previousPositionX; // Right
	double previousPositionY; // Forward
	double previousAngle;
	double averageEncoder;
	double angleAdjustment;

public:
	std::shared_ptr<NetworkTable> table;
	DriveTrain();
	void InitDefaultCommand();
	void Drive(Joystick* stick);
	void TeleopPeriodic();
	void DriveStraight(Joystick* stick);
	void Stop();
	void StartTracking();
	double DriveFunction(double inSpeed);
	void UpdatePosition();
	void GetCurrentAngle();
};

#endif  // DriveTrain_H
