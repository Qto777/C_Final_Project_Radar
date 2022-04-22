#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <allegro.h>
#include <vector>
#include "arg.hpp"
#include "dane.hpp"
#include "grafika.hpp"
#include "statystyka.hpp"
using namespace std;

//Olga Grabowska

int main(int argc, char *argv[])
{
    Parametry p;
    p = AnalizujArgumenty(argc, argv);
    Obiekty o;
    if ( p.tekstowy == TRUE)
    {
        o = WczytajDaneTXT (p.plik_we);
    }
    else
    {
        o = WczytajDaneBIN(p.plik_we);
    }
    RysujRadar(o);
    float min, max;
    StatystykaMaxMin(o, min, max);
    float sr = SredniaWazonaOdleglosci(o);
    printf("Srednia wazona odleglosci to: %f", sr); //
    Histogram hist = {0};
    WypelnijHistogramR(hist, o);
    WyswietlHistogram(stdout, hist);
    readkey();
    allegro_exit();


    return 0;
}
