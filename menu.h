#ifndef _MENU_H
#define _MENU_H
#include "catalogo.h"
class Menu
{
    private:
    Catalogo catalogo;

    public:
    Menu(Catalogo cat);
    void aplicacion();
};
#endif