#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "disconsi.h"
#define TAM 15
#define TAMSEC 5
#define TAMCOMIDA 5
#define TAMALMUERZO 18

typedef struct
{
   int dia;
   int mes;
   int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int ocupado;

} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{
    int id;
    char descripcion[20];
}eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fechaAlmuerzo;
}eAlmuerzo;

void inicializarEmpleados(eEmpleado vec[], int tam);
int menudeOpciones();
int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarSectores( eSector sectores[], int tam);
void empleadoMayorSueldoXSector( eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida comidas[], int tamComida, eEmpleado empleados[], int tam);
void mostrarAlmuerzos(eAlmuerzo almuerzo[], int tamAlmuerzo, eComida comida[], int tamComida, eEmpleado empleados[], int tam);
void mostrarAlmuerzoFecha(eAlmuerzo almuerzo[], int tamAlmuerzo, eComida comida[], int tamComida, eEmpleado empleados[], int tam);
int compararFechas (eFecha fecha1, eFecha fecha2);
void mostrarAlmuerzoXSector (eAlmuerzo almuerzos[], int tamAlmuerzo, eComida comidas[], int tamComida, eEmpleado empleados[], int tam, eSector sectores[], int tamSec);

int altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void bajaEmpleado(eEmpleado vec[], int tam, int legajo);


