#ifndef ReleaseCube_H
#define ReleaseCube_H

#include "Commands/Command.h"
#include "../Robot.h"

class ReleaseCube : public frc::Command {
public:
	ReleaseCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReleaseCube_H
