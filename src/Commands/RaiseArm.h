#ifndef RaiseArm_H
#define RaiseArm_H

#include "Commands/Command.h"

class RaiseArm : public frc::Command {
public:
	RaiseArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RaiseArm_H
