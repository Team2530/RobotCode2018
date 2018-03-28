#include <Solenoid.h>
#include <Subsystems/Sol.h>

Sol::Sol() : Subsystem("Sol") {
	//SMOL = new frc::Solenoid(solenoidChannel);
	SMOL = new frc::DoubleSolenoid(solenoidChannel1, solenoidChannel2);
}

void Sol::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new GrabCube());

}
void Sol::Grab(){
	SMOL->Set(frc::DoubleSolenoid::Value::kReverse);//koff//reverse//forward
}
void Sol::Release(){
	SMOL->Set(frc::DoubleSolenoid::Value::kForward);//kforward//off//reverse
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
