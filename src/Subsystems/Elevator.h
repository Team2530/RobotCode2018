#ifndef Elevator_H
#define Elevator_H
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <LimitSwitch.h>

class Elevator : public Subsystem {
private:
	static constexpr int ChannelElevator = 3;
	VictorSP* ElevatorMotor;
	static constexpr double minPow = 0.4;
	static constexpr double maxPow =0.6;// 0.3;
	LimitSwitch* TopLimitSwitch;
	//frc::DigitalInput* MiddleLimitSwitch;
	//frc::DigitalInput* BottomLimitSwitch;


	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Elevator();
	void InitDefaultCommand();
	void Raise();
	void Lower();
	void RaiseAuto();
	void Stop();
};

#endif  // Elevator_H
