/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class TruncateCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    TruncateCommand();
};
