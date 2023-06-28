#include "src\menu.h"


int main()
{
    menu menu;
    while (true)
    {
        menu::show();
        menu.choice();
    }
}