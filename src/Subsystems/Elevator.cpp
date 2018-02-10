#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() : Subsystem("Elevator") {
	ElevatorMotor = new VictorSP(ChannelElevator);
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Elevator::Raise(){
	ElevatorMotor->Set(maxPow);
}
void Elevator::RaiseAuto(){
	ElevatorMotor->Set(minPow);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
