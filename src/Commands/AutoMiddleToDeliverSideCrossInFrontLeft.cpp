#include "AutoMiddleToDeliverSideCrossInFrontLeft.h"
#include <Commands/DriveInches.h>
#include <Commands/TurnDegrees.h>
#include <Robot.h>

AutoMiddleToDeliverSideCrossInFrontLeft::AutoMiddleToDeliverSideCrossInFrontLeft() {
	AddSequential(new DriveInches(40)); //drive into area
	AddSequential(new TurnDegrees(90)); //left towards deliver side
	AddSequential(new DriveInches(80)); //drive towards front
	AddSequential(new TurnDegrees(-90)); //right to deliver
	AddSequential(new DriveInches(128)); //drive into switch
	AddSequential(new TurnDegrees(-90)); //right to switch
	//deliver box stuff
	/*Again i put evade in here lel
	AddSequential(new DriveInches(-10)); //??????????????????
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new DriveInches(30));
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new DriveInches(36));*/

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
