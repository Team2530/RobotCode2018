#include "DropRamps.h"
#include "Robot.h"
#include "Subsystems/Ramp.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Elevator.h"

DropRamps::DropRamps() {
	Requires(Robot::ramp.get());
	Requires(Robot::drivetrain.get());
	Requires(Robot::elevator.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DropRamps::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DropRamps::Execute() {
	Robot::ramp->Release();
}

// Make this return true when this Command no longer needs to run execute()
bool DropRamps::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DropRamps::End() {
	Robot::ramp->ReleaseStop();
	Robot::drivetrain->Stop();
	Robot::elevator->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DropRamps::Interrupted() {
	Robot::ramp->ReleaseStop();
}
