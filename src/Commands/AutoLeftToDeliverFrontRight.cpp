#include "AutoLeftToDeliverFrontRight.h"
#include <Commands/DriveInches.h>
#include <Commands/TurnDegrees.h>

AutoLeftToDeliverFrontRight::AutoLeftToDeliverFrontRight() {
	AddSequential(new DriveInches(40));
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new DriveInches(160));
	AddSequential(new TurnDegrees(90)); //left
	AddSequential(new DriveInches(100));
	//Drop Arm
	//raise arm if it isn't already
	//maybe move forward
	//drop box
	//maybe retract arm
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new DriveInches(36));
	AddSequential(new TurnDegrees(90)); //left
	AddSequential(new DriveInches(60));
	AddSequential(new TurnDegrees(90)); //left
	AddSequential(new DriveInches(36));

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
