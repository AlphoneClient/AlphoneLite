#pragma once
#include <string>
#include <vector>
#include "../Client/CommandManager.h"

class Command {
public:

	std::string input;
	std::string description;
	std::vector<std::string> words;
	Command(std::string input, std::string description);

	virtual void execute(std::string input, std::vector<std::string> words);
};