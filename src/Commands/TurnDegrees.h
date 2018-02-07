#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "Commands/Command.h"
#include <Robot.h>

class TurnDegrees : public Command {
public:
	TurnDegrees(int degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int TurnDeg;
};

#endif  // TurnDegrees_H
