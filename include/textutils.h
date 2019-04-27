/* author: Shelby Hendrickx */
#include <cstring>
#include <memory>
#include "textlist.h"
#include "sstring.h"

class TextUtils
{
    public:
        static size_t getLineNumberFromCommand(TextList &text, const SString& line);
        static std::shared_ptr<SString> getLineFromCin();
};


