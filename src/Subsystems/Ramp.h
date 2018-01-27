#ifndef Ramp_H
#define Ramp_H
#include <WPILib.h>
#include <Commands/Subsystem.h>

class Ramp : public Subsystem {
private:
	static constexpr int ChannelLeft = 0; //placeholder number
	VictorSP* RampMotorLeft;

	static constexpr int ChannelRight = 1; //also placeholder number
	VictorSP* RampMotorRight;
	bool released;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Ramp();
	void InitDefaultCommand();
	void Raise();
	void Release();
	void Stop();
};

#endif  // Ramp_H
