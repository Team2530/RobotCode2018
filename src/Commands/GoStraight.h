#ifndef GoStraight_H
#define GoStraight_H

#include "../CommandBase.h"

class GoStraight : public CommandBase {
public:
	GoStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GoStraight_H
