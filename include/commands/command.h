/* author: Shelby Hendrickx */
#ifndef COMMAND_H
#define COMMAND_H
#include "../sstring.h"
#include "../textlist.h"

class Command {
public:
    /**
     * Executes the command
     * Returns the result code of the method 
     */
    virtual int execute(TextList& text, const SString& str) = 0;

    /**
     * Default destructor
     */
    //virtual ~Command();
};

#endif // COMMAND_H