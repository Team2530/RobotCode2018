#ifndef AutoLeftToDeliverSideCrossInFrontRight_H
#define AutoLeftToDeliverSideCrossInFrontRight_H

#include <Commands/CommandGroup.h>

class AutoLeftToDeliverSideCrossInFrontRight : public frc::CommandGroup {
private:
	double buffer = 10;
	double distanceCrossSwitch = 238.75 + buffer;
	double finalYDistance = 93;

public:
	AutoLeftToDeliverSideCrossInFrontRight();
};

#endif  // AutoLeftToDeliverSideCrossInFrontRight_H
