#include <Commands/AutoRightToCrossLineRight.h>
#include <Commands/DriveInches.h>
#include <Commands/TurnDegrees.h>

AutoRightToCrossLineRight::AutoRightToCrossLineRight() {
	AddSequential(new DriveInches(40)); //drive forward
	AddSequential(new TurnDegrees(-90)); //turn right
	AddSequential(new DriveInches(33)); //go to the side
	AddSequential(new TurnDegrees(90)); //turn left
	AddSequential(new DriveInches(153)); //drive pass the auto line
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
