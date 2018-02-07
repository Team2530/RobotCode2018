#ifndef GoStraight_H
#define GoStraight_H

#include <Commands/Command.h>
#include <Subsystems/DriveTrain.h>
#include <Robot.h>
#include <RobotMap.h>
#include <Joystick.h>

class GoStraight : public Command {
private:
	Joystick* stick;
public:
	GoStraight();
	GoStraight(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GoStraight_H
