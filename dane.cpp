#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "arg.hpp"
#include "dane.hpp"
#include <vector>
using namespace std;
//Olga Grabowska

Obiekty WczytajDaneTXT (FILE *plik)
{
    Obiekty o;
    Obiekt pomoc;
    float odleglosc, kat, rozmiar;
    while (!feof(plik))
    {
        int i = fscanf(plik, "%f\t%f\t%f\n", &odleglosc, &kat, &rozmiar);
        if (i == 3)
        {
            pomoc = {odleglosc, (float) M_PI * kat / 180, rozmiar};
            o.push_back(pomoc);
        }
    }
    fclose(plik);
    return o;
}

float polozenieX (const Obiekt &o)
{
    float x = o.odleglosc * sin(o.kat);
    return x;
}

float polozenieY (const Obiekt &o)
{
    float y = o.odleglosc * cos(o.kat);
    return y;
}

Obiekty WczytajDaneBIN (FILE *plik)
{
    Obiekty o;
    Obiekt pomoc;
    float *tab = (float*)malloc(sizeof(float)*3);
    while (!feof(plik))
    {
        for (int i = 0; i < 3; i++)
        {
            fread(&tab[i], sizeof(float), 1, plik);
        }
        pomoc = {tab[0], tab[1]*M_PI/180, tab[2]};
        o.push_back(pomoc);
    }
    return o;
}
