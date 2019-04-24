/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class ReplaceCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    ReplaceCommand();
};