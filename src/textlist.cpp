/* author: Shelby Hendrickx */
#include "../include/textlist.h"
#include "../include/sstring.h"
#include "../include/linenode.h"

TextList::TextList() 
{
    header = new LineNode(nullptr);
    footer = new LineNode(nullptr);
    header->appendNextNode(footer);
    runner = nullptr;
    numOfLines = 0;
}

TextList::~TextList()
{
    setRunner();
    while (runner != footer)
    {
        LineNode *tmp = runner;
        runner = runner->getNext();
        delete tmp;
    }
    delete footer;
}

void TextList::setRunner() 
{
    runner = header;
}

void TextList::appendLine(SString s)
{
    footer->setData(s);
    footer->appendNextNode(new LineNode(nullptr));
    footer = footer->getNext();
    numOfLines++;
}

void TextList::printAll()
{
    setRunner();
    while (runner != footer)
    {
        runner->printLine();
    }
}

int TextList::numberOfLines()
{
    return numOfLines;
}

void TextList::insertLine(SString s, int n)
{
    if (n > numberOfLines()) return;

    // loop until correct line
    setRunner();
    int i = 0;
    while (i++ != n)
        runner = runner->getNext();

    // insert on line n
    LineNode *line = new LineNode(s);
    LineNode *tmp = runner->getNext();
    runner = line;
    runner->appendNextNode(tmp);

    // increment number of lines
    numOfLines++;
}
