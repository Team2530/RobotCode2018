
#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

//Commands
#include "Commands/GoStraight.h"
#include "Commands/SkidStearWithJoystick.h"
#include <SmartDashboard/SendableChooser.h>

//Subsystems
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sol.h"

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
	frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<frc::Command*> AutoChooser;
};


#endif /* SRC_ROBOT_H_ */
