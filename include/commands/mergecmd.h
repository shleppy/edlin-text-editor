/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class MergeCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    MergeCommand();
};
