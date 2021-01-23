#include "Command.h"

Command::Command(std::string input, std::string description) {
	this->input = input;
	this->description = description;
}

void Command::execute(std::string input, std::vector<std::string> words) {};