/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "undoable.h"

class AppendCommand : public Undoable
{
private:
    SString insertionText;
    size_t line;
public:
    AppendCommand();

    int execute(TextList& text, const SString& str) override;
    void undo(TextList& text) override;
    void redo(TextList& text) override;
};
