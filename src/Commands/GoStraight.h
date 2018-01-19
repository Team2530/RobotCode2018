#ifndef GoStraight_H
#define GoStraight_H

#include <Commands/Command.h>
#include <DriveTrain.h>
#include <Robot.h>

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
