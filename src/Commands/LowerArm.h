#ifndef LowerArm_H
#define LowerArm_H

#include "Commands/Command.h"
#include "Robot.h"

class LowerArm : public Command {
public:
	LowerArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LowerArm_H
