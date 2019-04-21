/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class QuitCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    QuitCommand();
};
