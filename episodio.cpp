#include "episodio.h"
using std::cout;
Episodio::Episodio()
{
    id = "0";
    nombre = "nombre de serie de prueba";
    genero = "genero de prueba";
    calificacion = 9.9;
    duracion = 2;
    fechaEstreno = "fecha de estreno de prueba";
    idEpisodio = "id episodio de prueba";
    nombreEpisodio = "nombre de episodio de prueba";
    temporada = 1;
    numEpisodio = 0;
}
Episodio::Episodio(string idc, string nom, string gen, double cal, int dur, string fEst, string idEps, int temp, string nomEps, int numEps)
{
    id = idc;
    nombre = nom;
    genero = gen;
    calificacion = cal;
    duracion = dur;
    fechaEstreno = fEst;
    idEpisodio = idEps;
    nombreEpisodio = nomEps;
    temporada = temp;
    numEpisodio = numEps;

}
string Episodio::getNombreEpisodio()
{
    return nombreEpisodio;
}
void Episodio::setCalificacion(double calUsuario)
{
    calificacion = calUsuario;
    cout << "se modificó la calificacion de el episodio: " << nombreEpisodio << " de " << nombre << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Episodio& episodio)
{
    os << "Episodio: " << episodio.nombreEpisodio
       << ", Serie: " << episodio.nombre
       << ", Genero: " << episodio.genero
       << ", Calificacion: " << episodio.calificacion
       << ", Id: " << episodio.id
       << ", Duracion: " << episodio.duracion
       << ", Fecha de estreno: " << episodio.fechaEstreno
       << ", Temporada: " << episodio.temporada
       << ", Numero de episodio: " << episodio.numEpisodio;
    return os;
}

