#pragma once
#include "../../Other/Module.h"

class NoFall : public Module {
public:
	NoFall() : Module::Module("NoFall", "Player", "Dont take fall damage") {}
	void onPacket(void* Packet, PacketType type, bool* cancel);
};
