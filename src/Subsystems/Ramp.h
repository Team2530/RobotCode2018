#ifndef Ramp_H
#define Ramp_H
#include <WPILib.h>
#include <Encoder.h>
#include <Commands/Subsystem.h>

class Ramp : public Subsystem {
private:
	static constexpr int ChannelLeft = 0; //placeholder number
	VictorSP* RampMotorLeft;

	static constexpr int ChannelRight = 1; //also placeholder number
	VictorSP* RampMotorRight;
	Encoder* RampLeft;
	Encoder* RampRight;
	bool released;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	double LeftPow=0.4;
	double RightPow =0.4;
	double LowerLeftPow =-0.4;
	double LowerRightPow =-0.4;
	Ramp();
	void InitDefaultCommand();
	void Raise();
	void RaiseLeft();
	void RaiseRight();
	void Lower();
	void LowerRight();
	void LowerLeft();
	void Release();
	void Stop();
};

#endif  // Ramp_H
