#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "disconsi.h"
#include "menu.h"
#include "ArrayEmpleado.h"
#define TAM 7

int main()
{
    char seguir = 's';
    char confirma;
    int flag = 0;
    int todoOk;
    int legajo;
    legajo = 10000;
    eEmpleado lista[TAM] =
    {
        {10008, "Rodrigo",   "Disconsi",   300000.000, 3, 1},
        {10009, "Ivan",    "Gonzales",   400000.000, 2, 1},
        {10010, "Harry",   "Fernandes",  450.000, 1, 1},
        {10011, "Lucas",   "Liciardi",   550.000, 2, 0},
        {10012, "Fernando","Laurido",    650.000, 1, 1},
        {10113, "Mariano", "Perez",      750.000, 4, 1},
        {10114, "Pablo",   "Calamardo",  850.000, 3, 1}

    };
    //inicializarEmpleados(lista, TAM);
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            todoOk = altaEmpleado(lista, TAM, &legajo);
            if(todoOk)
            printf("Alta empleado exitosa!!\n\n");
            flag = 1;
            system("pause");
            break;
        case 2:
            if(!flag)
            {
                printf("Realice la carga de algun empleado.\n\n");
                system("pause");
                break;
            }
            modificarEmpleado(lista, TAM);
            system("pause");
            break;
        case 3:
            if(!flag)
            {
                printf("Realice la carga de algun empleado.\n\n");
                system("pause");
                break;
            }
            bajaEmpleado(lista, TAM);
            system("pause");
            break;
        case 4:
            if(!flag)
            {
                printf("Realice la carga de algun empleado.\n\n");
                system("pause");
                break;
            }
            ordenarEmpleados(lista, TAM, 1);
            mostrarEmpleados(lista, TAM);
            totalPromedioSalarios(lista, TAM);
            system("pause");
            break;
        case 5:
            confirma = getChar("\nConfirma salida s/n?: ");
            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            system("pause");
            break;
        default:
            printf("\n Opcion invalida\n\n");
        }
    }while(seguir == 's');
}
