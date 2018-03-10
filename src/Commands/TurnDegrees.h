#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "Commands/Command.h"
#include <Robot.h>

class TurnDegrees : public frc::Command {
private:
public:
	TurnDegrees(double degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double TurnDeg;
	double StartingAngle;
	double Fix;
	double NewAngle;

};
#endif  // TurnDegrees_H
