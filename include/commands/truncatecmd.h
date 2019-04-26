/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "undoable.h"

class TruncateCommand : public Undoable
{
public:
    TruncateCommand();

    int execute(TextList& text, const SString& str) override;
    void undo(TextList& text) override;
    void redo(TextList& text) override;
};
