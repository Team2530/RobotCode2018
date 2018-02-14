#ifndef AutoEvadeSideBack_H
#define AutoEvadeSideBack_H

#include <Commands/CommandGroup.h>

class AutoEvadeSideBack : public frc::CommandGroup {
public:
	AutoEvadeSideBack();

	  void Initialize();
	  void Execute();
	  bool IsFinished();
	  void End();
	  void Interrupted();
	};


#endif  //AutoEvadeSideBack_H
