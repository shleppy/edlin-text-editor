/* author: Shelby Hendrickx */
#include <cstring>
#include "textlist.h"
#include "sstring.h"

class TextUtils
{
    public:
        static size_t getLineNumberFromCommand(TextList &text, const SString& line);
        static SString* getLineFromCin();
};


