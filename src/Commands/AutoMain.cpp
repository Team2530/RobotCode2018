#include "AutoMain.h"
#include <Commands/WaitCommand.h>

AutoMain::AutoMain(double t, char switchSide, StartPosition startPos,
		Robot::AutoCommand commandLeft, Robot::AutoCommand commandRight, bool Evade) {

	frc::Command* Autocommand = nullptr;
	frc::Command* EvadeCommand = nullptr

	if (switchSide == 'L') {
		switch (startPos) {
		case START_LEFT:
			if (commandLeft == Robot::DO_NOTHING) {
				Autocommand = new DoNothing();

			} else if (commandLeft == Robot::CROSS_LINE_LEFT
					|| commandLeft == Robot::CROSS_LINE_RIGHT) {
				Autocommand = new AutoLeftToCrossLineLeft();

			} else if (commandLeft == Robot::DELIVER_FRONT) {
				Autocommand = new AutoLeftToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft;

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				Autocommand = new AutoLeftDeliverToSideLeft();
				EvadeCommand = new AutoEvadeSideLeft;

			} else {
				Autocommand = new DoNothing();
			}
			break;


		case START_RIGHT:
			if (commandLeft == Robot::DO_NOTHING) {
				Autocommand = new DoNothing();

			} else if (commandLeft == Robot::CROSS_LINE_LEFT
					|| commandLeft == Robot::CROSS_LINE_RIGHT) {
				Autocommand = new AutoRightToCrossLineRight();

			} else if (commandLeft == Robot::DELIVER_FRONT) {
				Autocommand = new AutoRightToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft;

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK) {
				Autocommand =
						new AutoRightToDeliverSideCrossInBackLeft();
				EvadeCommand = new AutoEvadeSideLeft;

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_FRONT) {
				Autocommand =
						new AutoRightToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft;

			} else {
				Autocommand = new DoNothing();
			}
			break;
		case START_MIDDLE:
			if (commandLeft == Robot::DO_NOTHING) {
				Autocommand = new DoNothing();

			} else if (commandLeft == Robot::CROSS_LINE_LEFT) {
				Autocommand = new AutoMiddleToCrossLineLeft();

			} else if (commandLeft == Robot::CROSS_LINE_RIGHT) {
				Autocommand = new AutoMiddleToCrossLineLeft();

			} else if (commandLeft == Robot::DELIVER_FRONT) {
				Autocommand = new AutoMiddleToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft;

			} else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				Autocommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft;

			} else {
				Autocommand = new DoNothing();
			}
			break;
		}
	} else {
		switch (startPos) {
		case START_LEFT:
			if (commandRight == Robot::DO_NOTHING) {
				Autocommand = new DoNothing();

			} else if (commandRight == Robot::CROSS_LINE_LEFT
					|| commandRight == Robot::CROSS_LINE_RIGHT) {
				Autocommand = new AutoLeftToCrossLineLeft();

			} else if (commandRight == Robot::DELIVER_FRONT) {
				Autocommand = new AutoLeftToDeliverFrontRight();
				EvadeCommand = new AutoEvadeFrontRight;

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK) {
				Autocommand =
						new AutoLeftToDeliverSideCrossInBackRight();
				EvadeCommand = new AutoEvadeSideRight;

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_FRONT) {
				Autocommand =
						new AutoLeftToDeliverSideCrossInFrontRight();
				EvadeCommand = new AutoEvadeFrontRight;

			} else {
				Autocommand = new DoNothing();
			}
			break;

		case START_RIGHT:
			if (commandRight == Robot::DO_NOTHING) {
				Autocommand = new DoNothing();

			} else if (commandRight == Robot::CROSS_LINE_LEFT
					|| commandRight == Robot::CROSS_LINE_RIGHT) {
				Autocommand = new AutoRightToCrossLineRight();

			} else if (commandRight == Robot::DELIVER_FRONT) {
				Autocommand = new AutoRightToDeliverFrontRight();
				EvadeCommand = new AutoEvadeFrontRight;

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				Autocommand = new AutoRightToDeliverSideRight();
				EvadeCommand = new AutoEvadeSideRight;

			} else {
				Autocommand = new DoNothing();
			}
			break;
		case START_MIDDLE:
			if (commandRight == Robot::DO_NOTHING) {
				Autocommand = new DoNothing();

			} else if (commandRight == Robot::CROSS_LINE_LEFT) {
				Autocommand = new AutoMiddleToCrossLineLeft();

			} else if (commandRight == Robot::CROSS_LINE_RIGHT) {
				Autocommand = new AutoMiddleToCrossLineRight();

			} else if (commandRight == Robot::DELIVER_FRONT) {
				Autocommand = new AutoMiddleToDeliverFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft;

			} else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::DELIVER_SIDE_CROSS_FRONT) {
				Autocommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();
				EvadeCommand = new AutoEvadeFrontLeft;

			} else
				Autocommand = new DoNothing();
			break;
		}

	}

	if(AutoCommand == nullptr) {
		AutoCommand = new DoNothing();
	}

	if(EvadeCommand == nullptr) {
		Evade = False;
	}

	AddSequential(new WaitCommand(t));
	AddSequential(AutoCommand);
	if (Evade) {
		AddSequetial(EvadeCommand);
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
