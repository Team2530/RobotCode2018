#ifndef AutoRightToDeliverSideCrossInFrontLeft_H
#define AutoRightToDeliverSideCrossInFrontLeft_H

#include <Commands/CommandGroup.h>

class AutoRightToDeliverSideCrossInFrontLeft : public frc::CommandGroup {
private:
	double buffer = 22;
	double distanceCrossSwitch = 238.75 + buffer;
	double finalYDistance = 93;
public:
	AutoRightToDeliverSideCrossInFrontLeft();
};

#endif  // AutoRightToDeliverSideCrossInFrontLeft_H
