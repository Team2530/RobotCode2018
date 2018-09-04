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
	xbox = new frc::XboxController(1);//is this zero? is this zero? yes, this is zero

	A = new frc::JoystickButton(xbox, 1);//raises the arm
	B = new frc::JoystickButton(xbox, 2);//lower the arm
	X = new frc::JoystickButton(xbox, 3);//lower ramp
	Y = new frc::JoystickButton(xbox, 4);//raise ramp
	LB = new frc::JoystickButton(xbox, 5);//grab cube
	RB = new frc::JoystickButton(xbox, 6);//release cube

	//LT = new frc::JoystickButton(xbox, 11); not using so why declare
	//RT = new frc::JoystickButton(xbox, 12); not using so why declare

	RB->WhenPressed(new GrabCube());
	LB->WhenPressed(new ReleaseCube());

	A->WhileHeld(new RaiseArm());
	B->WhileHeld(new LowerArm());

	Y->WhileHeld(new RaiseRamp());
	X->WhileHeld(new LowerRamp());

	//OK, JOYSTICK Stuff Here Please

	stick = new frc::Joystick(2);
	stick2 = new frc::Joystick(3);
	//Need grabber sometime soon :)
	B3 = new frc::JoystickButton(stick, 3);//
	B6 = new frc::JoystickButton(stick, 6);
	B7 = new frc::JoystickButton(stick, 7);
	B8 = new frc::JoystickButton(stick, 8);
	B9 = new frc::JoystickButton(stick, 9);
	B10 = new frc::JoystickButton(stick, 10);
	B11 = new frc::JoystickButton(stick, 11);
	//B12 = new frc::JoystickButton(stick, 12);
	/*old buttons
	B3->WhileHeld(new GoStraight());//need this

	B7->WhenPressed(new LowerRight());//testing only
	B8->WhenPressed(new LowerLeft());//testing only

	B9->WhileHeld(new RaiseRight());//might need this
	B10->WhileHeld(new RaiseLeft());//might need this

	B11->WhileHeld(new ResetRamps());//need this
	B12->WhileHeld(new DropRamps());//need this
	*/

	//*new buttons
	B3->WhileHeld(new GoStraight());

	B6->WhileHeld(new RaiseLeft());
	B7->WhileHeld(new LowerLeft());

	B8->WhileHeld(new DropRamps());
	B9->WhileHeld(new ResetRamps());

	B10->WhileHeld(new LowerRight());
	B11->WhileHeld(new RaiseRight());
	//*/ <- for if we want to commenct out new buttons and go back to old
}

Joystick* OI::GetJoystick() {

	return stick;

}
Joystick* OI::GetJoystick2(){
	return stick2;
}
