#ifndef LowerRamp_H
#define LowerRamp_H

#include "Commands/CommandGroup.h"
#include "Subsystems/Ramp.h"
#include "Robot.h"

class LowerRamp : public Command {
public:
	LowerRamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LowerRamp_H
