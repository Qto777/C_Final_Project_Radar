#ifndef _statystyka_h_
#define _statystyka_h_
#include <math.h>
#include <vector>
#include <allegro.h>
#include "arg.hpp"
#include "dane.hpp"
//Olga Grabowska

struct Histogram
{
    float biny[10];
    float masa_sum;
};

void StatystykaMaxMin (const Obiekty &o, float &min, float &max);
float SredniaWazonaOdleglosci (const Obiekty &o);
void WypelnijHistogramR (Histogram &h, const Obiekty &o);
void WyswietlHistogram (FILE *wy, const Histogram &h);

#endif
