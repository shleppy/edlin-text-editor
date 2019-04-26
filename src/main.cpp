/* author: Shelby Hendrickx */
#include <iostream>
#include "../include/editorgui.h"

void testSString();
void testLineNode();
void testTextList();

int main(int argc, char* argv[])
{
    // TODO if filename not provided create new file

    std::cout << "Welcome to Edline" << std::endl;

    // testSString();
    // testLineNode();
    //testTextList();

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
    std::cout << std::endl;
    SString str2{"bar"};
    std::cout << str2.getLength() << std::endl;

    SString cat = str + str2;
    cat.print();
    std::cout << std::endl;

    // f o o b a r
    // 1 2 3 4 5 6
    cat.subStr(2,4);
    cat.print();
    std::cout << std::endl;
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
    std::cout << "START" << std::endl;
    SString str{"foo"};
    SString str2{"bar"};
    SString str3{"foobar"};
    SString test{"teststring"};

    TextList *list = new TextList();
    list->appendLine(str);
    list->appendLine(str2);
    list->appendLine(str3);
    // list->printAll();

    list->extendLine(test, 2);
    // list->truncateLine(2, 3);
    // list->extendLine(str2, 2);
    // list->extendLine(str2, 2); 
    list->printAll();
    std::cout << "END" << std::endl;
}
