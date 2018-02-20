#ifndef LowerRight_H
#define LowerRight_H

#include "Commands/Command.h"
#include "Subsystems/Ramp.h"
#include "Robot.h"

class LowerRight : public Command{
public:
	LowerRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LowerRight_H
