#ifndef levator_H
#define levator_H

#include <Commands/Subsystem.h>

class levator : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	levator();
	void InitDefaultCommand();
};

#endif  // levator_H
