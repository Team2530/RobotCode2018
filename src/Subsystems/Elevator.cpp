#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() : Subsystem("Elevator") {
	ElevatorMotor = new VictorSP(ChannelElevator);

	MiddleLimitSwitch = new frc::DigitalInput(1); //placeholder channel
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Elevator::Raise(){
	if (MiddleLimitSwitch->Get())
		ElevatorMotor->Set(0);
	else
		ElevatorMotor->Set(maxPow);
}
void Elevator::Lower(){
	ElevatorMotor->Set(-1*maxPow);
}
void Elevator::RaiseAuto(){
	ElevatorMotor->Set(minPow);
}
void Elevator::DropRamps(){
	ElevatorMotor->Set(maxPow);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
