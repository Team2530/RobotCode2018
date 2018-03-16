#include "LowerArm.h"
#include "Robot.h"
#include "Subsystems/Elevator.h"


LowerArm::LowerArm() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::elevator.get());
}

// Called just before this Command runs the first time
void LowerArm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LowerArm::Execute() {
	Robot::elevator->Lower();
}

// Make this return true when this Command no longer needs to run execute()
bool LowerArm::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LowerArm::End() {
    Robot::elevator->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerArm::Interrupted() {
	Robot::elevator->Stop();

}
