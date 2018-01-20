/*
 * SMOL.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: akeaa
 */
#include "SMOL.h"

SMOL::SMOL() {
	Requires(Robot::sol.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SMOL::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SMOL::Execute() {
	//Robot::smol->SMOL();
}

// Make this return true when this Command no longer needs to run execute()
bool SMOL::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SMOL::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SMOL::Interrupted() {

}




