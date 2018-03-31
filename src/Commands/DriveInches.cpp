#include "DriveInches.h"
#include <Robot.h>
#include "Subsystems/DriveTrain.h"


DriveInches::DriveInches(double distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	d = distance*ticksPerInch;//WE MUST CHECK THIS GWUYS ticks = inches*(360/circumference)
	SmartDashboard::PutNumber("starting d", d);
	SmartDashboard::PutNumber("distance", distance);
	SmartDashboard::PutNumber("TicksPerInch", ticksPerInch);
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveInches::Initialize() {
	double startingDistance = 0;// Robot::drivetrain->GetEncoderDistance();
	Robot::drivetrain->ResetEncoders();
	target = startingDistance + d;
	CurrentAngle = Robot::drivetrain->GetIdealAngle();
	//rotations = d/circumference;
	//double power;

}

// Called repeatedly when this Command is scheduled to run
void DriveInches::Execute() {


		Robot::drivetrain->DriveStraight(target, CurrentAngle); //?????????//MAY NEED TO GET RID OF POWER FUNCTION THING!!
		SmartDashboard::PutNumber("d:  ", d);
		SmartDashboard::PutNumber("target:  ", target);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveInches::IsFinished() {
	if(fabs(target-Robot::drivetrain->GetEncoderDistance())<buffer){
		SmartDashboard::PutNumber("finish", 1);
		return true;

	}
	SmartDashboard::PutNumber("finish", 0);
	return false;
}

// Called once after isFinished returns true
void DriveInches::End() {
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetPIDs();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveInches::Interrupted() {
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetPIDs();
}
