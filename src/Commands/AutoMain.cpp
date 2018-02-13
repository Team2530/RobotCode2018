#include "AutoMain.h"

AutoMain::AutoMain(double t, char switchSide, StartPosition startPos,
		Robot::AutoCommand commandLeft, Robot::AutoCommand commandRight) {

	frc::Command* m_autonomousCommand = nullptr;

	if (switchSide == 'L') {
		switch (startPos) {
		case START_LEFT:
			if (commandLeft == Robot::DO_NOTHING)
				m_autonomousCommand = new DoNothing();

			else if (commandLeft == Robot::CROSS_LINE_LEFT
					|| commandLeft == Robot::CROSS_LINE_RIGHT)
				m_autonomousCommand = new AutoLeftToCrossLineLeft();

			else if (commandLeft == Robot::DELIVER_FRONT)
				m_autonomousCommand = new AutoLeftToDeliverFrontLeft();

			else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::DELIVER_SIDE_CROSS_FRONT)
				m_autonomousCommand = new AutoLeftDeliverToSideLeft();

			else
				m_autonomousCommand = new DoNothing();
			break;

		case START_RIGHT:
			if (commandLeft == Robot::DO_NOTHING)
				m_autonomousCommand = new DoNothing();

			else if (commandLeft == Robot::CROSS_LINE_LEFT
					|| commandLeft == Robot::CROSS_LINE_RIGHT)
				m_autonomousCommand = new AutoRightToCrossLineRight();

			else if (commandLeft == Robot::DELIVER_FRONT)
				m_autonomousCommand = new AutoRightToDeliverFrontLeft();

			else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK)
				m_autonomousCommand =
						new AutoRightToDeliverSideCrossInBackLeft();

			else if (commandLeft == Robot::DELIVER_SIDE_CROSS_FRONT)
				m_autonomousCommand =
						new AutoRightToDeliverSideCrossInFrontLeft();

			else
				m_autonomousCommand = new DoNothing();
			break;
		case START_MIDDLE:
			if (commandLeft == Robot::DO_NOTHING)
				m_autonomousCommand = new DoNothing();

			else if (commandLeft == Robot::CROSS_LINE_LEFT)
				m_autonomousCommand = new AutoMiddleToCrossLineLeft();

			else if (commandLeft == Robot::CROSS_LINE_RIGHT)
				m_autonomousCommand = new AutoMiddleToCrossLineLeft();

			else if (commandLeft == Robot::DELIVER_FRONT)
				m_autonomousCommand = new AutoMiddleToDeliverFrontLeft();

			else if (commandLeft == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandLeft
							== Robot::DELIVER_SIDE_CROSS_FRONT)
				m_autonomousCommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();

			else
				m_autonomousCommand = new DoNothing();
			break;
		}
	} else {
		switch (startPos) {
		case START_LEFT:
			if (commandRight == Robot::DO_NOTHING)
				m_autonomousCommand = new DoNothing();

			else if (commandRight == Robot::CROSS_LINE_LEFT
					|| commandRight == Robot::CROSS_LINE_RIGHT)
				m_autonomousCommand = new AutoLeftToCrossLineLeft();

			else if (commandRight == Robot::DELIVER_FRONT)
				m_autonomousCommand = new AutoLeftToDeliverFrontRight();

			else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK)
				m_autonomousCommand =
						new AutoLeftToDeliverSideCrossInBackRight();

			else if (commandRight == Robot::DELIVER_SIDE_CROSS_FRONT)
				m_autonomousCommand =
						new AutoLeftToDeliverSideCrossInFrontRight();

			else
				m_autonomousCommand = new DoNothing();
			break;

		case START_RIGHT:
			if (commandRight == Robot::DO_NOTHING)
				m_autonomousCommand = new DoNothing();

			else if (commandRight == Robot::CROSS_LINE_LEFT
					|| commandRight == Robot::CROSS_LINE_RIGHT)
				m_autonomousCommand = new AutoRightToCrossLineRight();

			else if (commandRight == Robot::DELIVER_FRONT)
				m_autonomousCommand = new AutoRightToDeliverFrontRight();

			else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::DELIVER_SIDE_CROSS_FRONT)
				m_autonomousCommand = new AutoRightToDeliverSideRight();

			else
				m_autonomousCommand = new DoNothing();
			break;
		case START_MIDDLE:
			if (commandRight == Robot::DO_NOTHING)
				m_autonomousCommand = new DoNothing();

			else if (commandRight == Robot::CROSS_LINE_LEFT)
				m_autonomousCommand = new AutoMiddleToCrossLineLeft();

			else if (commandRight == Robot::CROSS_LINE_RIGHT)
				m_autonomousCommand = new AutoMiddleToCrossLineRight();

			else if (commandRight == Robot::DELIVER_FRONT)
				m_autonomousCommand = new AutoMiddleToDeliverFrontLeft();

			else if (commandRight == Robot::DELIVER_SIDE_CROSS_BACK
					|| commandRight
							== Robot::DELIVER_SIDE_CROSS_FRONT)
				m_autonomousCommand =
						new AutoMiddleToDeliverSideCrossInFrontLeft();

			else
				m_autonomousCommand = new DoNothing();
			break;
		}

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
