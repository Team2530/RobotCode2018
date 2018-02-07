#ifndef AutoLeftToDeliverSideCrossInBackRight_H
#define AutoLeftToDeliverSideCrossInBackRight_H

#include <Commands/CommandGroup.h>

class AutoLeftToDeliverSideCrossInBackRight : public frc::CommandGroup {
private:
	double distancePastSwitch = 196; //14ft to center, 2ft,4in past rail
	double distancePastCube = 13;//1ft 1 in
	double buffer = 5;//extra room so not up against cubes
	double distanceBaseLinePastSwitch = distancePastSwitch+distancePastCube+buffer;
public:
	AutoLeftToDeliverSideCrossInBackRight();

};

#endif  // AutoLeftToDeliverSideCrossInBackRight_H
