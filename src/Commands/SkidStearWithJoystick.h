#ifndef SkidStearWithJoystick_H
#define SkidStearWithJoystick_H

#include "Commands/Command.h"
#include <Subsystems/DriveTrain.h>
#include <Robot.h>

class SkidStearWithJoystick : public frc::Command {
public:
	SkidStearWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SkidStearWithJoystick_H
