#include "catalogo.h"
#include "menu.h"
int main() {
    Catalogo catalogo;
    Menu menu(catalogo);
    menu.aplicacion();

    catalogo.mostrarEpisodiosDeSerie("Game Of Thrones");
    return 0;
}
