#ifndef AutoEvadeSideLeft_H
#define AutoEvadeSideLeft_H

#include <Commands/CommandGroup.h>

class AutoEvadeSideLeft : public frc::CommandGroup {
public:
	AutoEvadeSideLeft();

	  void Initialize();
	  void Execute();
	  bool IsFinished();
	  void End();
	  void Interrupted();
	};


#endif  //AutoEvadeSideBack_H
