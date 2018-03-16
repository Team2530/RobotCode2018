#include "RaiseArm.h"
#include "Robot.h"
#include "Subsystems/Elevator.h"

RaiseArm::RaiseArm() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::elevator.get());
}

// Called just before this Command runs the first time
void RaiseArm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RaiseArm::Execute() {
		Robot::elevator->Raise();
	}

// Make this return true when this Command no longer needs to run execute()
bool RaiseArm::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RaiseArm::End() {
	Robot::elevator->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseArm::Interrupted() {
	Robot::elevator->Stop();

}
