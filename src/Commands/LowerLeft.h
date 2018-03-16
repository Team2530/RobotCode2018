#ifndef LowerLeft_H
#define LowerLeft_H

#include "Commands/Command.h"

class LowerLeft : public Command {
public:
	LowerLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LowerLeft_H
