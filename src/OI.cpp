/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include <Commands/GoStraight.h>
#include <Commands/GrabCube.h>
#include <Commands/ReleaseCube.h>

OI::OI() {

	// Process operator interface input here.

	//XBOX Controller Stuff Here PLEEEEAAASE
	xbox = new frc::XboxController(1);//is this zero? is this zero?

	R2 = new frc::JoystickButton(xbox, 12);
	L2 = new frc::JoystickButton(xbox, 6);

	R2->WhenPressed(new GrabCube());

	//OK, JOYSTICK Stuff Here Please

	//also,,,,, need drive straight button on joystick eventually
	stick = new frc::Joystick(0);
	//Need grabber sometime soon :)
	B3 = new frc::JoystickButton(stick,3);


	B3->WhileHeld(new GoStraight());
}

