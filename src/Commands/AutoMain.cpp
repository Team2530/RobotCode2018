#include "AutoMain.h"
#include <Commands/WaitCommand.h>

AutoMain::AutoMain(double t, char switchSide, StartPosition startPos,
		Robot::AutoCommand commandLeft, Robot::AutoCommand commandRight, bool Evade) {

	frc::Command* AutoCommand = nullptr;
	frc::Command* EvadeCommand = nullptr;

	if (switchSide == 'L') {
		switch (startPos) {
		case START_LEFT:
			if (commandLeft == Robot::DO_NOTHING) {
				AutoCommand = new DoNothing();

			} else if (commandLeft == Robot::CROSS_LINE_LEFT
					|| commandLeft == Robot::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoLeftToCrossLineLeft();

			} else if (commandLeft == Robot::DELIVER_FRONT) {
				AutoCommand = new AutoLeftToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand = new AutoLeftDeliverToSideLeft();
				EvadeCommand = new AutoEvadeSideLeft();

			} else {
				AutoCommand = new DoNothing();
			}
			break;


		case START_RIGHT:
			if (commandLeft == Robot::DO_NOTHING) {
				AutoCommand = new DoNothing();

			} else if (commandLeft == Robot::CROSS_LINE_LEFT
					|| commandLeft == Robot::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoRightToCrossLineRight();

			} else if (commandLeft == Robot::DELIVER_FRONT) {
				AutoCommand = new AutoRightToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK) {
				AutoCommand =
						new AutoRightToDeliverSideCrossInBackLeft();
				EvadeCommand = new AutoEvadeSideLeft();

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoRightToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else {
				AutoCommand = new DoNothing();
			}
			break;
		case START_MIDDLE:
			if (commandLeft == Robot::DO_NOTHING) {
				AutoCommand = new DoNothing();

			} else if (commandLeft == Robot::CROSS_LINE_LEFT) {
				AutoCommand = new AutoMiddleToCrossLineLeft();

			} else if (commandLeft == Robot::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoMiddleToCrossLineLeft();

			} else if (commandLeft == Robot::DELIVER_FRONT) {
				AutoCommand = new AutoMiddleToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else {
				AutoCommand = new DoNothing();
			}
			break;
		}
	} else {
		switch (startPos) {
		case START_LEFT:
			if (commandRight == Robot::DO_NOTHING) {
				AutoCommand = new DoNothing();

			} else if (commandRight == Robot::CROSS_LINE_LEFT
					|| commandRight == Robot::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoLeftToCrossLineLeft();

			} else if (commandRight == Robot::DELIVER_FRONT) {
				AutoCommand = new AutoLeftToDeliverFrontRight();
				EvadeCommand = new AutoEvadeFrontRight();

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK) {
				AutoCommand =
						new AutoLeftToDeliverSideCrossInBackRight();
				//EvadeCommand = new AutoEvadeSideRight();

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoLeftToDeliverSideCrossInFrontRight();
				EvadeCommand = new AutoEvadeFrontRight();

			} else {
				AutoCommand = new DoNothing();
			}
			break;

		case START_RIGHT:
			if (commandRight == Robot::DO_NOTHING) {
				AutoCommand = new DoNothing();

			} else if (commandRight == Robot::CROSS_LINE_LEFT
					|| commandRight == Robot::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoRightToCrossLineRight();

			} else if (commandRight == Robot::DELIVER_FRONT) {
				AutoCommand = new AutoRightToDeliverFrontRight();
				EvadeCommand = new AutoEvadeFrontRight();

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand = new AutoRightToDeliverSideRight();
				//EvadeCommand = new AutoEvadeSideRight();

			} else {
				AutoCommand = new DoNothing();
			}
			break;
		case START_MIDDLE:
			if (commandRight == Robot::DO_NOTHING) {
				AutoCommand = new DoNothing();

			} else if (commandRight == Robot::CROSS_LINE_LEFT) {
				AutoCommand = new AutoMiddleToCrossLineLeft();

			} else if (commandRight == Robot::CROSS_LINE_RIGHT) {
				AutoCommand = new AutoMiddleToCrossLineRight();

			} else if (commandRight == Robot::DELIVER_FRONT) {
				AutoCommand = new AutoMiddleToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				AutoCommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft();

			} else
				AutoCommand = new DoNothing();
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
