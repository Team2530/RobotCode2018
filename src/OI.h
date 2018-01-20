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
	XboxController* GetXbox();

	Joystick* stick;
	XboxController* xbox;

	JoystickButton* B3;
	JoystickButton* R2;
	JoystickButton* L2;
};
