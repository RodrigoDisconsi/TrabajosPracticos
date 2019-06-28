#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "servicios.h"
#include "fecha.h"
#include "cliente.h"
#include "marca.h"
#include "color.h"


typedef struct{
        int id;
        char patente[11];
        int idServicio;
        eFecha fecha;
        int estado;
}eTrabajo;

void inicializarTrabajos(eTrabajo* trabajos, int tam);
int buscarLibreTrabajo(eTrabajo* trabajos, int tam);
int altaTrabajo(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios, eAuto* autos, int tamAutos, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamClientes, int* id);
int hayTrabajoParaMostrar(eTrabajo* trabajos, int tam);
void mostrarTrabajos(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicio);
void mostrarTrabajo(eServicio* servicios, int tam, eTrabajo* trabajo);

#endif // TRABAJO_H_INCLUDED
