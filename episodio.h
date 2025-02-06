#ifndef _EPISODIO_H
#define _EPISODIO_H
#include "video.h"
class Episodio : public Video
{
    protected:
        string idEpisodio;
        string nombreEpisodio;
        int temporada;
        int numEpisodio;
    
    public:
        Episodio();
        Episodio(string idc, string nom, string gen, double cal, int dur, string fEst, string idEps, int temp, string nomEps, int numEps);
        string getNombreEpisodio();
        void setCalificacion(double calUsuario);
        friend std::ostream& operator<<(std::ostream& os, const Episodio& episodio);
};
#endif