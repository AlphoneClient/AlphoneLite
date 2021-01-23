#pragma once
#include "../../Other/Module.h"

class CrouchPhase : public Module {
public:
	CrouchPhase() : Module::Module("Crouch Shift", "Movement", "Crouch Shift") {}
	void onGmTick(GameMode* GM);
};