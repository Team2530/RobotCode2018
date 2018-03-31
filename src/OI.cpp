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
#include <Commands/RaiseRight.h>
#include <Commands/RaiseLeft.h>
#include <Commands/LowerArm.h>
#include <Commands/DropRamps.h>
#include <Commands/LowerRamp.h>
#include <Commands/LowerLeft.h>
#include <Commands/LowerRight.h>
#include <Commands/ResetRamps.h>

OI::OI() {

	// Process operator interface input here.
	//bool pulse=false;
	//XBOX Controller Stuff Here PLEEEEAAASE
	xbox = new frc::XboxController(0);//is this zero? is this zero?

	A = new frc::JoystickButton(xbox, 1);//raises the arm
	B = new frc::JoystickButton(xbox, 2);
	X = new frc::JoystickButton(xbox, 3);
	Y = new frc::JoystickButton(xbox, 4);//release ramp?
	LB = new frc::JoystickButton(xbox, 5);//release cube
	RB = new frc::JoystickButton(xbox, 6);//grab cube

	LT = new frc::JoystickButton(xbox, 11);
	RT = new frc::JoystickButton(xbox, 12);//raise ramp

	LB->WhenPressed(new GrabCube());
	RB->WhenPressed(new ReleaseCube());

	A->WhileHeld(new RaiseArm());
	B->WhileHeld(new LowerArm());



	Y->WhileHeld(new RaiseRamp());
	X->WhileHeld(new LowerRamp());

	//X->WhenPressed(new ReleaseRamp());

	//OK, JOYSTICK Stuff Here Please

	//also,,,,, need drive straight button on joystick eventually
	stick = new frc::Joystick(1);
	stick2 = new frc::Joystick(2);
	//Need grabber sometime soon :)
	B3 = new frc::JoystickButton(stick, 3);
	B7 = new frc::JoystickButton(stick, 7);
	B8 = new frc::JoystickButton(stick, 8);
	B9 = new frc::JoystickButton(stick, 9);
	B10 = new frc::JoystickButton(stick, 10);
	B11 = new frc::JoystickButton(stick, 11);
	B12 = new frc::JoystickButton(stick, 12);


	B3->WhileHeld(new GoStraight());

	B9->WhileHeld(new RaiseRight());
	B10->WhileHeld(new RaiseLeft());

	B12->WhileHeld(new DropRamps());
	B11->WhileHeld(new ResetRamps());

	B8->WhileHeld(new LowerLeft());//temp
	B7->WhileHeld(new LowerRight());//temp
}

Joystick* OI::GetJoystick() {

	return stick;

}
Joystick* OI::GetJoystick2(){
	return stick2;
}
