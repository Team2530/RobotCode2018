#ifndef AutoEvadeSideRight_H
#define AutoEvadeSideRight_H

#include <Commands/CommandGroup.h>

class AutoEvadeSideRight : public frc::CommandGroup {
private:
	double static constexpr BackAwayFromSwitch = -12;
public:
	AutoEvadeSideRight();
};

#endif  // AutoEvadeSideRight_H
