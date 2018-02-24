/*
 * LimitSwitch.h
 *
 *  Created on: Feb 24, 2018
 *      Author: Team 2530
 */

#ifndef SRC_LIMITSWITCH_H_
#define SRC_LIMITSWITCH_H_
#include <DigitalInput.h>

class LimitSwitch : private frc::DigitalInput{
public:
	LimitSwitch(int channel);
	bool IsLimitReached() const;
};

#endif /* SRC_LIMITSWITCH_H_ */
