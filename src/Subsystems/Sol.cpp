#include "../RobotMap.h"
#include <Solenoid.h>
#include <Subsystems/Sol.h>

Sol::Sol() : Subsystem("Sol") {
	frc::Solenoid *SMOL = new frc::Solenoid(solenoidChannel);
}

void Sol::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new GrabCube());

}
void Sol::Grab(){
	SMOL->Set(true);
}
void Sol::Release(){
	SMOL->Set(false);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
