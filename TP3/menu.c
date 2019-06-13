#include <stdio.h>
#include <stdlib.h>
#include "disconsi.h"
#include "menu.h"


/** \brief Es el menu de opciones principal.
 * \return Retorna la opción elegida.
 */


int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("1- Cargar los datos de los empleados desde el archivo data.csv\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.bin\n");
    printf("3- Alta empleado\n");
    printf("4- Modificar datos de empleado\n");
    printf("5- Baja empleado\n");
    printf("6- listar empleados\n");
    printf("7- Ordenar empleados\n");
    printf("8- Guardar los datos de los empleados en el archivo data.csv\n");
    printf("9- Guardar los datos de los empleados en el archivo data.bin\n");
    printf("10- Salir\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}

/** \brief Es el menu de opciones de la opción modificar.
 * \return Retorna la opción elegida.
 */

int menuModificar()
{
   int opcion;
    printf("---Modificar---\n");
    printf("1- Cambiar id\n");
    printf("2- Cambiar nombre\n");
    printf("3- Horas trabajadas\n");
    printf("4- Sueldo\n");
    printf("5- Salir\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}

int menuOrdenar()
{
    int opcion;
    printf("---Ordenar---\n");
    printf("1- Ordenar por id\n");
    printf("2- Ordenar por nombre\n");
    printf("3- Ordenar por horas trabajadas\n");
    printf("4- Ordenar por Sueldo\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}

int subMenuOrdenar()
{
    int opcion;
    printf("---Ordenar---\n");
    printf("1- Ordenar de forma ascendente\n");
    printf("2- Ordenar de forma descendente\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}

