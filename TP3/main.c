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
    int id = 1001;
    int flag  = 0;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
        do{
        switch(menuPrincipal())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("El archivo se leyo correctamente!\n");
                    flag = 1;
                }
                else
                    printf("Error al leer el archivo!\n");
                system("Pause");
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("El archivo se leyo correctamente!\n");
                    flag = 1;
                }
                else
                    printf("Error al leer el archivo!\n");
                system("Pause");
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados, &id))
                {
                    printf("Alta empleado exitosa!!\n");
                    flag = 1;
                }

                system("Pause");
                break;
            case 4:
                if(flag == 0)
                {
                    printf("No hay empleados en el sistema.\n");
                    system("Pause");
                    break;
                }
                if(!controller_editEmployee(listaEmpleados))
                    printf("No se pudo completar la operacion.\n\n");
                system("Pause");
                break;
            case 5:
                if(flag == 0)
                {
                    printf("No hay empleados en el sistema.\n");
                    system("Pause");
                    break;
                }
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
                if(flag == 0)
                {
                    printf("No hay empleados en el sistema.\n");
                    system("Pause");
                    break;
                }
                if(!ordenarEmpleados(listaEmpleados))
                    printf("No se pudo ordenar.\n");
                system("Pause");
                break;
            case 8:
                if(flag == 0)
                {
                    printf("No hay empleados en el sistema.\n");
                    break;
                }
                if(controller_saveAsText("data.csv",listaEmpleados))
                    printf("Se guardo correctamente!\n");
                else
                    printf("Error al guardar el archivo!\n");
                system("Pause");
                break;
            case 9:
                if(flag == 0)
                {
                    printf("No hay empleados en el sistema.\n");
                    break;
                }
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
