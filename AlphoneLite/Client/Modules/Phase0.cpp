#include "Phase0.h"

void Phase0::onGmTick(GameMode* GM) {
	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			Minecraft::ClientInstance()->LocalPlayer()->getPos()->y = (int)Minecraft::ClientInstance()->LocalPlayer()->getPosOld();
		}
	}
}

void Phase0::onDisable() {
	Module::onDisable();

	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			Minecraft::ClientInstance()->LocalPlayer()->resetPos(Minecraft::ClientInstance()->LocalPlayer()->getPosOld());
		}
	}
}