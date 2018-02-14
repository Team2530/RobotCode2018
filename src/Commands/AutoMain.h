#ifndef AutoMain_H
#define AutoMain_H

#include <Commands/CommandGroup.h>
#include <Robot.h>

class AutoMain : public frc::CommandGroup {
public:
	AutoMain(double t,
			char switchSide,
			StartPosition startPos,
			Robot::AutoCommand commandLeft,
			Robot::AutoCommand commandRight,
			bool Evade);
};

#endif  // AutoMain_H
