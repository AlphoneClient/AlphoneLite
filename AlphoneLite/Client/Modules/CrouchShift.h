#pragma once
#include "../../Other/Module.h"

class CrouchShift : public Module {
public:
	CrouchShift() : Module::Module("Crouch Shift", "Movement", "Crouch Shift") {}
	void onGmTick(GameMode* GM);
};