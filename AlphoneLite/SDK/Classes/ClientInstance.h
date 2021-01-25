#pragma once
#include "TextHolder.h"
#include "MinecraftUIRenderContext.h"
#include "Actor.h"
#include "LocalPlayer.h"
#include "GameMode.h"

class ClientInstance {
public:
	class LocalPlayer* LocalPlayer() {
		if (this != nullptr) {
			return *reinterpret_cast<class LocalPlayer**>(reinterpret_cast<__int64>(this) + 0x138);
		}
		else {
			return nullptr;
		}
	}
	class GuiData
	{
	public:
		char pad_0000[40]; //0x0000
		Vec2 ScaledResolution; //0x0028
		char pad_0030[16]; //0x0030
	}; //Size: 0x0040

	class GuiData* GuiData() {
		uintptr_t** VTable = (uintptr_t**)this;
		return reinterpret_cast<class GuiData*>(VTable[155]);
	};
	class MinecraftGame* MinecraftGame() {
		if (this != nullptr) {
			return *reinterpret_cast<class MinecraftGame**>(reinterpret_cast<__int64>(this) + 0x98);
		}
		else {
			return nullptr;
		}
	}

	bool isValidTarget(class Actor* Entity) {
		if (Entity == nullptr) {
			return false;
		}
		if (Entity->isInvisible() || !Entity->isAlive() || Entity->isImmobile()) {
			return false;
		}
		if (Entity->getEntityTypeId() > 60 && Entity->getEntityTypeId() < 104 && Entity->getEntityTypeId() != 63) {
			return false;
		}
		if (Entity->getFormattedNameTag().length() <= 1) {
			return false;
		}
		if (!(this->LocalPlayer()->canAttack(Entity, false))) {
			return false;
		}
		return true;
	};
};

class BitmapFont {
public:
	//
};

class MinecraftGame {
public:
	class BitmapFont* MCFont() {
		return *reinterpret_cast<class BitmapFont**>(reinterpret_cast<__int64>(this) + 0xD8);
	}
	bool canUseKeys() {
		return *(bool*)(reinterpret_cast<uintptr_t>(this) + 0x260);
	}
};