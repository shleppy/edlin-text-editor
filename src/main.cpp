/* author: Shelby Hendrickx */
#include <iostream>
#include "../include/editorgui.h"

int main(int argc, char* argv[])
{
    // TODO if filename not provided create new file

    std::cout << "Welcome to Edline" << std::endl;

    if (argc == 2)
    {
        std::cout << "Starting application with file: " <<  argv[1] << std::endl;
        EditorGUI(argv[1]).start();
    }
    else
    {
        std::cout << "Starting application" << std::endl;
        EditorGUI().start();
    }

    return 0;
}
