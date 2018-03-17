#ifndef SOL_H
#define SOL_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <Solenoid.h>

class Sol : public frc::Subsystem {
private:
	static constexpr int solenoidChannel1=0;//this is a placeholder port
	static constexpr int solenoidChannel2=1;//place holder as well

	frc::Solenoid *SMOL;

public:
	Sol();
	void InitDefaultCommand();
	void Grab();
	void Release();
};

#endif  // SOL_H
