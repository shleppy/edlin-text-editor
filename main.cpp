/* author: Shelby Hendrickx */
#include "include/editorgui.h"

int main(int argc, char* argv[])
{
    // TODO if filename not provided create new file

    if (argc == 2) EditorGUI(argv[1]).start();
    else EditorGUI().start();
    
    return 0;
}