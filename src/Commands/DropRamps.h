#ifndef DropRamps_H
#define DropRamps_H

#include "Commands/Command.h"
#include "Robot.h"

class DropRamps : public Command {
public:
	DropRamps();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DropRamps_H
