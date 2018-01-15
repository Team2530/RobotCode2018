#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>

class DriveTrain : public Subsystem {
private:
	frc::VictorSP frontLeftMotor{1};
	frc::VictorSP frontRightMotor{0};
	frc::VictorSP backLeftMotor{2};
	frc::VictorSP backRightMotor{3};
	frc::SpeedControllerGroup leftSide{frontLeftMotor, backLeftMotor};
	frc::SpeedControllerGroup rightSide{frontRightMotor, backRightMotor};
	frc::DifferentialDrive robotDrive{leftSide, rightSide};

public:
	DriveTrain();
	void InitDefaultCommand();

	void TeleopPeriodic() {
		robotDrive.ArcadeDrive(stick.GetY(), stick.GetX());
	}
};

#endif  // DriveTrain_H
