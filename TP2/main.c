#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "disconsi.h"
#include "menu.h"
#include "ArrayEmpleado.h"
#define TAM 1000

int main()
{
    char seguir = 's';
    char confirma;
    int todoOk;
    int id = 10000;
    eEmpleado lista[TAM];
    inicializarEmpleados(lista, TAM);
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            todoOk = altaEmpleado(lista, TAM, &id);
            if(todoOk)
                printf("Alta empleado exitosa!!\n\n");
            system("pause");
            break;
        case 2:
            if(hayEmpleadoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay empleados cargados.\n\n");
                system("pause");
                break;
            }
            modificarEmpleado(lista, TAM);
            system("pause");
            break;
        case 3:
            if(hayEmpleadoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay empleados cargados.\n\n");
                system("pause");
                break;
            }
            bajaEmpleado(lista, TAM);
            system("pause");
            break;
        case 4:
            if(hayEmpleadoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay empleados cargados.\n\n");
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
