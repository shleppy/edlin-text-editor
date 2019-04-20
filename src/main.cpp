/* author: Shelby Hendrickx */
#include <iostream>
#include "../include/editorgui.h"
using namespace std;

int main(int argc, char* argv[])
{
    // TODO if filename not provided create new file

    cout << "Welcome to Edline" << endl;

    if (argc == 2) 
    {
        cout << "Starting application with file: " <<  argv[1] << endl;
        EditorGUI(argv[1]).start();
    }
    else 
    {
        cout << "Starting application" << endl;
        EditorGUI().start();
    }
    
    return 0;
}