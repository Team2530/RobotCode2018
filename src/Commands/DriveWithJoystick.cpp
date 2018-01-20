#include "DriveWithJoystick.h"

#include "Subsystems/DriveTrain.h"

DriveWithJoystick::DriveWithJoystick() : Command("DriveWithJoystick") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	Robot::drivetrain->Drive(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
	Robot::drivetrain->Stop();
}
