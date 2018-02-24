#include <Commands/AutoMiddleToCrossLineLeft.h>
#include <Commands/DriveInches.h>
#include <Commands/Right.h>
#include <Commands/Left.h>

AutoMiddleToCrossLineLeft::AutoMiddleToCrossLineLeft() {
	AddSequential(new DriveInches(33));//Drives to center of area
	AddSequential(new Left(90));//Turns towards left face of field
	AddSequential(new DriveInches(66));//drive to outside of switch
	AddSequential(new DriveInches(buffer));//buffer to avoid switch
	AddSequential(new Right(90));//turn towards autoline
	AddSequential(new DriveInches(102));//drive over autoline
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
