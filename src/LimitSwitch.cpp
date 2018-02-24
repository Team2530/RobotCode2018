/*
 * LimitSwitch.cpp
 *
 *  Created on: Feb 24, 2018
 *      Author: Team 2530
 */

#include <LimitSwitch.h>

LimitSwitch::LimitSwitch(int channel) : DigitalInput(channel) {

	// TODO Auto-generated constructor stub

}


	bool LimitSwitch::IsLimitReached() const{
		return !Get() ;
	}
