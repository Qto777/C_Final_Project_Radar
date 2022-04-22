#ifndef _grafika_h_
#define _grafika_h_
#include <math.h>
#include <allegro.h>
#include <vector>
#include "arg.hpp"
#include "dane.hpp"

//Olga Grabowska

void RysujRadar(const Obiekty &o);
int makecol(int r, int g, int b);
void circle(BITMAP *bmp, int x, int y, int radius, int color);
void circlefill(BITMAP * bmp, int x, int y, int radius, int color);


#endif
