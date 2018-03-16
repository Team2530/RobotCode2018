#ifndef LowerArm_H
#define LowerArm_H

#include "Commands/Command.h"

class LowerArm : public frc::Command {
public:
	LowerArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LowerArm_H
