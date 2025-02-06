#ifndef _VIDEO_H
#define _VIDEO_H
#include <iostream>
#include <string>
using std::string;
class Video
{
    protected:
    string id;
    string nombre;
    string genero;
    double calificacion;
    int duracion;
    string fechaEstreno;

    public:
    Video();
    Video(string idc, string nom, string gen, double cal, int dur, string fEst);
    double getCalificacion();
    string getGenero();
};
#endif