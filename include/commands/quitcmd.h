/* author: Shelby Hendrickx */
#ifndef QUIT_COMMAND_H
#define QUIT_COMMAND_H
#include "command.h"

class QuitCommand : public Command
{
public: 
    int execute(TextList& text, const SString& str) override;
    QuitCommand();
};

#endif // QUIT_COMMAND_H