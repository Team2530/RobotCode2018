#include "AutoMain.h"
#include <Commands/WaitCommand.h>
#include <Commands/AutoDeliverCube.h>
#include "Commands/GoStraight.h"
#include "Commands/SkidStearWithJoystick.h"
#include "Commands/DoNothing.h"

#include "Commands/AutoLeftToCrossLineLeft.h"
#include "Commands/AutoLeftToDeliverFrontRight.h"
#include "Commands/AutoLeftToDeliverFrontLeft.h"
#include "Commands/AutoLeftDeliverToSideLeft.h"
#include "Commands/AutoLeftToDeliverSideCrossInFrontRight.h"
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
#include "Commands/AutoRightToDeliverSideRight.h"
#include "Commands/AutoRightToDeliverSideCrossInFrontLeft.h"
#include "Commands/AutoRightToDeliverSideCrossInBackLeft.h"

#include "Commands/AutoEvadeSideLeft.h"
#include "Commands/AutoEvadeSideRight.h"
#include "Commands/AutoEvadeFrontLeft.h"
#include "Commands/AutoEvadeFrontRight.h"

AutoMain::AutoMain(double t, char switchSide, StartPosition startPos,
		Robot::AutoCommand commandLeft, Robot::AutoCommand commandRight, bool Evade) {

	bool Deliver = true;

	frc::Command* AutoCommand = nullptr;
	frc::Command* EvadeCommand = nullptr;

	if (switchSide == 'L') {
		switch (startPos) {
		case START_LEFT:
			if (commandLeft == Robot::AutoCommand::DO_NOTHING) {
				AutoCommand = new DoNothing();
				Deliver = false;

			} else if (commandLeft == Robot::AutoCommand::CROSS_LINE_LEFT
					|| commandLeft == Robot::AutoCommand::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoLeftToCrossLineLeft();
				Deliver = false;

			} else if (commandLeft == Robot::AutoCommand::DELIVER_FRONT) {
				AutoCommand = new AutoLeftToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandLeft == Robot::AutoCommand::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::AutoCommand::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand = new AutoLeftDeliverToSideLeft();
				EvadeCommand = new AutoEvadeSideLeft();

			} else {
				AutoCommand = new DoNothing();
				Deliver = false;
			}
			break;


		case START_RIGHT:
			if (commandLeft == Robot::AutoCommand::DO_NOTHING) {
				AutoCommand = new DoNothing();
				Deliver = false;

			} else if (commandLeft == Robot::AutoCommand::CROSS_LINE_LEFT
					|| commandLeft == Robot::AutoCommand::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoRightToCrossLineRight();
				Deliver = false;

			} else if (commandLeft == Robot::AutoCommand::DELIVER_FRONT) {
				AutoCommand = new AutoRightToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandLeft == Robot::AutoCommand::DELIVER_SIDE_CROSS_BACK) {
				AutoCommand =
						new AutoRightToDeliverSideCrossInBackLeft();
				EvadeCommand = new AutoEvadeSideLeft();

			} else if (commandLeft == Robot::AutoCommand::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoRightToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else {
				AutoCommand = new DoNothing();
				Deliver = false;
			}
			break;
		case START_MIDDLE:
			if (commandLeft == Robot::AutoCommand::DO_NOTHING) {
				AutoCommand = new DoNothing();
				Deliver = false;

			} else if (commandLeft == Robot::AutoCommand::CROSS_LINE_LEFT) {
				AutoCommand = new AutoMiddleToCrossLineLeft();
				Deliver = false;

			} else if (commandLeft == Robot::AutoCommand::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoMiddleToCrossLineLeft();
				Deliver = false;

			} else if (commandLeft == Robot::AutoCommand::DELIVER_FRONT) {
				AutoCommand = new AutoMiddleToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandLeft == Robot::AutoCommand::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::AutoCommand::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else {
				AutoCommand = new DoNothing();
				Deliver = false;
			}
			break;
		}
	} else {
		switch (startPos) {
		case START_LEFT:
			if (commandRight == Robot::AutoCommand::DO_NOTHING) {
				AutoCommand = new DoNothing();
				Deliver = false;

			} else if (commandRight == Robot::AutoCommand::CROSS_LINE_LEFT
					|| commandRight == Robot::AutoCommand::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoLeftToCrossLineLeft();
				Deliver = false;

			} else if (commandRight == Robot::AutoCommand::DELIVER_FRONT) {
				AutoCommand = new AutoLeftToDeliverFrontRight();
				EvadeCommand = new AutoEvadeFrontRight();

			} else if (commandRight == Robot::AutoCommand::DELIVER_SIDE_CROSS_BACK) {
				AutoCommand =
						new AutoLeftToDeliverSideCrossInBackRight();
				//EvadeCommand = new AutoEvadeSideRight();

			} else if (commandRight == Robot::AutoCommand::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoLeftToDeliverSideCrossInFrontRight();
				EvadeCommand = new AutoEvadeFrontRight();

			} else {
				AutoCommand = new DoNothing();
				Deliver = false;
			}
			break;

		case START_RIGHT:
			if (commandRight == Robot::AutoCommand::DO_NOTHING) {
				AutoCommand = new DoNothing();
				Deliver = false;

			} else if (commandRight == Robot::AutoCommand::CROSS_LINE_LEFT
					|| commandRight == Robot::AutoCommand::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoRightToCrossLineRight();
				Deliver = false;

			} else if (commandRight == Robot::AutoCommand::DELIVER_FRONT) {
				AutoCommand = new AutoRightToDeliverFrontRight();
				EvadeCommand = new AutoEvadeFrontRight();

			} else if (commandRight == Robot::AutoCommand::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::AutoCommand::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand = new AutoRightToDeliverSideRight();
				//EvadeCommand = new AutoEvadeSideRight();

			} else {
				AutoCommand = new DoNothing();
				Deliver = false;
			}
			break;
		case START_MIDDLE:
			if (commandRight == Robot::AutoCommand::DO_NOTHING) {
				AutoCommand = new DoNothing();
				Deliver = false;

			} else if (commandRight == Robot::AutoCommand::CROSS_LINE_LEFT) {
				AutoCommand = new AutoMiddleToCrossLineLeft();
				Deliver = false;

			} else if (commandRight == Robot::AutoCommand::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoMiddleToCrossLineRight();
				Deliver = false;

			} else if (commandRight == Robot::AutoCommand::DELIVER_FRONT) {
				AutoCommand = new AutoMiddleToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandRight == Robot::AutoCommand::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::AutoCommand::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else
				AutoCommand = new DoNothing();
				Deliver = false;
			break;
		}

	}

	if (AutoCommand == nullptr) {
		AutoCommand = new DoNothing();
	}

	if (EvadeCommand == nullptr) {
		Evade = false;
	}

	AddSequential(new WaitCommand(t));
	AddSequential(AutoCommand);
	if (Deliver){
		AddSequential(new AutoDeliverCube());
		}
	if (Evade) {
		AddSequential(EvadeCommand);
	}

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
