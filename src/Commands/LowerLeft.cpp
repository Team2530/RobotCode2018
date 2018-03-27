#include "LowerLeft.h"
#include "Robot.h"
#include "Subsystems/Ramp.h"


LowerLeft::LowerLeft() {
	Requires(Robot::ramp.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LowerLeft::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LowerLeft::Execute() {
	Robot::ramp->LowerLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool LowerLeft::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LowerLeft::End() {
	Robot::ramp->StopLeft();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerLeft::Interrupted() {
	Robot::ramp->StopLeft();
}
