#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "cliente.h"
#include "color.h"



typedef struct{
    int id;
    int idCliente;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo;
    int estado;
}eAuto;

void inicializarAutos(eAuto* autos, int tam);
int buscarLibre(eAuto* autos, int tam);
int altaAuto(eAuto* autos, int tam, eMarca* marcas, int tamMarca, eColor* colores, int tamColor, eCliente* clientes, int tamClientes, int* id);
int buscarAuto(eAuto* autos, int tam, char* patente);
void mostrarAuto(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* aAuto);
void mostrarAutos(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);
int bajaAuto(eAuto* autos, int tam, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente);
void ordenarAutos(eAuto* autos, int tam);
int modificarAuto(eAuto* autos, int tam, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente);
int hayAutoParaMostrar(eAuto* autos, int tam);
int mostrarAutosColores(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);
int mostrarAutosMarca(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);

#endif // AUTO_H_INCLUDED
