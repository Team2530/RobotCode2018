#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() : Subsystem("Elevator") {
	ElevatorMotor = new VictorSP(ChannelElevator);
	TopLimitSwitch = new frc::DigitalInput(0); //placeholder channel
	//MiddleLimitSwitch = new frc::DigitalInput(1); //placeholder channel
	//BottomLimitSwitch = new frc::DigitalInput(2); //placeholder channel
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Elevator::Raise(){
//	if (TopLimitSwitch->Get())
		//ElevatorMotor->Set(0);
	//else
		ElevatorMotor->Set(-maxPow);
}
void Elevator::Lower(){
	/*if (BottomLimitSwitch->Get())
		ElevatorMotor->Set(0);
	else*/
		ElevatorMotor->Set(maxPow);
}
void Elevator::Stop(){
	ElevatorMotor->Set(0);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
