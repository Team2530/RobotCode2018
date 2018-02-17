#ifndef SetPushed_H
#define SetPushed_H

#include <Commands/Command.h>

class SetPushed : public Command {
private:
	bool pushed=false;
public:
	SetPushed(bool flag);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetPushed_H
