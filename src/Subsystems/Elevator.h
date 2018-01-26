#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>

class Elevator : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Elevator();
	void InitDefaultCommand();
	void Raise();
};

#endif  // Elevator_H
