#ifndef RaiseRight_H
#define RaiseRight_H

#include "Commands/Command.h"

class RaiseRight : public frc::Command {
public:
	RaiseRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RaiseRight_H
