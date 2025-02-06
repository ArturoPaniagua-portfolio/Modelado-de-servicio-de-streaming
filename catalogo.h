#ifndef _CATALOGO_H
#define _CATALOGO_H
#include "interface.h"
#include "vector"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using std::vector;
using std::string;
class Catalogo
{
    private:
        vector<Interface*> catalogo;

    public:
        void leerCSV(string rutaArchivo);
        void mostrarVideosConCalificacionMayorA(double calificacion);
        void mostrarVideosDeGenero(string genero);
        void mostrarEpisodiosDeSerie(string nombreSerie);
        void mostrarPeliculasConCalificacionMayorA(double calificacion);
        void calificarVideo(string nombreVideo, double calificacion);
        bool contains(const string& s, const string& substring);
};
#endif