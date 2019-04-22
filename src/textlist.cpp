/* author: Shelby Hendrickx */
#include <string>
#include <fstream>
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
    return numOfLines;
}

void TextList::insertLine(const SString& str, const size_t n)
{
    if (n > numberOfLines() || n < 1) return;

    setRunner(n - 1);
    LineNode *line = new LineNode(str);
    line->appendNextNode(runner->getNext());
    runner->appendNextNode(line);

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

void TextList::extendLine(const SString& str, const size_t line)
{
    //TODO check if total len < 80
    setRunner(line);
    runner->setData(runner->getData() + str);
}

void TextList::printLine(size_t line)
{
    if (line > numOfLines) return;
    setRunner(line);
    runner->printLine();
}

void TextList::printAll(std::string file)
{
    size_t current_position = 1;
    setRunner(1);
    if (file == NULLFILE)
        printToOut();
    else
        printToFile(file);
}

void TextList::printToOut() 
{
    while (runner != footer)
    {
        runner->printLine();
        runner = runner->getNext();
    }
}

void TextList::printToFile(std::string file)
{
    std::ofstream fs(file);
    while (runner != footer)
    {
        fs << runner->getData().getData() << std::endl;
        runner = runner->getNext();
    }
    fs.close();
}

bool TextList::isEmpty()
{
    return numOfLines == 0;
}
