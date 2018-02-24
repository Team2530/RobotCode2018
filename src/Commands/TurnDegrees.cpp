#include "TurnDegrees.h"

TurnDegrees::TurnDegrees(int degrees) {
	TurnDeg = degrees;
	StartingAngle = Robot::drivetrain->GetCurrentAngle();
	NewAngle = Robot::drivetrain->GetCurrentAngle();
	TargetAngle = TurnDeg + StartingAngle;
	Fix = 0.25;

	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
		if (NewAngle > TargetAngle)
			Fix = -0.25;
		if (NewAngle < 	TargetAngle)
			Fix = 0.25;
	Robot::drivetrain->Turn(Fix);

}
// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished() {

	if (NewAngle >= TargetAngle + 1)
		return false;
	if (NewAngle <= TargetAngle - 1)
		return false;
	else
		return true;

	}


// Called once after isFinished returns true
void TurnDegrees::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDegrees::Interrupted() {
	Robot::drivetrain->Stop();
}

int TurnDegrees::Left (int TurnDegrees){
	return TurnDegrees ;
}

int TurnDegrees::Right (int TurnDegrees){
	return -TurnDegrees ;
	}
