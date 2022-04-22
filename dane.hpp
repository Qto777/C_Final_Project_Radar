#ifndef _dane_h_
#define _dane_h_
using namespace std;
#include <vector>

//Olga Grabowska

struct Obiekt //lista
{
    float odleglosc;
    float kat;
    float rozmiar;
};

typedef vector <Obiekt> Obiekty;

Obiekty WczytajDaneTXT (FILE *plik);
float polozenieX (const Obiekt &o);
float polozenieY (const Obiekt &o);
Obiekty WczytajDaneBIN (FILE *plik);

#endif
