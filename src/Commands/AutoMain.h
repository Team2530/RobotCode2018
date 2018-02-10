#ifndef AutoMain_H
#define AutoMain_H

#include <Commands/CommandGroup.h>
#include <Robot.h>

class AutoMain : public CommandGroup {
public:
	AutoMain(double t,
			char switchSide,
			StartPosition startPos,
			Robot::AutoCommand commandLeft,
			Robot::AutoCommand commandRight);
};

#endif  // AutoMain_H
