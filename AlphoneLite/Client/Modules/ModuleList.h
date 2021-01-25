#pragma once
#include "../ClientManager.h"
#include "../../Other/Module.h"
#include "TabGUI.h"

class ModuleList : public Module {
public:
	ModuleList() : Module::Module("Module List", "Visuals", "Shows Enabled Modules") {
		enabled = true;
	}
	void onRender();
};
