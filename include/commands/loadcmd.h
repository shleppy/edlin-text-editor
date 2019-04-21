/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class LoadCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    LoadCommand();
};
