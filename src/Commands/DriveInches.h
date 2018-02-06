#ifndef DriveInches_H
#define DriveInches_H

#include "Commands/Command.h"

class DriveInches : public Command {
public:
	DriveInches(int inches);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int DriveInch;
};

#endif  // DriveInches_H
