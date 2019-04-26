/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "undoable.h"

class SplitCommand : public Undoable
{
public:
    SplitCommand();
    
    int execute(TextList& text, const SString& str) override;
    void undo(TextList& text) override;
    void redo(TextList& text) override;
};
