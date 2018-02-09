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
std::string Robot::gameData;

StartPosition left = START_LEFT;
StartPosition right = START_RIGHT;
StartPosition middle = START_MIDDLE;
void Robot::RobotInit() {
	//Left Chooser
	AutoChooserLeft.AddDefault("Do Nothing", DO_NOTHING);
	AutoChooserLeft.AddObject("Cross Auto Line Left", CROSS_LINE_LEFT);
	AutoChooserLeft.AddObject("Cross Auto Line Right", CROSS_LINE_RIGHT);
	AutoChooserLeft.AddObject("Deliver Front", DELIVER_FRONT);
	AutoChooserLeft.AddObject("Deliver Side Crossing Front", DELIVER_SIDE_CROSS_FRONT);
	AutoChooserLeft.AddObject("Deliver Side Crossing Back", DELIVER_SIDE_CROSS_BACK);
	//Right Chooser
	AutoChooserRight.AddDefault("Do Nothing", DO_NOTHING);
	AutoChooserRight.AddObject("Cross Auto Line Left", CROSS_LINE_LEFT);
	AutoChooserRight.AddObject("Cross Auto Line Right", CROSS_LINE_RIGHT);
	AutoChooserRight.AddObject("Deliver Front", DELIVER_FRONT);
	AutoChooserRight.AddObject("Deliver Side Crossing Front", DELIVER_SIDE_CROSS_FRONT);
	AutoChooserRight.AddObject("Deliver Side Crossing Back", DELIVER_SIDE_CROSS_BACK);
	//Position Chooser
	ChooserPos.AddObject("Left", left);
	ChooserPos.AddObject("Right", right);
	ChooserPos.AddObject("Middle", middle);
	SmartDashboard::PutData("Start Position", &ChooserPos);
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

	std::string gameData;
			gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
			if(gameData[0] == 'L')	{
				switch (ChooserPos.GetSelected()) {
						case START_LEFT:
							if (AutoChooserLeft.GetSelected() == DO_NOTHING)
								m_autonomousCommand = new DoNothing();

							else if (AutoChooserLeft.GetSelected() == CROSS_LINE_LEFT
									||AutoChooserLeft.GetSelected() == CROSS_LINE_RIGHT)
								m_autonomousCommand = new AutoLeftToCrossLineLeft();

							else if (AutoChooserLeft.GetSelected() == DELIVER_FRONT)
								m_autonomousCommand = new AutoLeftToDeliverFrontLeft();

//							else if (AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_BACK
//									||AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_FRONT)
//								m_autonomousCommand = new AutoLeftToDeliverSideCrossInFrontLeft();

							else
								m_autonomousCommand = new DoNothing();
							break;

						case START_RIGHT:
							if (AutoChooserLeft.GetSelected() == DO_NOTHING)
								m_autonomousCommand = new DoNothing();

							else if (AutoChooserLeft.GetSelected() == CROSS_LINE_LEFT
									||AutoChooserLeft.GetSelected() == CROSS_LINE_RIGHT)
								m_autonomousCommand = new AutoRightToCrossLineRight();

							else if (AutoChooserLeft.GetSelected() == DELIVER_FRONT)
								m_autonomousCommand = new AutoRightToDeliverFrontLeft();

							else if (AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_BACK)
								m_autonomousCommand = new AutoRightToDeliverSideCrossInBackLeft();

							else if (AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_FRONT)
								m_autonomousCommand = new AutoRightToDeliverSideCrossInFrontLeft();

							else
								m_autonomousCommand = new DoNothing();
							break;
						case START_MIDDLE:
							if (AutoChooserLeft.GetSelected() == DO_NOTHING)
								m_autonomousCommand = new DoNothing();

							else if (AutoChooserLeft.GetSelected() == CROSS_LINE_LEFT)
								m_autonomousCommand = new AutoMiddleToCrossLineLeft();

							else if	(AutoChooserLeft.GetSelected() == CROSS_LINE_RIGHT)
								m_autonomousCommand = new AutoMiddleToCrossLineLeft();

							else if (AutoChooserLeft.GetSelected() == DELIVER_FRONT)
								m_autonomousCommand = new AutoMiddleToDeliverFrontLeft();

							else if (AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_BACK
								||AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_FRONT)
								m_autonomousCommand = new AutoMiddleToDeliverSideCrossInFrontLeft();

							else
								m_autonomousCommand = new DoNothing();
							break;
				}
			}
				else{
					switch (ChooserPos.GetSelected()) {
						case START_LEFT:
							if (AutoChooserLeft.GetSelected() == DO_NOTHING)
								m_autonomousCommand = new DoNothing();

//							else if (AutoChooserLeft.GetSelected() == CROSS_LINE_LEFT
//									||AutoChooserLeft.GetSelected() == CROSS_LINE_RIGHT)
//								m_autonomousCommand = new AutoLeftToCrossLineRight();

							else if (AutoChooserLeft.GetSelected() == DELIVER_FRONT)
								m_autonomousCommand = new AutoLeftToDeliverFrontRight();

							else if (AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_BACK)
								m_autonomousCommand = new AutoLeftToDeliverSideCrossInBackRight();

//							else if	(AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_FRONT)
//								m_autonomousCommand = new AutoLeftToDeliverSideCrossInFrontRight();

							else
								m_autonomousCommand = new DoNothing();
							break;

						case START_RIGHT:
							if (AutoChooserLeft.GetSelected() == DO_NOTHING)
								m_autonomousCommand = new DoNothing();

							else if (AutoChooserLeft.GetSelected() == CROSS_LINE_LEFT
									||AutoChooserLeft.GetSelected() == CROSS_LINE_RIGHT)
								m_autonomousCommand = new AutoRightToCrossLineRight();

							else if (AutoChooserLeft.GetSelected() == DELIVER_FRONT)
								m_autonomousCommand = new AutoRightToDeliverFrontLeft();

							else if (AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_BACK
									||AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_FRONT)
								m_autonomousCommand = new AutoRightToDeliverSideCrossInFrontLeft();

							else
								m_autonomousCommand = new DoNothing();
							break;
						case START_MIDDLE:
							if (AutoChooserLeft.GetSelected() == DO_NOTHING)
								m_autonomousCommand = new DoNothing();

							else if (AutoChooserLeft.GetSelected() == CROSS_LINE_LEFT)
								m_autonomousCommand = new AutoMiddleToCrossLineLeft();

							else if	(AutoChooserLeft.GetSelected() == CROSS_LINE_RIGHT)
								m_autonomousCommand = new AutoMiddleToCrossLineRight();

							else if (AutoChooserLeft.GetSelected() == DELIVER_FRONT)
								m_autonomousCommand = new AutoMiddleToDeliverFrontLeft();

							else if (AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_BACK
								||AutoChooserLeft.GetSelected() == DELIVER_SIDE_CROSS_FRONT)
								m_autonomousCommand = new AutoMiddleToDeliverSideCrossInFrontLeft();

							else
								m_autonomousCommand = new DoNothing();
							break;
				}
			//	m_autonomousCommand = AutoChooserRight.GetSelected();
			}

	/*if (autoSelected == "Deliver Low") {
		m_autonomousCommand = DeliverLow();
	} else if(autoSelected == "Cross Auto Line") {
		m_autonomousCommand = CrossAutoLine();
	} else{
		m_autonomousCommand = DoNothing();
	}*/


	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Start();
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
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()  {

}


START_ROBOT_CLASS(Robot)
