#include "Ramp.h"
#include "../RobotMap.h"

Ramp::Ramp() : Subsystem("Ramp") {
	RampMotorLeft = new VictorSP(ChannelLeft);
	RampMotorRight = new VictorSP(ChannelRight);
	released=false;
}

void Ramp::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Ramp::Raise() {
	if(released){
		RampMotorLeft->Set(0.4);
		RampMotorRight->Set(0.4);
	}
}
void Ramp::Release(){
	released = true;
	//dunno how this gonna happppen
}

void Ramp::Stop() {
	RampMotorLeft->Set(0);
	RampMotorRight->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
