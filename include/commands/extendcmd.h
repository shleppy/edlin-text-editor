/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "undoable.h"

class ExtendCommand : public Undoable
{
public:
    ExtendCommand();
    
    int execute(TextList& text, const SString& str) override;
    void undo(TextList& text);
    void redo(TextList& text);
};
