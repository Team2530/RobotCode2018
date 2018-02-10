#ifndef Elevator_H
#define Elevator_H
#include <WPILib.h>
#include <Commands/Subsystem.h>

class Elevator : public Subsystem {
private:
	static constexpr int ChannelElevator = 0; //placeholder number
	VictorSP* ElevatorMotor;
	static constexpr double minPow = 0.1;
	static constexpr double maxPow = 0.7;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Elevator();
	void InitDefaultCommand();
	void Raise();
	void RaiseAuto();
};

#endif  // Elevator_H
