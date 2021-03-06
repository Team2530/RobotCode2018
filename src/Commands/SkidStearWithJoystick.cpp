#include "SkidStearWithJoystick.h"
#include <Joystick.h>
#include <Robot.h>
#include "Subsystems/DriveTrain.h"
#include "OI.h"

SkidStearWithJoystick::SkidStearWithJoystick() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void SkidStearWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SkidStearWithJoystick::Execute() {
	Joystick* stick = Robot::oi -> GetJoystick();
	Robot::drivetrain->Drive(stick);
}

// Make this return true when this Command no longer needs to run execute()
bool SkidStearWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SkidStearWithJoystick::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SkidStearWithJoystick::Interrupted() {
	Robot::drivetrain->Stop();
}
