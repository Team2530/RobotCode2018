
#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

//Commands

#include <SmartDashboard/SendableChooser.h>
//#include <Subsystems/Sol.h>
//#include "Subsystems/DriveTrain.h"
//#include <Subsystems/Elevator.h>
//#include <Subsystems/Ramp.h>
#include <StartPositions.h>
#include <networktables/NetworkTableInstance.h>
//#include <OI.h>
//#include <Commands/TankDriveWithJoystick.h>
#include <TimedRobot.h>

//Auto Commands

class DriveTrain;
class Sol;
class Elevator;
class Ramp;
class OI;



class Robot : public frc::TimedRobot {
public:

	//Stuffffff
	static std::shared_ptr<DriveTrain> drivetrain;
	static std::shared_ptr<Sol> sol;
	static std::shared_ptr<Elevator> elevator;
	static std::shared_ptr<Ramp> ramp;
	static std::shared_ptr<OI> oi;
	static std::string gameData;

	virtual void RobotInit() override ;

	virtual void DisabledInit() override ;

	virtual void DisabledPeriodic() override ;

	virtual void AutonomousInit() override ;

	virtual void AutonomousPeriodic() override ;

	virtual void TeleopInit() override ;

	virtual void TeleopPeriodic() override ;

	virtual void TestPeriodic() override ;

	enum AutoCommand{
			DO_NOTHING,
			CROSS_LINE_LEFT,
			CROSS_LINE_RIGHT,
			DELIVER_FRONT,
			DELIVER_SIDE_CROSS_FRONT,
			DELIVER_SIDE_CROSS_BACK,
			TANK_DRIVE_WITH_JOYSTICK,
			SKID_STEAR_WITH_JOYSTICK
		};

private:

	frc::Command* m_autonomousCommand = nullptr;
	//frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<AutoCommand*> *AutoChooserLeft;
	frc::SendableChooser<AutoCommand*> *AutoChooserRight;
	frc::SendableChooser<StartPosition*> *ChooserPos;
	frc::SendableChooser<AutoCommand> *ChooserDrive;
};

#endif /* SRC_ROBOT_H_ */
