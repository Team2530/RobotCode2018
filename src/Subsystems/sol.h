#ifndef SOL_H
#define SOL_H

#include <Commands/Subsystem.h>
#include <Solenoid.h>

class SOL : public Subsystem {
private:
//	static constexpr int SMOL=0;//this is a placeholder port

	frc::Solenoid *SMOL = new Solenoid(0);

public:
	SOL();
	void InitDefaultCommand();
};

#endif  // SOL_H
