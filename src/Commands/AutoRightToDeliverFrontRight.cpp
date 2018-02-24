#include <Commands/AutoRightToDeliverFrontRight.h>
#include <Commands/DriveInches.h>
#include <Commands/Left.h>
#include <Commands/Right.h>

AutoRightToDeliverFrontRight::AutoRightToDeliverFrontRight() {
	AddSequential(new DriveInches(135)); //goes towards switch
	AddSequential(new Left(90));
	AddSequential(new DriveInches(23)); //drive to switch
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
