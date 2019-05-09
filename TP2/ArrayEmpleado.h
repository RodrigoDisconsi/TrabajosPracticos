#include <stdio.h>

struct
{
 int legajo;
 char nombre[51];
 char apellido[51];
 float sueldo;
 int sector;
 int ocupado;
}typedef eEmpleado;

void inicializarEmpleados(eEmpleado vec[], int tam);

void mostrarEmpleado(eEmpleado emp);

void mostrarEmpleados(eEmpleado vec[], int tam);

int altaEmpleado(eEmpleado vec[], int tam, int* legajo);

void modificarEmpleado(eEmpleado vec[], int tam);

void totalPromedioSalarios(eEmpleado vec[], int tam);

void bajaEmpleado(eEmpleado vec[], int tam);

int buscarLibre(eEmpleado vec[], int tam);

void ordenarEmpleados(eEmpleado vec[], int tam, int order);
