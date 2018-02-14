#ifndef AutoEvadeSide_H
#define AutoEvadeSide_H

#include <Commands/CommandGroup.h>

class AutoEvadeSide : public frc::CommandGroup {
public:
	AutoEvadeSide();

	  void Initialize();
	  void Execute();
	  bool IsFinished();
	  void End();
	  void Interrupted();
	};
};

#endif  //AutoEvadeSide_H
