/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include <Commands/GoStraight.h>

OI::OI() {

	// Process operator interface input here.

	//XBOX Controller Stuff Here PLEEEEAAASE

	//OK, JOYSTICK Stuff Here Please

	//also,,,,, need drive straight button on joystick eventually
	stick = new frc::Joystick(0);
	//Need grabber sometime soon :)
	B3 = new frc::JoystickButton(stick,3);

	B3->WhileHeld(new GoStraight);
}

