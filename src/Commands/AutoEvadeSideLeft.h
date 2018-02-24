#ifndef AutoEvadeSideLeft_H
#define AutoEvadeSideLeft_H

#include <Commands/CommandGroup.h>

class AutoEvadeSideLeft : public frc::CommandGroup {
private:
	double static constexpr BackAwayFromSwitch = -12;
public:
	AutoEvadeSideLeft();
};

#endif  // AutoEvadeSideLeft_H
