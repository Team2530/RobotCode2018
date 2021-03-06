#ifndef RaiseLeft_H
#define RaiseLeft_H

#include "Commands/Command.h"

class RaiseLeft : public frc::Command {
public:
	RaiseLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RaiseLeft_H
