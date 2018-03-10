#include "TurnDegrees.h"

TurnDegrees::TurnDegrees(int degrees) {
	TurnDeg = degrees;

	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize() {
	StartingAngle = Robot::drivetrain->GetIdealAngle();
	Robot::drivetrain->AddToIdealAngle(TurnDeg);
	SmartDashboard::PutNumber("target:  ", Robot::drivetrain->GetIdealAngle());
	SmartDashboard::PutNumber("start: ", StartingAngle);
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
	NewAngle = Robot::drivetrain->GetCurrentAngle();
	SmartDashboard::PutNumber("angle:  ", NewAngle);
	Fix = .1*Robot::drivetrain->ModAngle(Robot::drivetrain->GetIdealAngle()-NewAngle);

	Robot::drivetrain->Turn(Fix);

}
// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished() {

	if(abs(Robot::drivetrain->ModAngle(Robot::drivetrain->GetIdealAngle()-NewAngle))<1)
		return true;
	else
		return false;

	/*if (NewAngle >= TargetAngle + 5)
		return false;
	if (NewAngle <= TargetAngle - 5)
		return false;
	else
		return true;8?*/

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


