 #ifndef AutoEvadeFrontLeft_H
#define AutoEvadeFrontLeft_H

#include <Commands/CommandGroup.h>

class AutoEvadeFrontLeft : public frc::CommandGroup {
private:
	double static constexpr BackAwayFromSwitch = -20;
	double static constexpr DriveOutOfTheWay = 105;
public:
	AutoEvadeFrontLeft();
};

#endif  // AutoEvadeFrontLeft_H
