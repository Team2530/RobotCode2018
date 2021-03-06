#include <Commands/AutoMiddleToCrossLineRight.h>
#include <Commands/DriveInches.h>
#include <Commands/Right.h>
#include <Commands/Left.h>

AutoMiddleToCrossLineRight::AutoMiddleToCrossLineRight() {
	AddSequential(new DriveInches(33));//Drive to middle of field
	AddSequential(new Right(90));//turn towards right switch
	AddSequential(new DriveInches(150));//drive towards right switch
	AddSequential(new Left(90));//turn towards switch
	AddSequential(new DriveInches(54));//drive to switch
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
