/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class HelpCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    HelpCommand();
};
