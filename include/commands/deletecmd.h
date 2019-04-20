/* author: Shelby Hendrickx */
#ifndef DELETE_COMMAND_H
#define DELETE_COMMAND_H
#include "command.h"

class DeleteCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    DeleteCommand();
};

#endif // DELETE_COMMAND_H