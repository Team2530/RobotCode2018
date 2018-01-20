#ifndef SOL_H
#define SOL_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <Solenoid.h>

class Sol : public Subsystem {
private:
//	static constexpr int SMOL=0;//this is a placeholder port

	frc::Solenoid *SMOL = new Solenoid(0);

public:
	Sol();
	void InitDefaultCommand();
};

#endif  // SOL_H