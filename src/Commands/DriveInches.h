#ifndef DriveInches_H
#define DriveInches_H

#include "Commands/Command.h"

class DriveInches : public frc::Command {
private:
	double d;
	double target;
	double buffer=1000;//need test!!!
	double rotations;
	static constexpr double ticksPerRevolution = 8192/1;
	static constexpr double diameter = 6; //inches
	static constexpr double pi = 3.14159265358979323;//2*acos(0.0);
	double ticksPerInch = ticksPerRevolution/(pi*diameter);
	static constexpr double circumference = pi*diameter;
	static constexpr double maxPower = 0.5;
	static constexpr double minPower = 0.4;
	double CurrentAngle;
public:
	DriveInches(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveInches_H
