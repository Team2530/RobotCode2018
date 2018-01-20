
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

	//Stuffffff
	static std::shared_ptr<DriveTrain> drivetrain;
	static std::shared_ptr<Sol> sol;

	virtual void RobotInit() override ;

	virtual void DisabledInit() override ;

	virtual void DisabledPeriodic() override ;

	virtual void AutonomousInit() override ;

	virtual void AutonomousPeriodic() override ;

	virtual void TeleopInit() override ;

	virtual void TeleopPeriodic() override ;

	virtual void TestPeriodic() override ;

private:
	frc::Command* m_autonomousCommand = nullptr;
	frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<frc::Command*> AutoChooser;
};


#endif /* SRC_ROBOT_H_ */
