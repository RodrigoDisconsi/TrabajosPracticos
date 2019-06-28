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
    printf("  *** LAVADERO ***\n\n");
    printf("1- Alta Auto\n");
    printf("2- Modificar Auto\n");
    printf("3- Baja Auto\n");
    printf("4- Listar Autos\n");
    printf("5- Listar Clientes\n");
    printf("6- Listar Marcas\n");
    printf("7- Listar Colores\n");
    printf("8- Listar Servicios\n");
    printf("9- Alta Trabajo\n");
    printf("10- Listar Trabajos\n");
    printf("11- Mostrar autos por color\n");
    printf("12- Mostrar autos por marcas\n");
    printf("13- Mostrar trabajos efectuados a un auto\n");
    printf("14- Mostrar trabajos en una fecha determinada\n");
    printf("15- Mostrar autos sin trabajo\n");
    printf("16- Mostrar importes de un auto\n");
    printf("17- Mostrar servicio mas pedido\n");
    printf("18- Mostrar recaudacion en fecha\n");
    printf("24- Salir\n\n");
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
    printf("1- Cambiar color\n");
    printf("2- Cambiar modelo\n");
    printf("3- Salir\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}
