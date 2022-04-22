#ifndef _arg_h_
#define _arg_h_
#include <stdio.h>
//Olga Grabowska

struct Parametry
{
    bool tekstowy;
    FILE *plik_we;
};

Parametry AnalizujArgumenty (int argc, char *argv[]);

#endif
