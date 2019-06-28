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
    printf("11- Informes\n");
    printf("12- Salir\n\n");
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

int menuInformes()
{
    int opcion;
    system("cls");
    printf("  *** INFORMES ***\n\n");
    printf("1- Mostrar autos por color seleccionado\n");
    printf("2- Mostrar autos por marcas seleccionada\n");
    printf("3- Mostrar trabajos efectuados a un auto\n");
    printf("4- Mostrar autos sin trabajo\n");
    printf("5- Mostrar importes de trabajo a un auto\n");
    printf("6- Mostrar servicio mas pedido\n");
    printf("7- Mostrar recaudacion en una fecha\n");
    printf("8- Mostrar autos por servicio seleccionado y la fecha\n");
    printf("9- Mostrar trabajos realizados a un auto por color seleccionado\n");
    printf("10- Mostrar facturacion de un servicio selccionado\n");
    printf("11- Mostrar la marca que efectua mas servicio seleccionado\n");
    printf("12- Mostrar autos que recibieron trabajos en una fecha determinada\n");
    printf("13- Salir\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}