int main()
{
    char seguir = 's';
    char confirma;
    eSector sectores[] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},

    };
    eEmpleado lista[TAM]=
    {
        {1234, "Juan", 'm', 30000,{12,3,2000},5, 1},
        {2222, "Ana", 'f', 32000, {2,7,2010}, 2,1},
        {2211, "Jorge", 'm', 28000,{14,5,2013}, 2,1},
        {3241, "Alberto", 'm', 35000, {2,9,2010},1, 1},
        {8944, "Sonia", 'f', 39000, {12,3,2012},3,1},
        {2231, "Miguel", 'm', 29700, {28,7,2009}, 2,1},
        {6578, "Adrian", 'm', 43200, {11,1,2016},5, 1},
        {3425, "Lucia", 'f', 32300, {19,10,2004}, 2,1},
        {5546, "Gaston", 'm', 29760, {13,9,2006},4,1},
        {7500, "Augusto", 'm', 47000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,1},
        {7463, "Eduardo", 'm', 25000, {12,12,2003}, 4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 0},
        {9045, "Fernanda", 'f', 47000,{18, 7,2011}, 1,0},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,0}
    };

    eComida comidas[]=
    {
        {1, "Milanesa"},
        {2, "Canelones"},
        {3, "Pescado"},
        {4, "Pollo"},
        {5, "Tarta"},
    };

    eAlmuerzo almuerzo[]=
    {
        {101, 1234, 1, {25,4,2018}},
        {102, 3241, 2, {25,4,2018}},
        {103, 9040, 5, {25,4,2018}},
        {104, 7439, 1, {20,3,2018}},
        {105, 7654, 4, {20,3,2018}},
        {106, 9040, 5, {20,3,2018}},
        {107, 1234, 1, {20,2,2018}},
        {108, 3241, 4, {21,2,2018}},
        {109, 2231, 5, {21,2,2018}},
        {110, 5546, 1, {21,1,2018}},
        {111, 8944, 4, {21,1,2018}},
        {112, 9040, 3, {22,1,2018}},
        {113, 8944, 1, {22,3,2018}},
        {114, 2231, 4, {22,3,2018}},
        {115, 9040, 2, {23,2,2018}},
        {116, 1234, 1, {24,2,2018}},
        {117, 2231, 4, {24,2,2018}},
        {118, 6578, 5, {24,2,2018}}
    };
    //inicializarEmpleados(lista, TAM);




    do
    {
        switch(menudeOpciones())
        {

        case 1:
            printf("\nAlta empleado\n\n");
            if(altaEmpleado(lista, TAM, sectores, TAMSEC))
            {
                printf("Alta de empleado exitosa!!\n\n");
            }
            else
            {
                printf("                        ***NO SE PUDO REALIZAR EL ALTA***\n");
            }
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 6:
            //printf("\nListar empleados\n\n");
            mostrarSectoresConEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
         case 7:
            //printf("\nListar empleados\n\n");
            mostrarCantEmpleadosXSector(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

         case 8:
            //printf("\nListar empleados\n\n");
            SectorMasEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
         case 9:
            empleadoMayorSueldoXSector(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 10:
            mostrarAlmuerzoFecha(almuerzo, TAMCOMIDA, comidas, TAMCOMIDA, lista, TAM);
            system("pause");
            break;
        case 11:
            mostrarAlmuerzos(almuerzo, TAMALMUERZO, comidas, TAMCOMIDA, lista, TAM);
            system("pause");
            break;
        case 12:
            mostrarAlmuerzoXSector(almuerzo, TAMALMUERZO, comidas, TAMCOMIDA, lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 13:
            confirma = getChar("\nConfirma salida s/n?: ");
            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}


void inicializarEmpleados(eEmpleado vec[], int tam)
{
        for(int i = 0; i < tam ; i++)
        {
            vec[i].ocupado = 0;
        }
}

int menudeOpciones()
{
    int opcion;
    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Listar Sectores con Empleados\n");
    printf("7- Cantidad de empleados por sector\n");
    printf("8- Sectores con mas empleados\n");
    printf("9- Empleados que mas ganan por sector\n");
    printf("10- Mostrar almuerzo en determinada fecha\n");
    printf("11- Mostrar almuerzos\n");
    printf("12- Mostrar almuerzo por sector\n");
    printf("13- Salir\n\n");
    opcion = getInt("Ingrese una opcion: ");
    printf("\n\n");
    return opcion;
}
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    int consigioNombre;

   consigioNombre =  obtenerSector(sectores, tam, emp.idSector, nombreSector);

    if( !consigioNombre){
         strcpy(nombreSector, "Sin definir");
     }
    printf("   %d   %10s     %c     %.2f     %02d/%02d/%4d    %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;
    system("cls");
    printf(" Legajo      Nombre     Sexo    Sueldo     FechaIngreso   Sector\n");
    printf(" ------      ------     ----    ------     ------------   ------\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    printf("\n\n");
    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{
    int todoOk = 0;
    for(int i=0; i < tam; i++)    {
        if(idSector == sectores[i].id)
        {
            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;
         for(int i= 0; i<tam; i++)
         {
             if(vec[i].ocupado == 0)
             {
                 indice = i;
                 break;
             }
         }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    system("cls");
    for(int i=0; i < tamSec; i++)
    {
        printf("Sector: %s\n\n", sectores[i].descripcion);
        for(int j=0; j < tam; j++)
        {
            if( empleados[j].idSector == sectores[i].id && empleados[j].ocupado== 1)
            {
                mostrarEmpleado(sectores, tamSec, empleados[j]);
            }
        }
        printf("\n\n");

    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int contador;
    for(int i=0; i < tamSec; i++)
    {
        contador = 0;
        printf("Sector: %s\n\n", sectores[i].descripcion);
        for(int j=0; j < tam; j++)
        {
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1){
                contador++;
            }
        }
        printf("Cantidad: %d\n\n", contador);
    }
}

void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
int totales[tamSec];
int mayor;
int flag = 0;
    for(int i=0; i < tamSec; i++)
    {
        totales[i] = 0;
        for(int j=0; j < tam; j++)
        {
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1)
            {
                totales[i]++;
            }
        }
    }
     for(int i=0; i < tamSec; i++)
     {
            if( flag == 0 || mayor < totales[i]){
                mayor = totales[i];
                flag = 1;
            }
     }
     printf("Cantidad mayor de empleados %d\n", mayor);
     printf("En el o los siguientes sectores:\n");
     for(int i=0; i < tamSec; i++){
            if( totales[i] == mayor)
            {
                printf("%s\n", sectores[i].descripcion);
            }
      }
}

void mostrarSectores( eSector sectores[], int tam)
{
    printf("\n    Sectores\n");
    printf(" id     descripcion\n\n");
    for(int i=0; i < tam; i++){
        printf("  %d      %10s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\n\n");
}

void empleadoMayorSueldoXSector( eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
float sueldoMayor[tamSec];
int flag;
    for(int i=0; i < tamSec; i++)
    {
        sueldoMayor[i] = 0;
        flag = 0;
        for(int j=0; j < tam; j++){
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1)
            {
                if(flag == 0 || sueldoMayor[i] < empleados[j].sueldo)
                {
                    sueldoMayor[i] = empleados[j].sueldo;
                    flag = 1;
                }
            }
        }
    }

     for(int i=0; i < tamSec; i++)
     {
            printf("Sector: %s\n\n", sectores[i].descripcion);
            for(int j=0; j<tam; j++)
            {
                if(sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1 && sueldoMayor[i] == empleados[j].sueldo)
                {
                    mostrarEmpleado(sectores, tamSec, empleados[j]);
                }
            }
            printf("\n\n");
     }
}

void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida comidas[], int tamComida, eEmpleado empleados[], int tam)
{
    char auxComida[20];
    char auxNombre[20];
    int consigioComida = 0;
    int consigioNombre = 0;

        for(int i=0; i<tamComida; i++)
        {
            if(unAlmuerzo.idComida == comidas[i].id)
            {
                strcpy(auxComida, comidas[i].descripcion);
                consigioComida = 1;
                break;
            }
        }
        for(int j=0; j<tam; j++)
        {
            if(empleados[j].ocupado == 1 && unAlmuerzo.idEmpleado == empleados[j].legajo)
            {
                strcpy(auxNombre, empleados[j].nombre);
                consigioNombre = 1;
                break;
            }
        }
        if(!consigioComida || !consigioNombre)
        {
             printf("No se pudo mostrar almuerzo.\n");
        }
        else
        {
             printf("%d     %10s     %10s     %d/%d/%d\n", unAlmuerzo.id, auxNombre, auxComida, unAlmuerzo.fechaAlmuerzo.dia, unAlmuerzo.fechaAlmuerzo.mes, unAlmuerzo.fechaAlmuerzo.anio);
        }
}
void mostrarAlmuerzos(eAlmuerzo almuerzo[], int tamAlmuerzo, eComida comida[], int tamComida, eEmpleado empleados[], int tam)
{
    system("cls");
     printf("ID-COMIDA    NOMBRE    COMIDA     FECHA\n");
     printf("--------     ------    ------     -----\n");
     for(int i = 0; i<tamAlmuerzo; i++)
     {
         mostrarAlmuerzo(almuerzo[i], comida, tamComida, empleados, tam);
     }
}

void mostrarAlmuerzoFecha(eAlmuerzo almuerzo[], int tamAlmuerzo, eComida comida[], int tamComida, eEmpleado empleados[], int tam)
{
    eFecha auxFecha;
    int flag = 0;
        printf("Ingrese fecha: ");
        scanf("%d %d %d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
        printf("\n");
        printf("%d/%d/%d\n\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);
            for(int i=0; i<tamAlmuerzo; i++)
            {
                if(compararFechas (almuerzo[i].fechaAlmuerzo, auxFecha))
                {
                    mostrarAlmuerzo(almuerzo[i], comida, tamComida, empleados, tam);
                    flag = 1;
                }
            }
            if(!flag)
            {
                printf("No hay almuerzo en la fecha indicada\n\n");
            }
}

int compararFechas (eFecha fecha1, eFecha fecha2)
{
    int todoOK = 0;
    if(fecha1.dia == fecha2.dia && fecha1.mes == fecha2.mes && fecha1.anio == fecha2.anio)
        todoOK = 1;
    return todoOK;
}

void mostrarAlmuerzoXSector (eAlmuerzo almuerzos[], int tamAlmuerzo, eComida comidas[], int tamComida, eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    mostrarSectores(sectores, tamSec);
    char desc[20];
    int consiguioSector;
    int idSector;
    idSector = getInt("Ingrese un sector: ");
    system("cls");
    consiguioSector = obtenerSector(sectores, tamSec, idSector, desc);
    if(consiguioSector)
    {
      printf("---%s---\n", desc);
      for (int i=0; i<tam; i++)
      {
          if(idSector == empleados[i].idSector && empleados[i].ocupado == 1)
          {
              for (int j=0; j<tamAlmuerzo; j++)
              {
                  if(empleados[i].legajo == almuerzos[j].idEmpleado)
                  {
                      mostrarAlmuerzo(almuerzos[j], comidas, tamComida, empleados, tam);
                  }
              }
          }
      }
    }
    else
    {
        printf("El sector no se encuentra en el sistema.");
    }
}


int altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int auxiliarLegajo;
    int auxiliarDia;
    int auxiliarMes;
    int auxiliarAnio;
    int auxiliarSector;
    float auxiliarSueldo;
    char auxSexo;
    char auxSector[10];
    char auxLegajo[20];
    char auxNombre[20];
    char auxSueldo[20];
    char auxDia[10];
    char auxMes[10];
    char auxAnio[10];
    indice = buscarLibre(vec, tam);
    if(indice == -1)
    {
        printf("No hay lugar en el sistema.\n\n");
        return 0;
    }
    if(!getStringLetras("Ingrese el nombre: ", auxNombre))
    {
        printf("Ingrese solo letras!!\n\n");
        return 0;
    }
    auxSexo = tolower(getChar("Ingrese su sexo F/M: "));
    if(auxSexo != 'f' && auxSexo != 'm')
    {
        printf("Error al ingresar sexo.\n\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese el numero de legajo: ", auxLegajo))
    {
        printf("Ingrese solo numeros!!\n\n");
        return 0;
    }
    auxiliarLegajo = atoi(auxLegajo);
    if(buscarEmpleado(vec, tam, auxiliarLegajo) != -1)
    {
        printf("El legajo ya existe!!\n\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese el sueldo: ", auxSueldo))
    {
        printf("Ingrese solo numeros!!\n\n");
        return 0;
    }
    auxiliarSueldo = atof(auxSueldo);
    if(!getStringNumeros("Ingrese dia: ", auxDia))
    {
        printf("Ingrese solo numeros!!\n\n");
        return 0;
    }
    auxiliarDia = atoi(auxDia);
    if(auxiliarDia < 0 || auxiliarDia > 31)
    {
        printf("Dia invalido!!\n\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese mes: ", auxMes))
    {
        printf("Ingrese solo numeros!!\n\n");
        return 0;
    }
    auxiliarMes = atoi(auxMes);
    if(auxiliarMes < 0 || auxiliarMes > 12)
    {
        printf("Mes invalido!!\n\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese anio: ", auxAnio))
    {
        printf("Ingrese solo numeros!!\n\n");
        return 0;
    }
    auxiliarAnio = atoi(auxAnio);
    if(auxiliarAnio < 0)
    {
        printf("Anio invalido!!\n\n");
        return 0;
    }
    mostrarSectores(sectores, tamSector);
    if(!getStringNumeros("Ingrese un sector: ", auxSector))
    {
        printf("Ingrese solo numeros");
        return 0;
    }
    auxiliarSector = atoi(auxSector);
    if(auxiliarSector < 0 || auxiliarSector > 5)
    {
        printf("El sector ingresado es invalido.\n\n");
        return 0;
    }
    vec[indice].legajo = auxiliarLegajo;
    strcpy(vec[indice].nombre, auxNombre);
    vec[indice].sueldo = auxiliarSueldo;
    vec[indice].sexo = auxSexo;
    vec[indice].idSector = auxiliarSector;
    vec[indice].fechaIngreso.dia = auxiliarDia;
    vec[indice].fechaIngreso.mes = auxiliarMes;
    vec[indice].fechaIngreso.anio = auxiliarAnio;
    vec[indice].ocupado = 1;
    return 1;
}
