#ifndef ReleaseCube_H
#define ReleaseCube_H

#include "Commands/Command.h"

class ReleaseCube : public Command {
public:
	ReleaseCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReleaseCube_H
