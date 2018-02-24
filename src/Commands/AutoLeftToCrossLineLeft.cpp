#include <Commands/AutoLeftToCrossLineLeft.h>
#include <Commands/DriveInches.h>
#include <Commands/TurnDegrees.h>

AutoLeftToCrossLineLeft::AutoLeftToCrossLineLeft() {
	AddSequential(new DriveInches(40));//drives forward so can turn
	AddSequential(new TurnDegrees(90));
	AddSequential(new DriveInches(33));//drives over to avoid switch
	AddSequential(new TurnDegrees(-90));
	AddSequential(new DriveInches(153));//drives forward to cross autoline

}
