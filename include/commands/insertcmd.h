/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "undoable.h"

class InsertCommand : public Undoable
{
private:
    size_t line;
    SString insertionText;
public:
    InsertCommand();
    int execute(TextList& text, const SString& str) override;
    void undo(TextList& text) override;
    void redo(TextList& text) override;
};
