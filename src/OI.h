/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
//#include <AHRS.h>
#include <Joystick.h>
#include <XboxController.h>
#include <Buttons/JoystickButton.h>

class OI {
public:
	OI();
	Joystick* GetJoystick();
	Joystick* GetJoystick2();
	XboxController* GetXbox();

	Joystick* stick;
	Joystick* stick2;
	XboxController* xbox;

	//joystick
	JoystickButton* B3;
	JoystickButton* B7;//temp
	JoystickButton* B8;//temp
	JoystickButton* B9;
	JoystickButton* B10;
	JoystickButton* B11;
	JoystickButton* B12;

	//xbox
	JoystickButton* RB;//grab
	JoystickButton* LB;//release
	JoystickButton* A;//lift arm
	JoystickButton* Y;//who knows yet
	JoystickButton* RT;
	JoystickButton* B;
	JoystickButton* X;
	JoystickButton* LT;
};
