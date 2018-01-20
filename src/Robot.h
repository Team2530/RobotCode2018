
#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

//Commands
#include "Commands/GoStraight.h"
#include "Commands/SkidStearWithJoystick.h"

//Subsystems
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sol.h"

class Robot : public frc::TimedRobot {
public:

	//Stuffffff
	static std::shared_ptr<DriveTrain> drivetrain;
	static std::shared_ptr<Sol> sol;

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
};


#endif /* SRC_ROBOT_H_ */
