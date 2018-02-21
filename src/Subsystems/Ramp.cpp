#include "Ramp.h"
#include "../RobotMap.h"

Ramp::Ramp() : Subsystem("Ramp") {
	RampMotorLeft = new VictorSP(ChannelLeft);
	RampMotorRight = new VictorSP(ChannelRight);
	RampMotorMid = new VictorSP(ChannelMid);
	//RampLeft = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//8,9 fillers
	//RampRight = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );
	TopLimitSwitchLeft = new frc::DigitalInput(6);
	TopLimitSwitchRight = new frc::DigitalInput(8);
	BottomLimitSwitchLeft = new frc::DigitalInput(7);
	BottomLimitSwitchRight = new frc::DigitalInput(9);
	released=false;
	timeInSec = 0;
}

void Ramp::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Ramp::Raise() {
	if(released){
		/*if(RampLeft->GetDistance() < RampRight->GetDistance()){
			LeftPow=1;
			if(RightPow!=.4){
				RightPow=.4;
			}
			else{
				RightPow-=.1;
			}
		}
		else if(RampRight->GetDistance() < RampLeft->GetDistance()){
			RightPow=1;
			if(LeftPow!=.4){
							LeftPow=.4;
						}
						else{
							LeftPow-=.1;
						}
		}*/
		timeInSec = timeInSec + 0.005;

		if(timeInSec == 3) {
			LeftPow = 0.7;
			RightPow = 0.7;
		} else if(timeInSec == 7) {
			LeftPow = 1;
			RightPow = 1;
			}
		if(TopLimitSwitchLeft->Get() && TopLimitSwitchRight->Get()){
			RampMotorLeft->Set(LeftPow);
			RampMotorRight->Set(RightPow);
		}
		else{
			Stop();
		}



	}
}
void Ramp::RaiseLeft() {
	if(released){
		LeftPow=0.4;
		if(TopLimitSwitchLeft->Get())
			RampMotorLeft->Set(LeftPow);
		else
			Stop();
	}
}
void Ramp::RaiseRight() {
	if(released){
		RightPow=0.4;
		if(TopLimitSwitchRight->Get())
			RampMotorRight->Set(RightPow);
		else
			Stop();
	}
}
void Ramp::Lower() {
	LeftPow=.4;
	RightPow=.4;
	if(BottomLimitSwitchLeft->Get() && BottomLimitSwitchRight->Get()){
		RampMotorLeft->Set(-LeftPow);
		RampMotorRight->Set(-RightPow);
	}
	else{
		Stop();
	}
}
void Ramp::LowerLeft() {
	if(BottomLimitSwitchLeft->Get())
		RampMotorLeft->Set(LowerLeftPow);
	else
		Stop();

}
void Ramp::LowerRight() {
	if(BottomLimitSwitchRight->Get())
		RampMotorRight->Set(LowerRightPow);
	else
		Stop();
}
void Ramp::Release(){
	RampMotorMid->Set(MidReleasePow);
	released = true;
	//dunno how this gonna happppen
}
void Ramp::Reset(){
	RampMotorMid->Set(-MidReleasePow);
	released=false;
}

void Ramp::Stop() {
	RampMotorLeft->Set(0);
	RampMotorRight->Set(0);
}

void Ramp::ReleaseStop() {
	RampMotorMid->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
