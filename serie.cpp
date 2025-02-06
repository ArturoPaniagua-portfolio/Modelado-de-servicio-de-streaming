#include "serie.h"
using std::endl;
using std::cout;
using std::cin;

Serie::Serie()
{
    nombre = "nombre de prueba";
    episodios = {};
}
Serie::Serie(string nom, vector<Episodio> eps)
{
    nombre = nom;
    episodios = eps;
}
void Serie::print(std::ostream& os) const
{
    os << "Nombre de la serie: " << nombre << endl;
    for(int i = 0; i < episodios.size(); i++)
    {
        Episodio eps = episodios[i];
        os << "Episodio " << i+1 << ": " << eps.getNombreEpisodio() << endl;
    } 
}
Interface& Serie::operator+(double calUsuario)
{   
    cout<<"episodios para calificar: "<<endl;
    for(int i = 0; i < episodios.size(); i++)
    {
        Episodio eps = episodios[i];
        cout << "Episodio " << i+1 << ": " << eps.getNombreEpisodio() << endl;
    } 
        cout << "¿Que episodio quiere calificar?"<<endl;
        cout << "Ingrese el número: ";
        int nep;
        cin >> nep; cout <<endl;
        Episodio eps = episodios[nep-1];
        eps.setCalificacion(calUsuario);
        cout << "listo" << endl; 
}
void Serie::addEpisodio(const Episodio& episodio)
{
    episodios.push_back(episodio);
}
vector<Episodio*> Serie::getEpisodiosConCalificacionMayorA(double calificacion)
{
    vector<Episodio*> episodiosFiltrados;
    for (Episodio& episodio : episodios)
    {
        if (episodio.getCalificacion() > calificacion)
        {
            episodiosFiltrados.push_back(&episodio);
        }
    }
    return episodiosFiltrados;
}
vector<Episodio*> Serie::getEpisodiosDeGenero(string genero)
{
    vector<Episodio*> episodiosFiltrados;
    for (Episodio& episodio : episodios)
    {
        if (contains(episodio.getGenero(), genero))
        {
            episodiosFiltrados.push_back(&episodio);
        }
    }
    return episodiosFiltrados;
}
vector<Episodio*> Serie::getEpisodios()
{
    vector<Episodio*> episodiosPtrs;
    for (Episodio& episodio : episodios)
    {
        episodiosPtrs.push_back(&episodio);
    }
    return episodiosPtrs;
}
string Serie::getNombre()
{
    return nombre;
}
bool Serie::contains(const string& s, const string& substring)
{
    return s.find(substring) != string::npos;
}