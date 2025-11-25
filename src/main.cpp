#include "foundations/memory.h"
#include <stdio.h>


int main()
{

    cashew::memory::Block memblock(9);
    const char* text = "Hello, World!\n";

    for (int i = 0; i < 15; i++) {
        memblock.AddChar(text[i], i);
    }

    printf(memblock.GetC_Str());

    return 0;

}