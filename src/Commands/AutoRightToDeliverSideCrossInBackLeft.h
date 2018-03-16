#ifndef AutoRightToDeliverSideCrossInBackLeft_H
#define AutoRightToDeliverSideCrossInBackLeft_H

#include <Commands/CommandGroup.h>


class AutoRightToDeliverSideCrossInBackLeft : public frc::CommandGroup {
private:
	double distancePastSwitch = 196; //14ft to center, 2ft,4in past rail
	double distancePastCube = 13;//1ft 1 in
	double distanceToCenterSwitchFromCube = 28;//4ft 8 inches is all, so middle is 2ft 4 inches
	double bufferY = 5;//extra room so not up against cubes
	double bufferX = 5;
	double distanceBaseLinePastSwitch = distancePastSwitch+distancePastCube+bufferY;
	double distancePassSwitchLongWay=153 + bufferX;//12 ft 9.5inch + buffer
	double distanceLineUpSwitch = distancePastCube+distanceToCenterSwitchFromCube + bufferY;
	double distanceFinalToSwitch = bufferX;
public:
	AutoRightToDeliverSideCrossInBackLeft();
};

#endif  // AutoRightToDeliverSideCrossInBackLeft_H
