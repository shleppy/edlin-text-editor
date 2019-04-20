/* author: Shelby Hendrickx */
#include <iostream>
#include "../include/editorgui.h"
using namespace std;

void testSString();
void testLineNode();
void testTextList();

int main(int argc, char* argv[])
{
    // TODO if filename not provided create new file
    cout << "Welcome to Edline" << endl;

    // testSString();
    // testLineNode();
    // testTextList();

    if (argc > 1) 
    {
        const char* fileName = argv[1];
        EditorGUI gui{fileName};
        gui.start();
    }
    else 
    {
        EditorGUI gui{};
        gui.start();
    }
    
    return 0;
}

void testSString()
{
    SString str{"foo"};
    str.print();
    cout << endl;
    SString str2{"bar"};
    cout << str2.getLength() << endl;

    SString cat = str + str2;
    cat.print();
    cout << endl;
}

void testLineNode()
{
    SString str{"foo"};
    LineNode *n = new LineNode(str);
    SString str2{"bar"};
    LineNode *n2 = new LineNode(str2);
    SString str3{"test"};
    LineNode *n3 = new LineNode(str3);

    n->appendNextNode(n2);
    n2->appendNextNode(n3);

    while(n != nullptr)
    {
        n->printLine();
        n = n->getNext();
    }
}

void testTextList()
{
    SString str{"foo"};
    SString str2{"bar"};
    SString str3{"test"};

    TextList *list = new TextList();
    list->appendLine(str);
    list->appendLine(str2);
    list->printLine(2);
    list->insertLine(str3, 1);
    list->printAll();
}