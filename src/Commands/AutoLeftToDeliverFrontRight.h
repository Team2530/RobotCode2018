#ifndef AutoLeftToDeliverFrontRight_H
#define AutoLeftToDeliverFrontRight_H

#include <Commands/CommandGroup.h>

class AutoLeftToDeliverFrontRight : public frc::CommandGroup {
private:
	double buffer = 22;
public:
	AutoLeftToDeliverFrontRight();
};

#endif  // AutoLeftToDeliverFrontRight_H
