#include "NoFall.h"


void NoFall::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (type == PacketType::ActorFall) *cancel = true;
}