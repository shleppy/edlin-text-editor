/* author: Shelby Hendrickx */
#ifndef LOAD_COMMAND_H
#define LOAD_COMMAND_H
#include "command.h"

class LoadCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    LoadCommand();
};

#endif // LOAD_COMMAND_H