#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "Commands/Command.h"

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
int Left (int TurnDegrees);
int Right (int TurnDegrees);
#endif  // TurnDegrees_H
