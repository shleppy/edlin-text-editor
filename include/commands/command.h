/* author: Shelby Hendrickx */
#pragma once
#include "../sstring.h"
#include "../textlist.h"

class Command {
public:
    /**
     * Executes the command
     * Returns the result code of the method
     */
    virtual int execute(TextList& text, const SString& str) = 0;
};
