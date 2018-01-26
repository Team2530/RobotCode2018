#ifndef GoStraight_H
#define GoStraight_H

#include <Commands/Command.h>
#include <Subsystems/DriveTrain.h>
#include <Robot.h>
#include <RobotMap.h>
#include <Joystick.h>
#include <OI.cpp>

class GoStraight : public Command {
public:
	GoStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GoStraight_H
