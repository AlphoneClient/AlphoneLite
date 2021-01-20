#include "GameMode.h"

int Gamemode::GamemodeValue = 1;
int savedGamemodeValue;

void Gamemode::onEnable() {
	Module::onEnable();

	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			Minecraft::ClientInstance()->LocalPlayer()->setPlayerGameType(1);
		}
	}
}

void Gamemode::onTick() {
	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			Minecraft::ClientInstance()->LocalPlayer()->setPlayerGameType(1);
		}
	}
}

void Gamemode::onDisable() {
	Module::onDisable();

	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			Minecraft::ClientInstance()->LocalPlayer()->setPlayerGameType(0);
		}
	}
}