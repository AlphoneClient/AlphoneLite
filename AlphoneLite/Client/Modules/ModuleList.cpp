#include "ModuleList.h"

void ModuleList::onRender() {
		Vec2 ScreenResolution = Minecraft::ClientInstance()->GuiData()->ScaledResolution;
		std::vector<Module*> Modules = ClientManager::GetModules();
		std::vector<std::string> enabledModules;

		for (int I = 0; I < Modules.size(); I++) {
			if (Modules[I]->enabled) enabledModules.push_back(Modules[I]->name);
		}

		enabledModules = Utils::smallestToBiggestStringVec(enabledModules);
		std::reverse(enabledModules.begin(), enabledModules.end());

		if (enabledModules.size() > 0) {
			for (int I = 0; I < enabledModules.size(); I++) {
				float TextWidth = RenderUtils::GetTextWidth(enabledModules[I], 1.0f);
				float width = ScreenResolution.x - TextWidth;

				RenderUtils::DrawRectangle(Vec4(width - 7, I * 10 + 5, width + TextWidth - 3, I * 10 + 15), MC_Colour(0, 1, 1, 0), .7, 1.2);
				RenderUtils::FillRectangle(Vec4(width - 7, I * 10 + 5, width + TextWidth - 3, I * 10 + 15), MC_Colour(0, 0, 0, 1), 0.2f);
				RenderUtils::RenderText(enabledModules[I], Vec2(width - 5, I * 10 + 5), MC_Colour(1, 1, 1, 1), 1.0f, 1.0f);
				RenderUtils::FlushText();
		}
	}
}