#include <Commands/AutoMiddleToDeliverFrontRight.h>
#include <Commands/DriveInches.h>
#include <Commands/TurnDegrees.h>

AutoMiddleToDeliverFrontRight::AutoMiddleToDeliverFrontRight() {
	AddSequential(new DriveInches(65));//drive into middle of area
	AddSequential(new TurnDegrees(-90));//turn right towards right switch
	AddSequential(new DriveInches(126));//drive towards right switch
	AddSequential(new DriveInches(buffer));//buffer for turn radius
	AddSequential(new TurnDegrees(90));//turn to face switch
	AddSequential(new DriveInches(75));//drive towards switch
	AddSequential(new TurnDegrees(90));//turn into switch
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
