#ifndef DeliverHigh_H
#define DeliverHigh_H

#include "Commands/Command.h"

class DeliverHigh : public Command {
public:
	DeliverHigh();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DeliverHigh_H
