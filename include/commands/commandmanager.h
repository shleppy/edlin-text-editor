/* author: Shelby Hendrickx */
#include <stack>
#include "undoable.h"

class CommandManager 
{
private:
    TextList *text;
    std::stack<Undoable*> undoStack;
    std::stack<Undoable*> redoStack;
    void handleUndoCommand(TextList *text, const SString& line, Undoable *cmd);
public:
    CommandManager();
    virtual ~CommandManager();

    void executeCommand(TextList *text, const SString& line);
};