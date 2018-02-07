#ifndef AutoLeftToAFront_H
#define AutoLeftToAFront_H

#include "../CommandBase.h"

class AutoLeftToAFront : public CommandBase {
public:
	AutoLeftToAFront();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoLeftToAFront_H
