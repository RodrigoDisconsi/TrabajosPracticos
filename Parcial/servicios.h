#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "auto.h"


typedef struct{
        int id;
        char descripcion[26];
        float precio;
}eServicio;

void mostrarServicio(eServicio* servicios, int tam);
int obtenerServicio(eServicio* servicios, int tam, int idServicio, char desc[]);



#endif
