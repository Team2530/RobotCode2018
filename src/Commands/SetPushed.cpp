#include "SetPushed.h"
#include "Robot.h"

SetPushed::SetPushed(bool flag) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	pushed = flag;
	Requires(Robot::elevator.get());
}

// Called just before this Command runs the first time
void SetPushed::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetPushed::Execute() {
	Robot::elevator->SetPushed(pushed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetPushed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetPushed::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetPushed::Interrupted() {

}
