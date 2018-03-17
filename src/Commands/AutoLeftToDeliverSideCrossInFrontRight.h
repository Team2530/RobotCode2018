#ifndef AutoLeftToDeliverSideCrossInFrontRight_H
#define AutoLeftToDeliverSideCrossInFrontRight_H

#include <Commands/CommandGroup.h>

class AutoLeftToDeliverSideCrossInFrontRight : public frc::CommandGroup {
private:
	double distanceCrossSwitch = 180;

public:
	AutoLeftToDeliverSideCrossInFrontRight();
};

#endif  // AutoLeftToDeliverSideCrossInFrontRight_H
