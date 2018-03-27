#include "Ramp.h"


Ramp::Ramp() : Subsystem("Ramp") {
	RampMotorLeft = new VictorSP(ChannelLeft);
	RampMotorRight = new VictorSP(ChannelRight);
	RampMotorMid = new VictorSP(ChannelMid);
	//RampLeft = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//8,9 fillers
	//RampRight = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );
	TopLimitSwitchLeft = new LimitSwitch(6);
	TopLimitSwitchRight = new LimitSwitch(8);
	BottomLimitSwitchLeft = new LimitSwitch(7);
	BottomLimitSwitchRight = new LimitSwitch(9);
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

		//if(timeInSec == 3) {
			//LeftPow = 0.7;
			//RightPow = 0.7;
		//} else if(timeInSec == 7) {
			//LeftPow = 1;
			//RightPow = 1;
			}
		if(!TopLimitSwitchLeft->IsLimitReached() && !TopLimitSwitchRight->IsLimitReached()){
			RampMotorLeft->Set(LeftPow);
			RampMotorRight->Set(RightPow);
		}
		else{
			Stop();
		}



	//}
}
void Ramp::RaiseLeft() {
	if(released){
		LeftPow=1;
		if(!TopLimitSwitchLeft->IsLimitReached())
			RampMotorLeft->Set(LeftPow);
		else
			Stop();
	}
}
void Ramp::RaiseRight() {
	if(released){
		RightPow=1;
		if(!TopLimitSwitchRight->IsLimitReached())
			RampMotorRight->Set(RightPow);
		else
			Stop();
	}
}
void Ramp::Lower() {
	LeftPow=.4;
	RightPow=.4;
	if(!BottomLimitSwitchLeft->IsLimitReached() && !BottomLimitSwitchRight->IsLimitReached()){
		RampMotorLeft->Set(-LeftPow);
		RampMotorRight->Set(-RightPow);
	}
	else{
		Stop();
	}
}
void Ramp::LowerLeft() {
	if(!BottomLimitSwitchLeft->IsLimitReached())
		RampMotorLeft->Set(LowerLeftPow);
	else
		StopRight();

}
void Ramp::LowerRight() {
			RightPow=0.4;
			if(!BottomLimitSwitchRight->IsLimitReached())
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
	//released=false;
}

void Ramp::Stop() {
	RampMotorLeft->Set(0);
	RampMotorRight->Set(0);
}

void Ramp::ReleaseStop() {
	RampMotorMid->Set(0);
}
void Ramp::StopRight(){
	RampMotorRight->Set(0);
}
void Ramp::StopLeft(){
	RampMotorLeft->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
