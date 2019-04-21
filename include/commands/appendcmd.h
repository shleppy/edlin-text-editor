/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class AppendCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    AppendCommand();
};
