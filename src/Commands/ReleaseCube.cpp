#include <Commands/ReleaseCube.h>
#include "../Robot.h"
#include "Subsystems/Sol.h"

ReleaseCube::ReleaseCube() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::sol.get());
}

// Called just before this Command runs the first time
void ReleaseCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ReleaseCube::Execute() {
	Robot::sol->Release();
}

// Make this return true when this Command no longer needs to run execute()
bool ReleaseCube::IsFinished() {
	SmartDashboard::PutNumber("Finished : ", 0);
	return false;
}

// Called once after isFinished returns true
void ReleaseCube::End() {
	SmartDashboard::PutNumber("Finished: ", 1);
	//Robot::sol->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseCube::Interrupted() {
	//Robot::sol->Stop;
}
