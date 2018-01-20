/*
 * SMOL.h
 *
 *  Created on: Jan 15, 2018
 *      Author: akeaa
 */

#ifndef SRC_COMMANDS_SMOL_H_
#define SRC_COMMANDS_SMOL_H_

#include <OI.h>
#include <robot.h>

#include "Commands/Command.h"

class SMOL : public Command {

	SMOL();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_SMOL_H_ */
