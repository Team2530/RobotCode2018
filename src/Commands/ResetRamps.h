#ifndef ResetRamps_H
#define ResetRamps_H

#include "Commands/Command.h"

class ResetRamps : public Command {
public:
	ResetRamps();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetRamps_H

