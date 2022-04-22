#include "grafika.hpp"
#include "dane.hpp"
#include "arg.hpp"
#include "statystyka.hpp"
#include <allegro.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;
//Olga Grabowska

void StatystykaMaxMin (const Obiekty &o, float &min, float &max)
{
    min = o[0].odleglosc;
    for (const Obiekt &i : o)
        if (i.odleglosc < min)
            min = i.odleglosc;

    max = o[0].odleglosc;
    for (const Obiekt &i : o)
        if (i.odleglosc > max)
            max = i.odleglosc;

    printf("Najmniejsza odleglosc to: %f", min); //
    printf("Najwieksza odleglosc to: %f", max); //

}

float SredniaWazonaOdleglosci (const Obiekty &o)
{
	float licznik = 0;
	float mianownik = 0;
    for (const Obiekt &i : o)
    {
		licznik += i.rozmiar * i.odleglosc;
        mianownik += i.rozmiar;
    }
    float sr_waz = licznik/mianownik;
    return sr_waz;
}

void WypelnijHistogramR (Histogram &h, const Obiekty &o)
{
    for (const Obiekt &i : o)
    {
        if (i.odleglosc >= 0 && i.odleglosc < 10)
            h.biny[0] += i.rozmiar;
        else if (i.odleglosc >= 10 && i.odleglosc < 20)
            h.biny[1] += i.rozmiar;
        else if (i.odleglosc >= 20 && i.odleglosc < 30)
            h.biny[2] += i.rozmiar;
        else if (i.odleglosc >= 30 && i.odleglosc < 40)
            h.biny[3] += i.rozmiar;
        else if (i.odleglosc >= 40 && i.odleglosc < 50)
            h.biny[4] += i.rozmiar;
        else if (i.odleglosc >= 50 && i.odleglosc < 60)
            h.biny[5] += i.rozmiar;
        else if (i.odleglosc >= 60 && i.odleglosc < 70)
            h.biny[6] += i.rozmiar;
            else if (i.odleglosc >= 70 && i.odleglosc < 80)
            h.biny[7] += i.rozmiar;
        else if (i.odleglosc >= 80 && i.odleglosc < 90)
            h.biny[8] += i.rozmiar;
        else if (i.odleglosc >= 90 && i.odleglosc < 100)
            h.biny[9] += i.rozmiar;

        h.masa_sum += i.rozmiar;
    }
}

void gwiazdki (float procent, unsigned max)
{
    unsigned l_gwiazdek;
    l_gwiazdek = (unsigned) procent * max;
        for (unsigned n = 0; n < l_gwiazdek; n++)
            printf("*");
}

void WyswietlHistogram (FILE *wy, const Histogram &h)
{
   /* for (int i = 0; i <= 10; i++)
    {
        float procent = (float) h.biny[i]/h.masa_sum;
    }*/
        fprintf(wy, "od 0 do 10: %f",h.biny[0]);
        gwiazdki((float) h.biny[0]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 10 do 20: %f",h.biny[1]);
        gwiazdki((float) h.biny[2]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 20 do 30: %f",h.biny[1]);
        gwiazdki((float) h.biny[2]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 30 do 40: %f",h.biny[2]);
        gwiazdki((float) h.biny[3]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 40 do 50: %f",h.biny[3]);
        gwiazdki((float) h.biny[4]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 50 do 60: %f",h.biny[4]);
        gwiazdki((float) h.biny[5]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 60 do 70: %f",h.biny[5]);
        gwiazdki((float) h.biny[6]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 70 do 80: %f",h.biny[6]);
        gwiazdki((float) h.biny[7]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 80 do 90: %f",h.biny[7]);
        gwiazdki((float) h.biny[8]/h.masa_sum, 100);
        fprintf(wy, "\n");
        fprintf(wy, "od 90 do 100: %f",h.biny[8]);
        gwiazdki((float) h.biny[9]/h.masa_sum, 100);
        fprintf(wy, "\n");
}
