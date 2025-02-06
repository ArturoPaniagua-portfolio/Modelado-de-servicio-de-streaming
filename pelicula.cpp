#include "pelicula.h"
using std::cout;
using std::endl;
Pelicula::Pelicula()
{
    id = "0";
    nombre = "pelicula de prueba";
    genero = "genero de prueba";
    calificacion = 9.9;
    duracion = 2;
    fechaEstreno = "fecha de estreno de prueba";
}
Pelicula::Pelicula(string idc, string nom, string gen, double cal, int dur, string fEst)
{
    id = idc;
    nombre = nom;
    genero = gen;
    calificacion = cal;
    duracion = dur;
    fechaEstreno = fEst;
}

void Pelicula::print(std::ostream& os) const
{
    os << "Pelicula: " << nombre 
       << ", Genero: " << genero 
       << ", Calificacion: " << calificacion
       << ", Id: " << id
       << ", Duracion: " << duracion
       << ", Fecha de estreno: " << fechaEstreno << endl;
}

Interface& Pelicula::operator+(double calUsuario)
{
    // Implementa cómo quieres que se sume una calificación a una Pelicula
    calificacion = calUsuario;
}
string Pelicula::getNombre()
{
    return nombre;
}