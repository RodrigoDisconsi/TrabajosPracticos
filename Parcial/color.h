#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct {
        int id;
        char nombreColor[21];
}eColor;

int obtenerColor(eColor* colores, int tam, int idColor, char* desc);
void mostrarColores(eColor* colores, int tam);


#endif // COLOR_H_INCLUDED
