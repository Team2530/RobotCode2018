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
	static constexpr int kFrontLeftChannel = 4;
	static constexpr int kBackLeftChannel = 2;
	static constexpr int kFrontRightChannel = 1;
	static constexpr int kBackRightChannel = 3;
	//static constexpr double ticksPerRevolution = 1/1000;
	static constexpr double diameter = 6; //inches
	static constexpr double pi = 2*acos(0.0);
	static constexpr double minPower = 0.1;
	AHRS* ahrs;

	WPI_TalonSRX* frontLeftController;
	WPI_VictorSPX* backLeftController;
	WPI_TalonSRX* frontRightController;
	WPI_VictorSPX* backRightController;
	DifferentialDrive* robotDrive;

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

	double kTimeoutMs = 10;
	double kPIDLoopIdx=0;
	double kSlotIdk;
	//double update=0;

public:
	std::shared_ptr<NetworkTable> table;
	DriveTrain();
	void InitDefaultCommand();
	void Drive(Joystick* stick);
	void TeleopPeriodic();
	void DriveStraight(Joystick* stick, double StartingAngle);
	void DriveStraight(double rotations, double StartingAngle);
	//void DriveStraightAuto(double distance);
	void Stop();
	void Turn(double degree);
	void StartTracking(double initialX, double initialY, double initialAngle);
	double DriveFunction(double inSpeed);
	double GetEncoderDistance();
	void UpdatePosition();
	double GetCurrentAngle();
	void SetEncoderDistance(double value);
};

#endif  // DriveTrain_H
