#include "AutoMiddleToDeliverSideCrossInFrontRight.h"
#include <Commands/DriveInches.h>
#include <Commands/Right.h>
#include <Commands/Left.h>

AutoMiddleToDeliverSideCrossInFrontRight::AutoMiddleToDeliverSideCrossInFrontRight() {
	AddSequential(new DriveInches(33));//drive into mid field
	AddSequential(new Right(90));//turn right towards side of switch
	AddSequential(new DriveInches(144));//drive towards side of switch
	AddSequential(new DriveInches(buffer));//buffer to account for turn radius
	AddSequential(new Left(90));//turn left to face side of switch
	AddSequential(new DriveInches(102));//drive to side of switch
	AddSequential(new Left(90));//turn to face side of switch
	AddSequential(new DriveInches(buffer));// Add Commands here:
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
