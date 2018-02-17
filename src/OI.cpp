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
#include <Commands/RaiseArm.h>
#include <Commands/RaiseRamp.h>
#include <Commands/LowerArm.h>
#include <Commands/DropRamps.h>
#include <Commands/LowerRamp.h>
#include <Commands/SetPushed.h>
OI::OI() {

	// Process operator interface input here.
	bool pulse=false;
	//XBOX Controller Stuff Here PLEEEEAAASE
	xbox = new frc::XboxController(1);//is this zero? is this zero?

	RB = new frc::JoystickButton(xbox, 6);//grab cube
	LB = new frc::JoystickButton(xbox, 5);//release cube
	A = new frc::JoystickButton(xbox, 1);//raises the arm
	Y = new frc::JoystickButton(xbox, 4);//release ramp?
	LS = new frc::JoystickButton(xbox, 9);//raise ramp
	B = new frc::JoystickButton(xbox, 18);
	X = new frc::JoystickButton(xbox, 19);
	LT = new frc::JoystickButton(xbox, 3);

	RB->WhenPressed(new GrabCube());
	LB->WhenPressed(new ReleaseCube());
	A->WhenPressed(new RaiseArm());

	LS->WhenPressed(new RaiseRamp());
	Y->WhenPressed(new DropRamps());
	B->WhenPressed(new LowerArm());
	LT->WhenPressed(new LowerRamp());

	//X->WhenPressed(new ReleaseRamp());

	//OK, JOYSTICK Stuff Here Please

	//also,,,,, need drive straight button on joystick eventually
	stick = new frc::Joystick(0);
	//Need grabber sometime soon :)
	B3 = new frc::JoystickButton(stick,3);
	B7 = new frc::JoystickButton(stick, 7);


	B3->WhileHeld(new GoStraight());
	B7->WhileHeld(new SetPushed(true));
	B7->WhenReleased(new SetPushed(false));
}

