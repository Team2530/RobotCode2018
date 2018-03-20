#include "TurnDegrees.h"
#include <Robot.h>
#include "Subsystems/DriveTrain.h"

TurnDegrees::TurnDegrees(double degrees) {
	TurnDeg = degrees;

	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize() {
	StartingAngle = Robot::drivetrain->GetIdealAngle();
	SmartDashboard::PutNumber("start: ", StartingAngle);
	Robot::drivetrain->AddToIdealAngle(TurnDeg);
	SmartDashboard::PutNumber("target:  ", Robot::drivetrain->GetIdealAngle());
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
	NewAngle = Robot::drivetrain->GetCurrentAngle();
	SmartDashboard::PutNumber("angle:  ", NewAngle);
	Fix = .015*Robot::drivetrain->ModAngle(Robot::drivetrain->GetIdealAngle()-NewAngle);
	SmartDashboard::PutNumber("Fix: ", Fix);
	double constexpr maxPow=.9;
	double constexpr minPowLeft=.6;
	double constexpr minPowRight=.5;
	if(Fix<0){
		if(Fix<-maxPow)
			Fix=-maxPow;
		if(Fix>-minPowRight)
			Fix=-minPowRight;
	}
	else{
		if(Fix>maxPow)
			Fix=maxPow;
		if(Fix<minPowLeft)
			Fix=minPowLeft;
	}


	Robot::drivetrain->Turn(Fix);

}
// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished() {

	if(fabs(Robot::drivetrain->ModAngle(Robot::drivetrain->GetIdealAngle()-NewAngle))<3){
		SmartDashboard::PutNumber("turn finished", 1);
		return true;
	}
	else{
		SmartDashboard::PutNumber("turn finished", 0);
		return false;
	}
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
	Robot::drivetrain->ResetPIDs();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDegrees::Interrupted() {
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetPIDs();
}


