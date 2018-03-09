#ifndef GoStraight_H
#define GoStraight_H

#include <Commands/Command.h>
#include <Subsystems/DriveTrain.h>
#include <Robot.h>
#include <RobotMap.h>
#include <Joystick.h>

class GoStraight : public frc::Command {
private:
	Joystick* stick;
	double CurrentAngle;
public:
	GoStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GoStraight_H
