/*
 * SMOL.h
 *
 *  Created on: Jan 15, 2018
 *      Author: akeaa
 */

#ifndef SRC_COMMANDS_GRABCUBE_H_
#define SRC_COMMANDS_GRABCUBE_H_

#include <OI.h>
#include <Robot.h>

#include "Commands/Command.h"

class GrabCube : public Command {
public:
	GrabCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_GRABCUBE_H_ */
