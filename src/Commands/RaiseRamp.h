#ifndef RaiseRamp_H
#define RaiseRamp_H

#include "Commands/Command.h"
#include "Subsystems/Ramp.h"
#include "Robot.h"

class RaiseRamp : public Command {
public:
	RaiseRamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RaiseRamp_H
