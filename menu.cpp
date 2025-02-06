#include "menu.h"
#include <iostream>
#include <stdexcept>

using namespace std;
Menu::Menu(Catalogo cat)
{
    catalogo = cat;
}
void Menu::aplicacion()
{
    int opcion = 0;
    while (opcion != 6)
    {
        cout << "1. Cargar archivo de datos (Excel o csv)" << endl;
        cout << "2. Mostrar los videos en general con:" << endl;
        cout << "3. Mostrar los episodios de una determinada serie." << endl;
        cout << "4. Mostrar las películas con una calificación mayor a cierto número" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        try
        {
            switch (opcion)
            {
                case 1:
                {
                    string rutaArchivo;
                    cout << "Ingresa el nombre del Archivo"<<endl
                    <<"En este formato 'BasePelículas.csv': ";
                    cin >> rutaArchivo;
                    catalogo.leerCSV(rutaArchivo);
                    break;
                }
                case 2:
                {
                    cout << "   1. Una calificación mayor a cierto parámetro" << endl;
                    cout << "   2. Un cierto género" << endl;
                    int subopcion;
                    cout << "Elige una opción: ";
                    cin >> subopcion;
                    if (subopcion == 1)
                    {
                        double calificacion;
                        do 
                        {
                            try
                            {
                                cout << "Ingresa la calificación mínima: ";
                                cin >> calificacion;
                                if (calificacion < 0 || calificacion > 10)
                                {
                                    throw invalid_argument("La calificación debe estar entre 0 y 10");
                                }
                            }
                            catch (const invalid_argument& e)
                            {
                                cerr << e.what() << endl;
                                continue;
                            }
                        } while (calificacion < 0 || calificacion > 10);
                        catalogo.mostrarVideosConCalificacionMayorA(calificacion);
                    }
                    else if (subopcion == 2)
                    {
                        string genero;
                        cout << "Ingresa el género: ";
                        cin >> genero;
                        catalogo.mostrarVideosDeGenero(genero);
                    }
                    else
                    {
                        throw invalid_argument("Opción no válida");
                    }
                    break;
                }
                case 3:
                {
                    string nombreSerie;
                    cout << "Ingresa el nombre de la serie: ";
                    cin.ignore();  // Agrega esta línea para limpiar el buffer de entrada.
                    getline(cin, nombreSerie);
                    catalogo.mostrarEpisodiosDeSerie(nombreSerie);
                    break;
                }
                case 4:
                {
                    double calificacion;
                    do
                    {
                        try
                        {
                            cout << "Ingresa la calificación mínima: ";
                            cin >> calificacion;
                            if (calificacion < 0 || calificacion > 10)
                            {
                                throw invalid_argument("La calificación debe estar entre 0 y 10");
                            }
                        }
                        catch (const invalid_argument& e)
                        {
                            cerr << e.what() << endl;
                            continue;
                        }
                    } while (calificacion < 0 || calificacion > 10);
                    catalogo.mostrarPeliculasConCalificacionMayorA(calificacion);
                    break;
                }
                case 5:
                {
                    string nombreVideo;
                    double calificacion;
                    cout << "Ingresa el nombre del video: ";
                    cin.ignore();  // Agrega esta línea para limpiar el buffer de entrada.
                    getline(cin, nombreVideo);
                    do 
                    {
                        try
                        {
                            cout << "Ingresa la calificación: ";
                            cin >> calificacion;
                            if (calificacion < 0 || calificacion > 10)
                            {
                                throw invalid_argument("La calificación debe estar entre 0 y 10");
                            }
                        }
                        catch (const invalid_argument& e)
                        {
                            cerr << e.what() << endl;
                            continue;
                        }
                    } while (calificacion < 0 || calificacion > 10);
                    catalogo.calificarVideo(nombreVideo, calificacion);
                    break;
                }

                case 6:
                {
                    cout << "Saliendo..." << endl;
                    break;
                }
                default:
                {
                    throw invalid_argument("Opción no válida");
                }
            }
        }
        catch (const invalid_argument& e)
        {
            cerr << e.what() << endl;
        }
    }
}
