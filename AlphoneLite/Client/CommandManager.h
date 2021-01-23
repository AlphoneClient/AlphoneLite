#pragma once
#include "../Other/Command.h"
#include "../SDK/Minecraft.h"
#include <vector>
#include <iterator>
#include <algorithm>

class CommandManager {
public:
	static std::string prefix;
	static std::vector<class Command*> FetchCommands();
	static void registerCommands();
	static bool handleInput(std::string input);
	static void respond(std::string msg);
	static void respondEmptyLine();
};