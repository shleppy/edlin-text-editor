/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class InsertCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    InsertCommand();
};
