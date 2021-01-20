#include "CrouchShift.h"


void CrouchShift::onGmTick(GameMode* GM) {
	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
			if (Player->isSneaking()) {
				float playerYaw = (Player->lookingVector.y + 90.0f) * (PI / 180.0f);
				Vec3 currPos = *Player->getPos();
				float newX = currPos.x += cos(playerYaw) * 0.32f;
				float newZ = currPos.z += sin(playerYaw) * 0.32f;
				Player->setPos(&currPos);
			}
		}
	}
}