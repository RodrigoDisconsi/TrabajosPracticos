#include <stdio.h>
#include <stdlib.h>
#include "disconsi.h"
#include "menu.h"


int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("  *** Administrar Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Modificar Empleado\n");
    printf("3- Baja Empleado\n");
    printf("4- Informar Empleados\n");
    printf("5- Salir\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}

int menuModificar()
{
   int opcion;
    system("cls");
    printf("  *** Administrar Empleados ***\n\n");
    printf("1- Cambiar nombre\n");
    printf("2- Cambiar apellido\n");
    printf("3- Cambiar salario\n");
    printf("4- Cambiar sector\n");
    printf("5- Salir\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}
