/*
 * GrabCube.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: Team2530
 */
#include <Commands/GrabCube.h>

GrabCube::GrabCube() {
	Requires(Robot::sol.get());
}

// Called just before this Command runs the first time
void GrabCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GrabCube::Execute() {
	//Robot::GrabCube->GrabCube();
}

// Make this return true when this Command no longer needs to run execute()
bool GrabCube::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GrabCube::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabCube::Interrupted() {

}




