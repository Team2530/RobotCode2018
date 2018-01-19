
#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_


class Robot : public frc::TimedRobot {
public:
	void RobotInit() override ;

	void DisabledInit() override ;

	void DisabledPeriodic() override ;

	void AutonomousInit() override ;

	void AutonomousPeriodic() override ;

	void TeleopInit() override ;

	void TeleopPeriodic() override ;

	void TestPeriodic() override ;

private:
	frc::Command* m_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	frc::SendableChooser<frc::Command*> m_chooser;
};


#endif /* SRC_ROBOT_H_ */
