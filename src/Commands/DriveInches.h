#ifndef DriveInches_H
#define DriveInches_H

#include "Commands/Command.h"
#include <Robot.h>
#include <Subsystems/DriveTrain.h>

class DriveInches : public frc::Command {
private:
	double d;
	static constexpr double ticksPerRevolution = 1/1000;
	static constexpr double diameter = 6; //inches
	static constexpr double pi = 2*acos(0.0);
	static constexpr double maxPower = 0.6;
	static constexpr double minPower = 0.1;
public:
	DriveInches(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveInches_H
