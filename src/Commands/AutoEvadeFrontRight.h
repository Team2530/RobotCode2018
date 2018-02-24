#ifndef AutoEvadeFrontRight_H
#define AutoEvadeFrontRight_H

#include <Commands/CommandGroup.h>

class AutoEvadeFrontRight : public frc::CommandGroup {
private:
	double static constexpr BackAwayFromSwitch = -20;
	double static constexpr GetOutOfTheWay = 105;
public:
	AutoEvadeFrontRight();
};

#endif  // AutoEvadeFrontRight_H
