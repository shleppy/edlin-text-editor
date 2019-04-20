/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class SaveCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    SaveCommand();
};
