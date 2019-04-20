/* author: Shelby Hendrickx */
#ifndef INSERT_COMMAND_H
#define INSERT_COMMAND_H
#include "command.h"

class InsertCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    InsertCommand();
};

#endif // INSERT_COMMAND_H