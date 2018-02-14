#ifndef AutoEvadeLeftSide_H
#define AutoEvadeLeftSide_H

#include <Commands/CommandGroup.h>

class AutoEvadeLeftSide : public frc::CommandGroup {
public:
	AutoEvadeLeftSide();

	  void Initialize();
	  void Execute();
	  bool IsFinished();
	  void End();
	  void Interrupted();
	};
};

#endif  //AutoEvadeLeftSide_H
