#ifndef LowerArm_H
#define LowerArm_H

#include "Commands/Command.h"
#include "Subsystems/Elevator.h"
#include "Robot.h"

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
