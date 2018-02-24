#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "Commands/Command.h"
#include <Robot.h>

class TurnDegrees : public frc::Command {
public:
	TurnDegrees(int degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int Left (int TurnDegrees);
	int Right (int TurnDegrees);
	int TurnDeg;
	int StartingAngle;
	int Fix;
	int TargetAngle;
	int NewAngle;

};
#endif  // TurnDegrees_H
