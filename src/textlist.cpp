/* author: Shelby Hendrickx */
#include <string>
#include <fstream>
#include <memory>
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
    if (n == numOfLines) 
    {
        appendLine(str);
        return;
    }
    setRunner(n);
    LineNode *ins = new LineNode(str);
    ins->appendNextNode(runner->getNext());
    runner->appendNextNode(ins);
    numOfLines++;
}

void TextList::appendLine(const SString& str)
{   
    setRunner(numOfLines);
    LineNode *next = new LineNode(str);
    runner->appendNextNode(next);
    next->appendNextNode(footer);
    numOfLines++;
}

std::shared_ptr<SString> TextList::deleteLine(const size_t line)
{
    setRunner(line - 1);
    // save element to remove
    std::shared_ptr<SString> 
        deletedText(new SString(runner->getNext()->getData().getData()));
    // remove element from linked list
    runner->appendNextNode(runner->getNext()->getNext());
    numOfLines--;
    return deletedText;
}

void TextList::truncateLine(const size_t line, const size_t pos)
{
    setRunner(line);
    SString p = runner->getData();
    p.subStr(0, pos);
    runner->setData(p);
}

void TextList::extendLine(const SString& str, const size_t line)
{
    setRunner(line);
    SString cat_str(runner->getData() + str);
    if (cat_str.getLength() > 80)
        cat_str.subStr(0, 80);
    runner->setData(cat_str);
}

void TextList::replaceLine(const SString& str, const size_t line)
{
    setRunner(line);
    runner->setData(str);
}

void TextList::mergeLine(const size_t line)
{
    setRunner(line);
    SString cat = runner->getData() + runner->getNext()->getData();
    if (cat.getLength() > 80)
        cat.subStr(0, 80);
    runner->setData(cat);
    deleteLine(line + 1);
}

void TextList::splitLine(const SString& splitWord, const size_t line)
{
    // TODO implement splitline
}

SString TextList::getLine(const size_t line)
{
    setRunner(line);
    return runner->getData();
}

void TextList::printLine(size_t line)
{
    if (line > numOfLines) return;
    setRunner(line);
    runner->printLine();
}

void TextList::printAll(std::string file)
{
    if (numOfLines == 0) return;
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
