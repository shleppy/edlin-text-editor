/* author: Shelby Hendrickx */
#include "../include/textlist.h"
#include "../include/sstring.h"
#include "../include/linenode.h"

#include <iostream>

TextList::TextList() 
{
    header = new LineNode("");
    footer = new LineNode("");
    runner = nullptr;

    header->appendNextNode(footer);
}

TextList::~TextList()
{
    runner = header;
    LineNode *lnp;
    while (runner != footer)
    {
        lnp = runner->getNext();
        delete runner;
        runner = lnp;
    }
}

void TextList::setRunner(const size_t line)
{
    runner = header;
    for (size_t i = 0; i <= line; ++i) 
    {
        runner = runner->getNext();
    }
}

size_t TextList::numberOfLines()
{
    return numOfLines++;
}

void TextList::insertLine(const SString& str, const size_t n)
{
    if (n > numberOfLines() || n < 1) return;

    // loop until correct line
    size_t current_position = 1;
    setRunner(current_position);
    int i = 0;
    while (i++ != n)
        runner = runner->getNext();

    // insert on line n
    LineNode *line = new LineNode(str);
    LineNode *tmp = runner->getNext();
    runner = line;
    runner->appendNextNode(tmp);

    // increment number of lines
    numOfLines++;
}

void TextList::appendLine(const SString& str)
{   
    LineNode *next = new LineNode(str);
    setRunner(numOfLines);
    runner->appendNextNode(next);
    next->appendNextNode(footer);
    numOfLines++;
}

void TextList::deleteLine(const size_t line)
{
    setRunner(line - 1);
    LineNode *p = runner->getNext();
    runner->appendNextNode(runner->getNext()->getNext());
    numOfLines--;
    delete p;
}

void TextList::printLine(size_t line)
{
    setRunner(line);
    runner->printLine();
}

void TextList::printAll()
{
    size_t current_position = 1;
    setRunner(current_position);
    while (runner != footer)
    {
        runner->printLine();
        runner = runner->getNext();
    }
}

