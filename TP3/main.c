#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "disconsi.h"
#include "menu.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int isOk;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
        do{
        switch(menuPrincipal())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
                    printf("El archivo se leyo correctamente!\n");
                else
                    printf("Error al leer el archivo!\n");
                system("Pause");
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                    printf("El archivo se leyo correctamente!\n");
                else
                    printf("Error al leer el archivo!\n");
                system("Pause");
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados))
                    printf("Alta empleado exitosa!!\n");
                system("Pause");
                break;
            case 4:
                if(!controller_editEmployee(listaEmpleados))
                    printf("No se pudo completar la operacion.\n\n");
                system("Pause");
                break;
            case 5:
                if(!controller_removeEmployee(listaEmpleados))
                    printf("No se pudo completar la operacion.\n\n");
                system("Pause");
                break;
            case 6:
                isOk = controller_ListEmployee(listaEmpleados);
                if(!isOk)
                    printf("Error al mostrar empleados.\n\n");
                else if(isOk == -1)
                    printf("No hay empleados para mostrar.\n\n");
                system("Pause");
                break;
            case 7:
                if(!ordenarEmpleados(listaEmpleados))
                    printf("No se pudo ordenar.\n");
                system("Pause");
                break;
            case 8:
                if(controller_saveAsText("data.txt",listaEmpleados))
                    printf("Se guardo correctamente!\n");
                else
                    printf("Error al guardar el archivo!\n");
                system("Pause");
                break;
            case 9:
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                    printf("Se guardo correctamente!\n");
                else
                    printf("Error al guardar el archivo!\n");
                system("Pause");
                break;
            case 10:
                seguir = getChar("\nDesea salir s/n?: ");
                if( tolower(seguir) == 's')
                {
                    seguir = 'n';
                }
                system("pause");
                break;

        }
    }while(seguir == 's');

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
