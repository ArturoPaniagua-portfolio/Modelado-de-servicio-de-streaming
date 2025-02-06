#include "video.h"
Video::Video()
{
    id = "0";
    nombre = "video de prueba";
    genero = "genero de prueba";
    calificacion = 9.9;
    duracion = 2;
    fechaEstreno = "fecha de estreno de prueba";
}
Video::Video(string idc, string nom, string gen, double cal, int dur, string fEst)
{
    id = idc;
    nombre = nom;
    genero = gen;
    calificacion = cal;
    duracion = dur;
    fechaEstreno = fEst;
}
double Video::getCalificacion()
{
    return calificacion;
}
string Video::getGenero()
{
    return genero;
}