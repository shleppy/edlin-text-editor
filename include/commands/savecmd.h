/* author: Shelby Hendrickx */
#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H
#include "command.h"

class SaveCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    SaveCommand();    
};

#endif // SAVE_COMMAND_H
