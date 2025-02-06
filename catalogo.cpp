#include <map>
#include <fstream>
#include <sstream>
#include "pelicula.h"
#include "serie.h"
#include "episodio.h"
#include "catalogo.h"

using namespace std;

void Catalogo::leerCSV(string rutaArchivo)
{
    ifstream file(rutaArchivo);
    string line;
    map<string, Serie*> series;

    bool firstLine = true;
    while (getline(file, line))
    {
    if (firstLine) 
    {
        firstLine = false;
        continue;
    }
        istringstream ss(line);
        vector<string> tokens;
        bool inQuotes = false;
        stringstream token;
        char c;
        while (ss.get(c))
        {
            if (c == '"')
            {
                inQuotes = !inQuotes;
            }
            else if (c == ',' && !inQuotes)
            {
                tokens.push_back(token.str());
                token.str("");
            }
            else
            {
                token << c;
            }
        }
        tokens.push_back(token.str());

        // Ahora puedes usar tokens[i] para acceder al i-ésimo campo
        string id = tokens[0];
        string nombre = tokens[1];
        int duracion = tokens[2].empty() ? 0 : stoi(tokens[2]);
        string genero = tokens[3];
        double calificacion = tokens[4].empty() ? 0.0 : stod(tokens[4]);
        string fechaEstreno = tokens[5];
        string nombreEpisodio = tokens[6];
        int temporada = tokens[7].empty() ? 0 : stoi(tokens[7]);
        int numEpisodio = tokens[8].empty() ? 0 : stoi(tokens[8]);
        string idEpisodio = tokens[9];


        if (nombreEpisodio.empty())
        {
            // Es una película
            Pelicula* pelicula = new Pelicula(id, nombre, genero, calificacion, duracion, fechaEstreno);
            catalogo.push_back(pelicula);
        }
        else
        {
            // Es un episodio de una serie
            Episodio* episodio = new Episodio(id, nombre, genero, calificacion, duracion, fechaEstreno, idEpisodio, temporada, nombreEpisodio, numEpisodio);

            // Busca la serie en el mapa
            Serie* serie = series[nombre];
            if (serie == nullptr)
            {
                // Si la serie no existe, crea una nueva y añádela al mapa y al catálogo
                serie = new Serie(nombre, {});
                series[nombre] = serie;
                catalogo.push_back(serie);
            }

            // Añade el episodio a la serie
            serie->addEpisodio(*episodio);
        }
    }
    cout << endl << "---------- archivo leido ----------" << endl;
}

void Catalogo::mostrarVideosConCalificacionMayorA(double calificacion)
{
    for (Interface* video : catalogo)
    {
        Pelicula* peliculaPtr = dynamic_cast<Pelicula*>(video);
        Serie* seriePtr = dynamic_cast<Serie*>(video);
        
        if (peliculaPtr && peliculaPtr->getCalificacion() > calificacion)
        {
            cout << *peliculaPtr << endl;
        }
        else if (seriePtr)
        {
            vector<Episodio*> episodios = seriePtr->getEpisodiosConCalificacionMayorA(calificacion);
            for (Episodio* episodio : episodios)
            {
                cout << *episodio << endl;
            }
        }
    }
}
bool Catalogo::contains(const string& s, const string& substring)
{
    return s.find(substring) != string::npos;
}
void Catalogo::mostrarVideosDeGenero(string genero)
{
    for (Interface* video : catalogo)
    {
        Pelicula* peliculaPtr = dynamic_cast<Pelicula*>(video);
        Serie* seriePtr = dynamic_cast<Serie*>(video);
        
        if (peliculaPtr && contains(peliculaPtr->getGenero(), genero))
        {
            cout << *peliculaPtr << endl;
        }
        else if (seriePtr)
        {
            vector<Episodio*> episodios = seriePtr->getEpisodiosDeGenero(genero);
            for (Episodio* episodio : episodios)
            {
                cout << *episodio << endl;
            }
        }
    }
}

void Catalogo::mostrarEpisodiosDeSerie(string nombreSerie)
{
    for (Interface* video : catalogo)
    {
        Serie* seriePtr = dynamic_cast<Serie*>(video);
        
        if (seriePtr && seriePtr->getNombre() == nombreSerie)
        {
            vector<Episodio*> episodios = seriePtr->getEpisodios();
            for (Episodio* episodio : episodios)
            {
                cout << *episodio << endl;
            }
        }
    }
}

void Catalogo::mostrarPeliculasConCalificacionMayorA(double calificacion)
{
    for (Interface* video : catalogo)
    {
        Pelicula* peliculaPtr = dynamic_cast<Pelicula*>(video);
        
        if (peliculaPtr && peliculaPtr->getCalificacion() > calificacion)
        {
            cout << *peliculaPtr << endl;
        }
    }
}

void Catalogo::calificarVideo(string nombreDeVideo, double calificacion)
{
    for (Interface* video : catalogo)
    {
        Pelicula* peliculaPtr = dynamic_cast<Pelicula*>(video);
        Serie* seriePtr = dynamic_cast<Serie*>(video);

        if (peliculaPtr && peliculaPtr->getNombre() == nombreDeVideo)
        {
            *peliculaPtr + calificacion;
            cout << "Se calificó la película: " << nombreDeVideo << " con una calificación de: " << calificacion << endl;
            break;
        }
        else if (seriePtr)
        {
            vector<Episodio*> episodios = seriePtr->getEpisodios();
            for (Episodio* episodio : episodios)
            {
                if (episodio->getNombreEpisodio() == nombreDeVideo)
                {
                    episodio->setCalificacion(calificacion);
                    cout << "Se calificó el episodio: " << nombreDeVideo << " con una calificación de: " << calificacion << endl;
                    break;
                }
            }
        }
    }
}
