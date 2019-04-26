/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class SplitCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    SplitCommand();
};
