#include "Menu.h"

int main(void)
{
    setlocale(LC_ALL, "RUS");
    std::vector<Event*> vec;
    menu(vec);
    system("pause");
}