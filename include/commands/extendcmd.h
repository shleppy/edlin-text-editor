/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class ExtendCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    ExtendCommand();
};
