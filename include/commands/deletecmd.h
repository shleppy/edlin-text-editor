/* author: Shelby Hendrickx */
#pragma once
#include "command.h"

class DeleteCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    DeleteCommand();
};
