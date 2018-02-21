#include "Ramp.h"
#include "../RobotMap.h"

Ramp::Ramp() : Subsystem("Ramp") {
	RampMotorLeft = new VictorSP(ChannelLeft);
	RampMotorRight = new VictorSP(ChannelRight);
	RampMotorMid = new VictorSP(ChannelMid);
	//RampLeft = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//8,9 fillers
	//RampRight = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );
	released=false;
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
		RampMotorLeft->Set(LeftPow);
		RampMotorRight->Set(RightPow);
	}
}
void Ramp::RaiseLeft() {
	RampMotorLeft->Set(LeftPow);
}
void Ramp::RaiseRight() {
	RampMotorRight->Set(RightPow);
}
void Ramp::Lower() {
	RampMotorLeft->Set(LowerLeftPow);
	RampMotorRight->Set(LowerRightPow);
}
void Ramp::LowerLeft() {
	RampMotorLeft->Set(LowerLeftPow);

}
void Ramp::LowerRight() {
	RampMotorRight->Set(LowerRightPow);
}
void Ramp::Release(){
	RampMotorMid->Set(MidReleasePow);
	released = true;
	//dunno how this gonna happppen
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
