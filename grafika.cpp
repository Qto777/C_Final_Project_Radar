#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafika.hpp"
#include "dane.hpp"
#include <allegro.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
//Olga Grabowska

void RysujRadar (const Obiekty &o)
{
    allegro_init ();
	install_keyboard ();
	set_color_depth (32);
	set_gfx_mode (GFX_AUTODETECT_WINDOWED, 500, 500, 0, 0);
    int green_color = makecol(0, 255, 0);
    int red_color = makecol(255, 0, 0);


    circle(screen, 0, 0, 50, green_color);
    circle(screen, 0, 0, 100, green_color);
    circle(screen, 0, 0, 150, green_color);
    circle(screen, 0, 0, 200, green_color);

    for (const Obiekt &i : o)
    {
        int x = polozenieX(i) * 2.5 + 250;
        int y = polozenieY(i) * 2.5 + 250;
        circlefill(screen, x, y, i.rozmiar, red_color);
    }

    allegro_exit ();
}

