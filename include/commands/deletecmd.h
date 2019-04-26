/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "undoable.h"

class DeleteCommand : public Undoable
{
private:
    SString deletedText;
    size_t line;
public:
    DeleteCommand();
    
    int execute(TextList& text, const SString& str) override;
    void undo(TextList& text) override;
    void redo(TextList& text) override;
};
