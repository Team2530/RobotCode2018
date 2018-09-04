/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TankDriveWithJoystick.h"
#include "Robot.h"
#include "Subsystems/DriveTrain.h"
#include "OI.h"

TankDriveWithJoystick::TankDriveWithJoystick() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void TankDriveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDriveWithJoystick::Execute() {
	Joystick* stick1 = Robot::oi->GetJoystick();
	Joystick* stick2 = Robot::oi->GetJoystick2();
	Robot::drivetrain->TankDrive(stick2, stick1);

}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDriveWithJoystick::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveWithJoystick::Interrupted() {
	Robot::drivetrain->Stop();
}
