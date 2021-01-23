#include "CommandManager.h"

std::string CommandManager::prefix = ".";
std::vector<Command*> Commands;

std::vector<Command*> CommandManager::FetchCommands() {
	return Commands;
}

#include "Commands/TestCommand.h"
//#include "Commands/SpeedCommand.h"
//#include "Commands/JumpCommand.h"
//#include "Commands/NukerCommand.h"
//#include "Commands/HelpCommand.h"
//#include "Commands/TeleportCommand.h"
//#include "Commands/TPAuraRangeCommand.h"
//#include "Commands/JetpackCommand.h"
//#include "Commands/GlideCommand.h"
//#include "Commands/GamemodeCommand.h"
//#include "Commands/ServerIpCommand.h"
//#include "Commands/KillauraCommand.h"

void CommandManager::registerCommands() {
	Commands.push_back(new TestCommand());
//	Commands.push_back(new SpeedCommand());
//	Commands.push_back(new JumpCommand());
//	Commands.push_back(new NukerCommand());
//	Commands.push_back(new HelpCommand());
//	Commands.push_back(new TeleportCommand());
//	Commands.push_back(new TPAuraRangeCommand());
//	Commands.push_back(new JetpackCommand());
//	Commands.push_back(new GlideCommand());
//	Commands.push_back(new GamemodeCommand());
//	Commands.push_back(new ServerIpCommand());
//	Commands.push_back(new KillauraCommand());
}

bool CommandManager::handleInput(std::string input) {
	if (input.length() > prefix.length()) {
		if (input.rfind(prefix, 0) == 0) {

			std::string newString = input;
			std::for_each(newString.begin(), newString.end(), [](char& c) {
				c = ::tolower(c);
				});

			newString.erase(0, prefix.length());

			std::istringstream iss(newString);
			std::vector<std::string> wordsArr(std::istream_iterator<std::string>{iss},
				std::istream_iterator<std::string>());

			bool wasFound = false;

			for (int I = 0; I < Commands.size(); I++) {
				if (Commands.at(I)->input == wordsArr.at(0)) {
					wasFound = true;
					Commands.at(I)->execute(newString, wordsArr);
				}
				else {
					if (Commands.at(I) == Commands.back()) {
						if (!wasFound) CommandManager::respond("Unknown Command!");
						wasFound = false;
					}
				}
			}

			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void CommandManager::respond(std::string msg) {
	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			TextHolder Text("[Alphone] " + msg);
			Minecraft::ClientInstance()->LocalPlayer()->displayTextObjectMessage(&Text);
		}
	}
}

void CommandManager::respondEmptyLine() {
	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			TextHolder Text("\n");
			Minecraft::ClientInstance()->LocalPlayer()->displayTextObjectMessage(&Text);
		}
	}
}