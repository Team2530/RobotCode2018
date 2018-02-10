
#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

//Commands
#include "Commands/GoStraight.h"
#include "Commands/SkidStearWithJoystick.h"
#include "Commands/DoNothing.h"
#include <SmartDashboard/SendableChooser.h>
#include <Subsystems/Sol.h>
#include "Subsystems/DriveTrain.h"
#include <Subsystems/Elevator.h>
#include <Subsystems/Ramp.h>
#include <StartPositions.h>

//Auto Commands
#include "Commands/DoNothing.h"

#include "Commands/AutoLeftToCrossLineLeft.h"
#include "Commands/AutoLeftToDeliverFrontRight.h"
#include "Commands/AutoLeftToDeliverFrontLeft.h"
//#include "Commands/AutoLeftToDeliverSideCrossInFrontLeft.h"
//#include "Commands/AutoLeftToDeliverSideCrossInFrontRight.h"
#include "Commands/AutoLeftToDeliverSideCrossInBackRight.h"

#include "Commands/AutoMiddleToCrossLineLeft.h"
#include "Commands/AutoMiddleToCrossLineRight.h"
#include "Commands/AutoMiddleToDeliverFrontRight.h"
#include "Commands/AutoMiddleToDeliverFrontLeft.h"
#include "Commands/AutoMiddleToDeliverSideCrossInFrontLeft.h"
#include "Commands/AutoMiddleToDeliverSideCrossInFrontRight.h"

#include "Commands/AutoRightToCrossLineRight.h"
#include "Commands/AutoRightToDeliverFrontRight.h"
#include "Commands/AutoRightToDeliverFrontLeft.h"
//#include "Commands/AutoRightToDeliverSideCrossInFrontRight.h"
#include "Commands/AutoRightToDeliverSideCrossInFrontLeft.h"
#include "Commands/AutoRightToDeliverSideCrossInBackLeft.h"


#include <SmartDashboard/SendableChooser.h>


class Robot : public frc::TimedRobot {
public:

	//Stuffffff
	static std::shared_ptr<DriveTrain> drivetrain;
	static std::shared_ptr<Sol> sol;
	static std::shared_ptr<Elevator> elevator;
	static std::shared_ptr<Ramp> ramp;
	static std::string gameData;

	virtual void RobotInit() override ;

	virtual void DisabledInit() override ;

	virtual void DisabledPeriodic() override ;

	virtual void AutonomousInit() override ;

	virtual void AutonomousPeriodic() override ;

	virtual void TeleopInit() override ;

	virtual void TeleopPeriodic() override ;

	virtual void TestPeriodic() override ;

private:
	enum AutoCommand{
		DO_NOTHING,
		CROSS_LINE_LEFT,
		CROSS_LINE_RIGHT,
		DELIVER_FRONT,
		DELIVER_SIDE_CROSS_FRONT,
		DELIVER_SIDE_CROSS_BACK
	};

	frc::Command* m_autonomousCommand = nullptr;
	//frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<AutoCommand> AutoChooserLeft;
	frc::SendableChooser<AutoCommand> AutoChooserRight;
	frc::SendableChooser<StartPosition> ChooserPos;
};

#endif /* SRC_ROBOT_H_ */
