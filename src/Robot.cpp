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

#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override {
		m_chooser.AddDefault("Default Auto", &m_defaultAuto);
		m_chooser.AddObject("My Auto", &m_myAuto);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	} {
		// Wait until here to initialize systems that depend on WPILib
			//std::printf("RobotInit start in %s, line %i\n", __FILE__, __LINE__);
/**			drivetrain = std::make_shared<DriveTrain>();
			dumper = std::make_shared<Dumper>();
			intake = std::make_shared<Intake>();
			tracker = std::make_shared<Tracker>();
			led = std::make_shared<LED>();

			vision = std::make_shared<Vision>();
		    lifter = std::make_shared<Lifter>();

		    cameraservo = std::make_shared<CameraServo>();

			oi = std::make_unique<OI>();

			chooserDo.AddDefault("Cross BaseLine", new DriveToFieldPosition(new CrossBaseLineFieldPosition())); //starting action
			chooserDo.AddObject("Do Nothing", new DoNothing());//^^
			chooserDo.AddObject("Deliver Gear", new DeliverGear());
			SmartDashboard::PutData("Autonomous modes", &chooserDo);

			chooserGear.AddObject("Left Gear", &leftGear);//choose which gear to go to
			chooserGear.AddDefault("Middle Gear", &middleGear);//^^
			chooserGear.AddObject("Right Gear", &rightGear);//^^
			SmartDashboard::PutData("Choose Gear", &chooserGear);

			chooserPos.AddObject("Left", &left); //starting position
			chooserPos.AddDefault("Middle", &middle);//^^
			chooserPos.AddObject("Right", &right);//^^
			SmartDashboard::PutData("Start Position", &chooserPos);

			chooserAngle.AddDefault("Start facing forward", &start0);
			chooserAngle.AddObject("Start with taco forward", &start_90);
			SmartDashboard::PutData("Starting orientation", &chooserAngle);

			chooserBot.AddDefault("Miracle Max", &max);
			chooserBot.AddObject("Zomberdinck", &zomber);
			SmartDashboard::PutData("This Robot", &chooserBot);
	}
**/

	/**
	 * This function is called once each time the robot enters Disabled
	 * mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when
	 * the robot is disabled.
	 */
	void DisabledInit() override {}

	void DisabledPeriodic() override {
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
	void AutonomousInit() override {
		std::string autoSelected = frc::SmartDashboard::GetString(
				"Auto Selector", "Default");
		if (autoSelected == "My Auto") {
			m_autonomousCommand = &m_myAuto;
		} else {
			m_autonomousCommand = &m_defaultAuto;
		}

		m_autonomousCommand = m_chooser.GetSelected();

		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Cancel();
			m_autonomousCommand = nullptr;
		}
	}

	void TeleopPeriodic() override { frc::Scheduler::GetInstance()->Run(); }

	void TestPeriodic() override {}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	frc::SendableChooser<frc::Command*> m_chooser;
};

START_ROBOT_CLASS(Robot)
