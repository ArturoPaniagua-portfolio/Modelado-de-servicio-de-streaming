#ifndef _PELICULA_H
#define _PELICULA_H
#include "video.h"
#include "interface.h"
using std::endl;
class Pelicula : public Video, public Interface
{
public:
    Pelicula();
    Pelicula(string idc, string nom, string gen, double cal, int dur, string fEst);
    virtual void print(std::ostream& os) const override;
    virtual Interface& operator+(double calUsuario) override;
    string getNombre();
};
#endif