/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "undoable.h"

class ReplaceCommand : public Undoable
{
public:
    ReplaceCommand();

    int execute(TextList& text, const SString& str) override;
    void undo(TextList& text) override;
    void redo(TextList& text) override;
};