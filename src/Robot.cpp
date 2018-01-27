/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>
#include <Robot.h>

std::shared_ptr<DriveTrain> Robot::drivetrain;
std::shared_ptr<Sol> Robot::sol;
std::shared_ptr<Elevator> Robot::elevator;
std::shared_ptr<Ramp> Robot::ramp;

StartPosition left = START_LEFT;
StartPosition right = START_RIGHT;
StartPosition middle = START_MIDDLE;
void Robot::RobotInit() {
	AutoChooser.AddObject("Do Nothing", new DoNothing());
	AutoChooser.AddObject("Deliver Low", new DeliverLow());
	AutoChooser.AddObject("Cross Auto Line", new CrossAutoLine());
	ChooserPos.AddObject("Left", &left);
	ChooserPos.AddObject("Right", &right);
	ChooserPos.AddObject("Middle", &middle);
	SmartDashboard::PutData("Start Position", &chooserPos);
}

void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to
 * select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to
 * the
 * chooser code above (like the commented example) or additional
 * comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()  {
	std::string autoSelected = frc::SmartDashboard::GetString(
			"Auto Selector", "Default");
	/*if (autoSelected == "Deliver Low") {
		m_autonomousCommand = DeliverLow();
	} else if(autoSelected == "Cross Auto Line") {
		m_autonomousCommand = CrossAutoLine();
	} else{
		m_autonomousCommand = DoNothing();
	}*/

	m_autonomousCommand = AutoChooser.GetSelected();

	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Start();
	}
	StartPosition* autonomusPos = chooserPos.GetSelected();
}

void Robot::AutonomousPeriodic()  {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()  {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()  {

}


START_ROBOT_CLASS(Robot)
