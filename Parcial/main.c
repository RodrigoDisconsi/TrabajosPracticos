#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "disconsi.h"
#include "trabajo.h"
#include "informes.h"
#include "menu.h"
#define TAM 100
#define TAMCLIENTES 22
#define TAMCM 5
#define TAMS 5



int main()
{
    char seguir = 's';
    char seguirInformes = 's';
    char confirma;
    char confirmaInformes;
    int todoOk;
    int id = 100;
    int idTrabajo = 3000;
    eTrabajo trabajos[TAM] =
    {
        {1, "AAA201", 20000, {12,3,2019}, 1},
        {2, "DFR234", 20000, {2,4,2019}, 1},
        {3, "GFT564", 20001, {7,1,2019}, 1},
        {4, "ACD321", 20002, {9,11,2019}, 1},
        {5, "HTD656", 20003, {12,12,2019}, 1},
        {6, "QSZ435", 20001, {21,7,2019}, 1},
        {7, "LGX201", 20001, {29,8,2019}, 1},
        {8, "SUZ324", 20004, {31,5,2019}, 1},
        {9, "HCU762", 20004, {2,2,2019}, 1},
        {10, "DYC735", 20000, {18,2,2019}, 1},
        {11, "JJK879", 20001, {17,3,2019}, 1},
        {12, "AAA201", 20000, {17,4,2019}, 1},
        {13, "DFR234", 20000, {2,6,2019}, 1},
        {14, "GFT564", 20001, {7,3,2019}, 1},
        {15, "ACD321", 20002, {21,7,2019}, 1},
        {16, "HTD656", 20003, {11,9,2019}, 1},
        {17, "QSZ435", 20001, {3,7,2019}, 1},
        {18, "LGX201", 20001, {21,8,2019}, 1},
        {19, "SUZ324", 20004, {28,5,2019}, 1},
        {20, "HCU762", 20004, {2,8,2019}, 1},
        {21, "DYC735", 20000, {8,2,2019}, 1},
        {22, "JJK879", 20001, {17,3,2019}, 1},
        {23, "KOD220", 20003, {17,4,2019}, 1},
        {24, "QSZ305", 20000, {21,3,2019}, 1},
        {25, "SSD128", 20002, {16,4,2019}, 1},
        {26, "SSD240", 20000, {17,4,2019}, 1},
        {27, "EDF213", 20001, {23,3,2019}, 1},
        {28, "AAA201", 20000, {12,2,2019}, 1},
        {29, "DFR234", 20000, {2,3,2019}, 1},
        {30, "GFT564", 20001, {7,2,2019}, 1},
        {31, "ACD321", 20002, {9,12,2019}, 1},
        {32, "HTD656", 20003, {12,9,2019}, 1},
        {33, "QSZ435", 20001, {21,5,2019}, 1},
        {34, "HTD656", 20002, {12,2,2019}, 1},
        {35, "QSZ435", 20000, {21,1,2019}, 1},
    };
    eAuto lista[TAM]=
    {
        {0,1, "AAA201", 1000, 5001, 1995, 1},
        {1,2,"DFR234", 1003, 5000, 2002, 1},
        {2,3,"GFT564", 1002, 5003, 2007, 1},
        {3,4,"ACD321", 1002, 5003, 1995, 1},
        {4,5,"HTD656", 1004, 5002, 2008, 1},
        {5,6,"QSZ435", 1003, 5001, 1994, 1},
        {6,7,"LGX201", 1001, 5000, 2012, 1},
        {7,8,"SUZ324", 1001, 5002, 1991, 1},
        {8,9,"HCU762", 1000, 5003, 2008, 1},
        {9,10,"DYC735", 1003, 5001, 2002, 1},
        {10,11,"JJK879", 1003, 5001, 2010, 1},
        {11,12,"FED322", 1004, 5002, 2006, 1},
        {12,13,"GHV332", 1001, 5003, 2007, 1},
        {13,14,"BDE221", 1000, 5004, 1996, 1},
        {14,15,"OPD332", 1000, 5001, 2014, 1},
        {15,16,"PPD121", 1002, 5001, 2015, 1},
        {16,17,"IIT230", 1001, 5000, 2009, 1},
        {17,18,"KOD220", 1004, 5002, 2011, 1},
        {18,19,"QSZ305", 1004, 5002, 1993, 1},
        {19,20,"SSD128", 1002, 5003, 1992, 1},
        {20,21,"SSD240", 1003, 5004, 1992, 1},
        {21,22,"EDF213", 1001, 5000, 2001, 1},
    };
    eCliente clientes[TAMCLIENTES] =
    {
        {1, "Augusto", 'm'},
        {2, "Franco", 'm'},
        {3, "Aldana", 'f'},
        {4, "Leila", 'f'},
        {5, "Azul", 'f'},
        {6, "Rodrigo", 'm'},
        {7, "Ezequiel", 'm'},
        {8, "Yamila", 'f'},
        {9, "Delfina", 'f'},
        {10, "Violeta", 'f'},
        {11, "Hernest", 'm'},
        {12, "Dylan", 'm'},
        {13, "Micaela", 'f'},
        {14, "Camila", 'f'},
        {15, "Fernanda", 'f'},
        {16, "Bruno", 'm'},
        {17, "Santiago", 'm'},
        {18, "Magali", 'f'},
        {19, "Camila", 'f'},
        {20, "Monica", 'f'},
        {21, "Lucas", 'm'},
        {22, "Fernando", 'm'}

    };
    eColor colores[] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"},

    };
    eMarca marcas[] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"},
    };
    eServicio servicios[] =
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600},
        {20004, "Teflonado", 800}
    };

    //inicializarAutos(lista, TAM);
    //inicializarTrabajos(trabajos, TAM);

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            todoOk = altaAuto(lista, TAM, marcas, TAMCM, colores, TAMCM, clientes, TAMCLIENTES, &id);
            if(todoOk)
                printf("Alta del auto exitosa!!\n\n");
            system("pause");
            break;
        case 2:
            if(hayAutoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay Autos cargados.\n\n");
                system("pause");
                break;
            }
            modificarAuto(lista, TAM, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES);
            system("pause");
            break;
        case 3:
            if(hayAutoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay Autos cargados.\n\n");
                system("pause");
                break;
            }
            bajaAuto(lista, TAM, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES);
            system("pause");
            break;
        case 4:
            if(hayAutoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay Autos cargados.\n\n");
                system("pause");
                break;
            }
            //ordenarAutos(lista, TAM);
            mostrarAutos(colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES, lista, TAM);
            system("pause");
            break;
        case 5:
            system("cls");
            mostrarCliente(clientes, TAMCLIENTES);
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarMarca(marcas, TAMCM);
            system("pause");
            break;

        case 7:
            system("cls");
            mostrarColores(colores, TAMCM);
            system("pause");
            break;
        case 8:
            system("cls");
            mostrarServicio(servicios, TAMS);
            system("pause");
            break;
        case 9:
            if(hayAutoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay Autos cargados.\n\n");
                system("pause");
                break;
            }
            todoOk = altaTrabajo(trabajos, TAM, servicios, TAMS, lista, TAM, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES, &idTrabajo);
            if(todoOk)
            {
                printf("Alta exitosa!!\n\n");
                system("pause");
                break;
            }
            system("pause");
            break;
        case 10:
            if(hayTrabajoParaMostrar(trabajos, TAM) == -1)
            {
                printf("No hay Trabajos cargados.\n\n");
                system("pause");
                break;
            }
            mostrarTrabajos(trabajos, TAM, servicios, TAMS);
            system("pause");
            break;
        case 11:
            if(hayTrabajoParaMostrar(trabajos, TAM) == -1 && hayAutoParaMostrar(lista, TAM) == -1)
            {
                printf("No hay trabajos o autos cargados.\n\n");
                system("Pause");
                break;
            }
            do
            {
                switch(menuInformes())
                {
                case 1:
                    if(!mostrarAutosColores(colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES, lista, TAM))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 2:
                    if(!mostrarAutosMarca(colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES, lista, TAM))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 3:
                    if(!mostrarTrabajoAuto(trabajos, TAM, servicios, TAMS, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES, lista, TAM))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 4:
                    if(!mostrarAutoSinTrabajo(trabajos, TAM, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES, lista, TAM))
                        printf("No hay autos sin trabajo.\n");
                    system("Pause");
                    break;
                case 5:
                    if(!mostrarImporteDeAuto(trabajos, TAM, servicios, TAMS, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES, lista, TAM))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 6:
                    if(!mostrarServicioMasPedido(servicios, TAMS, trabajos, TAM))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 7:
                    if(!mostrarRecaudacionFecha(trabajos, TAM, servicios, TAMS))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 8:
                    if(!mostrarAutosServicios(lista, TAM, trabajos, TAM, servicios, TAMS, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES))
                        printf("No hay autos con el servicio seleccionado!\n");
                    system("Pause");
                    break;
                case 9:
                    if(!trabajosRealizadosAutosXColor(lista, TAM, trabajos, TAM, servicios, TAMS, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES))
                        printf("No hay trabajos con el color seleccionado!\n");
                    system("Pause");
                    break;
                case 10:
                    if(!facturacionTotalPorServicio(lista, TAM, trabajos, TAM, servicios, TAMS, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 11:
                    if(!marcaMasServicios(lista, TAM, trabajos, TAM, servicios, TAMS, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES))
                        printf("Error.\n");
                    system("Pause");
                    break;
                case 12:
                    if(!mostrarAutoFecha(lista, TAM, trabajos, TAM, colores, TAMCM, marcas, TAMCM, clientes, TAMCLIENTES))
                        printf("No hay autos en la fecha seleccionada!\n");
                    system("Pause");
                    break;
                case 13:
                    confirmaInformes = getChar("\nConfirma salida s/n?: ");
                    if( tolower(confirmaInformes) == 's')
                    {
                        seguir = 'n';
                    }
                    system("pause");
                    break;
                default:
                    printf("\nOpcion invalida\n\n");
                    system("Pause");
                    break;
                }
            }
            while(seguirInformes == 's');
            system("Pause");
            break;
        case 24:
            confirma = getChar("\nConfirma salida s/n?: ");
            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            system("pause");
            break;
        default:
            printf("\nOpcion invalida\n\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}


