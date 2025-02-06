#ifndef _SERIE_H
#define _SERIE_H
#include "interface.h"
#include "episodio.h"
#include <vector>
using std::vector;
class Serie : public Interface
{
    protected:
    vector<Episodio> episodios;
    string nombre;

    public:
    Serie();
    Serie(string nom, vector<Episodio> eps);
    string getNombre();
    virtual void print(std::ostream& os) const override;
    virtual Interface& operator+(double calUsuario) override;
    void addEpisodio(const Episodio& episodio);
    vector<Episodio*> getEpisodiosConCalificacionMayorA(double calificacion);
    vector<Episodio*> getEpisodiosDeGenero(string genero);
    vector<Episodio*> getEpisodios();
    bool contains(const string& s, const string& substring);
};
#endif