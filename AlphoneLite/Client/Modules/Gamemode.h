#pragma once
#include "../../Other/Module.h"

class Gamemode : public Module {
public:
	Gamemode() : Module::Module("Gamemode", "Player", "Go into creative") {};
	virtual void onEnable();
	virtual void onTick();
	virtual void onDisable();

	static int GamemodeValue;
};