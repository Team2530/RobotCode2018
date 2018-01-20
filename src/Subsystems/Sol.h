#ifndef SOL_H
#define SOL_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <Solenoid.h>

class Sol : public Subsystem {
private:
	static constexpr int solenoidChannel=0;//this is a placeholder port

	frc::Solenoid *SMOL;

public:
	Sol();
	void InitDefaultCommand();
	void Grab();
	void Release();
};

#endif  // SOL_H
