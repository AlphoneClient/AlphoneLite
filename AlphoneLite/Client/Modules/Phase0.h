#pragma once
#include "../../Other/Module.h"

class Phase0 : public Module {
public:
	Phase0() : Module::Module("Phase", "Player", "Walk through walls!") {};
	virtual void onGmTick(GameMode* GM);
	virtual void onDisable();
};