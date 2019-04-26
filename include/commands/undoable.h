/* author: Shelby Hendrickx*/
#pragma once
#include "../commands/command.h"
#include "../textlist.h"
#include "../sstring.h"

class Undoable : public Command
{
public: 
    virtual ~Undoable() { };
    virtual int execute(TextList& text, const SString& str) = 0;
    virtual void undo(TextList& text) = 0;
    virtual void redo(TextList& text) = 0;
};