#ifndef DeliverLow_H
#define DeliverLow_H

#include "Commands/Command.h"

class DeliverLow : public Command {
public:
	DeliverLow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DeliverLow_H
