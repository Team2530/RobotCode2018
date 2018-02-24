#include "AutoRightToDeliverSideCrossInFrontLeft.h"
#include <Robot.h>
#include <Commands/DriveInches.h>
#include <Commands/TurnDegrees.h>

AutoRightToDeliverSideCrossInFrontLeft::AutoRightToDeliverSideCrossInFrontLeft() {
	AddSequential(new DriveInches(75));//distance up before turn
	AddSequential(new TurnDegrees(90)); //turn left
	AddSequential(new DriveInches(distanceCrossSwitch));
	AddSequential(new TurnDegrees(-90)); //turn right
	AddSequential(new DriveInches(finalYDistance));
	AddSequential(new TurnDegrees(-90)); //turn right
	AddSequential(new DriveInches(buffer));
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
