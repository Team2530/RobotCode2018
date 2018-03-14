#include <Commands/AutoLeftToCrossLineLeft.h>
#include <Commands/DriveInches.h>
#include <Commands/Left.h>
#include <Commands/Right.h>

AutoLeftToCrossLineLeft::AutoLeftToCrossLineLeft() {
    AddSequential(new DriveInches(40));//drives forward so can turn !!!!! 40!!!!!!!
    AddSequential(new Left(90));
    AddSequential(new DriveInches(33));//drives over to avoid switch
	AddSequential(new Right(90));
	AddSequential(new DriveInches(153));//drives forward to cross autoline

}
