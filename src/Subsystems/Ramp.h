#ifndef Ramp_H
#define Ramp_H
#include <WPILib.h>
#include <Encoder.h>
#include <Commands/Subsystem.h>
#include <LimitSwitch.h>

class Ramp : public Subsystem {
private:
	static constexpr int ChannelLeft = 2;
	VictorSP* RampMotorLeft;

	static constexpr int ChannelRight = 1;
	VictorSP* RampMotorRight;

	static constexpr int ChannelMid = 0;
	VictorSP* RampMotorMid;
	//Encoder* RampLeft;
	//Encoder* RampRight;
	bool released;
	int timeInSec;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	LimitSwitch* TopLimitSwitchLeft;
	LimitSwitch* TopLimitSwitchRight;
	LimitSwitch* BottomLimitSwitchLeft;
	LimitSwitch* BottomLimitSwitchRight;

public:
	double LeftPow=1;
	double RightPow =1;
	double LowerLeftPow =-0.4;
	double LowerRightPow =-0.4;
	double MidReleasePow = 1;
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
	void ReleaseStop();
	void Reset();
	void StopRight();
	void StopLeft();
};

#endif  // Ramp_H
