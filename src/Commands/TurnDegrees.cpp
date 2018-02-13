#include "TurnDegrees.h"

TurnDegrees::TurnDegrees(int degrees) {
	TurnDeg = degrees;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TurnDegrees::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDegrees::Interrupted() {

}

int Left (int TurnDegrees){
	return TurnDegrees ;
}

int Right (int TurnDegrees){
	return -TurnDegrees ;
	}
