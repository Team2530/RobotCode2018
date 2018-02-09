#include "AutoMiddleToDeliverSideCrossInFrontLeft.h"
#include <Commands/GoStraight.h>
#include <Commands/TurnDegrees.h>
#include <Robot.h>

AutoMiddleToDeliverSideCrossInFrontLeft::AutoMiddleToDeliverSideCrossInFrontLeft() {
	AddSequential(new GoStraight(40));
	AddSequential(new TurnDegrees(90)); //left
	AddSequential(new GoStraight(80));
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new GoStraight(128));
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new GoStraight(10)); //??????????????????
	//deliver box stuff
	AddSequential(new GoStraight(-10)); //??????????????????
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new GoStraight(30));
	AddSequential(new TurnDegrees(-90)); //right
	AddSequential(new GoStraight(36));

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
