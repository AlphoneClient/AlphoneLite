#pragma once
#include "../../Other/Command.h"

class TestCommand : public Command {
public:
	TestCommand();
	virtual void execute(std::string input, std::vector<std::string> words);
};