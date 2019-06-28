#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "trabajo.h"
#include "auto.h"


int mostrarAutosColores(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);
int mostrarAutosMarca(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);

int mostrarAutoFecha(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente);
int mostrarTrabajoAuto(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);
int mostrarAutoSinTrabajo(eTrabajo* trabajos, int tamTrabajo, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);
int mostrarImporteDeAuto(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);
int mostrarImporteDeAuto(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos);
int mostrarServicioMasPedido(eServicio* servicios, int tamServicios, eTrabajo* trabajos, int tamTrabajo);
int mostrarRecaudacionFecha(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios);
int mostrarAutosServicios(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente);
int trabajosRealizadosAutosXColor(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente);
int facturacionTotalPorServicio(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente);
int marcaMasServicios(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente);
#endif // INFORMES_H_INCLUDED
