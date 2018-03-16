#ifndef GoStraight_H
#define GoStraight_H

#include <Commands/Command.h>

namespace frc {
class Joystick;
};

class GoStraight : public frc::Command {
private:
	Joystick* stick;
	double CurrentAngle;
public:
	GoStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GoStraight_H
