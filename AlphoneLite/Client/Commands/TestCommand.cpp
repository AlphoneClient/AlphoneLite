#include "TestCommand.h"

TestCommand::TestCommand() : Command::Command("test", "Description of sorts (WIP)") {

}

void TestCommand::execute(std::string input, std::vector<std::string> words) {
	CommandManager::respond("Test Command was executed");
}