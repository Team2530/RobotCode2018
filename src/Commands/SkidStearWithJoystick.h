#ifndef SkidStearWithJoystick_H
#define SkidStearWithJoystick_H

#include "Commands/Command.h"

class SkidStearWithJoystick : public Command {
public:
	SkidStearWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SkidStearWithJoystick_H
