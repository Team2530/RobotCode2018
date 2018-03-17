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
#include <Commands/AutoMain.h>
#include <Commands/SkidStearWithJoystick.h>
#include <Commands/TankDriveWithJoystick.h>

#include "Subsystems/Ramp.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Sol.h"
#include "OI.h"

std::shared_ptr<DriveTrain> Robot::drivetrain;
std::shared_ptr<Sol> Robot::sol;
std::shared_ptr<Elevator> Robot::elevator;
std::shared_ptr<Ramp> Robot::ramp;
std::shared_ptr<OI> Robot::oi;
std::string Robot::gameData;

StartPosition left = START_LEFT;
StartPosition right = START_RIGHT;
StartPosition middle = START_MIDDLE;
void Robot::RobotInit() {

	drivetrain = std::make_shared<DriveTrain>();
	sol = std::make_shared<Sol>();
	elevator = std::make_shared<Elevator>();
	ramp = std::make_shared<Ramp>();
	oi = std::make_shared<OI>();

	// Gets USB camera from CameraServer
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture("USB Camera 0", 0);
	// Sets resolution
	camera.SetResolution(320, 240);
	camera.SetExposureManual(20);
	camera.SetBrightness(100);

	//Left Chooser
	AutoChooserLeft = new frc::SendableChooser<AutoCommand>;
	AutoChooserLeft->AddDefault("Do Nothing Left", DO_NOTHING);
	AutoChooserLeft->AddObject("Auto Line Left", CROSS_LINE_LEFT);
	AutoChooserLeft->AddObject("Auto Line Right", CROSS_LINE_RIGHT);
	AutoChooserLeft->AddObject("Deliver Front", DELIVER_FRONT);
	AutoChooserLeft->AddObject("Deliver Side Cross Front", DELIVER_SIDE_CROSS_FRONT);
	AutoChooserLeft->AddObject("Deliver Side Cross Back", DELIVER_SIDE_CROSS_BACK);
	SmartDashboard::PutData("Automode Left", AutoChooserLeft);

	//Right Chooser
	AutoChooserRight = new frc::SendableChooser<AutoCommand>;
	AutoChooserRight->AddDefault("Do Nothing Right", DO_NOTHING);
	AutoChooserRight->AddObject("Auto Line Left", CROSS_LINE_LEFT);
	AutoChooserRight->AddObject("Auto Line Right", CROSS_LINE_RIGHT);
	AutoChooserRight->AddObject("Deliver Front", DELIVER_FRONT);
	AutoChooserRight->AddObject("Deliver Side Cross Front", DELIVER_SIDE_CROSS_FRONT);
	AutoChooserRight->AddObject("Deliver Side Cross Back", DELIVER_SIDE_CROSS_BACK);
	SmartDashboard::PutData("Automode Right", AutoChooserRight);

	//Position Chooser
	ChooserPos = new frc::SendableChooser<StartPosition>;
	ChooserPos->AddDefault("Left", left);
	ChooserPos->AddObject("Right", right);
	ChooserPos->AddObject("Middle", middle);
	SmartDashboard::PutData("Start Position", ChooserPos);
	//Drive Chooser
	ChooserDrive = new frc::SendableChooser<AutoCommand>;
	ChooserDrive->AddObject("TankDrive", TANK_DRIVE_WITH_JOYSTICK);
	ChooserDrive->AddObject("SkidSteer", SKID_STEAR_WITH_JOYSTICK);
	//Wait Chooser
	SmartDashboard::SetDefaultNumber("WaitTime", 0);
	// Open up a NetworkTables connection to the powerup-gss server. This will reconnect on it's own if
	// the powerup-gss server is not available. The AddLogger will remove all error messages for this NT instance,
	// so if you are experiencing difficulties making this work, comment that line out.
	// Note: This should probably be split into it's own subsystem so the code layout and function is cleaner.

	drivetrain->SetEncoderDistance(0.0);
}

void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("disabled angle", drivetrain->GetCurrentAngle());
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
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	// Return the switch & scale data pulled from the NetworkTable entry.
	//std::string gameData = GSSinst.GetTable("OffseasonFMSInfo")->GetEntry("GameData").GetString("defaultValue");

	double waitTime = SmartDashboard::GetNumber("WaitTime", 0);

	StartPosition startPos = ChooserPos->GetSelected();
	AutoCommand leftCommand = AutoChooserLeft->GetSelected();
	AutoCommand rightCommand = AutoChooserRight->GetSelected();
	drivetrain->InitIdealAngle();

	SmartDashboard::PutNumber("WaitTime:", waitTime);
	SmartDashboard::PutNumber("StartPos:", startPos);
	SmartDashboard::PutNumber("leftCommand:", leftCommand);
	SmartDashboard::PutNumber("rightCommand:", rightCommand);

	bool evade = true;
	m_autonomousCommand = new AutoMain(waitTime, gameData[0], startPos, leftCommand, rightCommand, evade);

	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand -> Start();
	}

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
	Command* dfault = new TankDriveWithJoystick();
	dfault->Start();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic(){
}



START_ROBOT_CLASS(Robot)
