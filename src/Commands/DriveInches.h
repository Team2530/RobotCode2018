#ifndef DriveInches_H
#define DriveInches_H

#include "Commands/Command.h"
#include <Robot.h>
#include <Subsystems/DriveTrain.h>

class DriveInches : public Command {
public:
	DriveInches(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveInches_H
