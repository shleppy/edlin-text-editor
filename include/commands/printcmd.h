/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class PrintCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    PrintCommand();
};
