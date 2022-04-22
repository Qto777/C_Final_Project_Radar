#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "arg.hpp"
using namespace std;
//Olga Grabowska

Parametry AnalizujArgumenty (int argc, char *argv[])
{
    Parametry p;
    char *plik = argv[2];

        if (strcmp (argv[1], "-T") == 0)
        {
            p.tekstowy = true;
            p.plik_we = fopen(plik, "r");
            return p;

		}
        else if (strcmp (argv[1], "-B") == 0)
        {
            p.tekstowy = false;
            p.plik_we =  fopen(plik, "rb");
            return p;
		}
        else
        {
            fputs("Bledny typ pliku. Podaj: (-T) dla pliku tekstowego lub (-B) dla pliku binarnego.", stderr);
            exit(1);
        }
       /* p.plik_we = fopen(argv[2], "r");
        if (!p.plik_we)
        {
            fputs("Nie moge otworzyc pliku wejsciowego", stderr);
            exit 1;
        }
        else
            return p;
    }
    else
    {
        fputs("Prosze upewnic sie, ze podano dokladnie 2 argumenty uruchomienia programu. Pierwszy: typ pliku (-T) dla tekstowego lub (-B) dla binarnego. Drugi: nazwa pliku wejsciowego.", stderr);
        exit(EXIT_FAILURE);
    }*/
}


