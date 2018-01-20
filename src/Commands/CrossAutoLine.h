#ifndef CrossAutoLine_H
#define CrossAutoLine_H

#include "Commands/Command.h"

class CrossAutoLine : public Command {
public:
	CrossAutoLine();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrossAutoLine_H
