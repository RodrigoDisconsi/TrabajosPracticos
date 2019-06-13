#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "Employee.h"
#include "disconsi.h"

int employee_setId(Employee* this,int id)
{
     int todoOK = 0;
     if(this != NULL && id>0)
     {
         this->id = id;
         todoOK = 1;
     }
     return todoOK;
}




int employee_getId(Employee* this,int* id)
{
    int todoOK = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOK = 1;
    }
    return todoOK;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOK = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) >= 3)
    {
        strcpy(this->nombre, nombre);
        todoOK = 1;
    }
    return todoOK;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int todoOK = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOK = 1;
    }
    return todoOK;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOK = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOK = 1;
    }
    return todoOK;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOK = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOK = 1;
    }
    return todoOK;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOK = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOK = 1;
    }
    return todoOK;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOK = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOK = 1;
    }
    return todoOK;
}

Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;
        if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
        {
            this = employee_new();
        if(this != NULL)
            if(!(employee_setId(this, atoi(idStr)) && employee_setNombre(this, nombreStr) && employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) && employee_setSueldo(this, atoi(sueldoStr))))
            {
                        free(this);
                        this = NULL;
            }
        }
    return this;
}

int mostrarEmpleado(Employee* empleado)
{
    int isOk = 0;
    if(empleado != NULL)
    {
        printf("      %-4d      %-15s   %-3d         %-6d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        isOk = 1;
    }
    return isOk;
}

int mostrarEmpleados(LinkedList* empleados, int size)
{
    int isOk = 0;
    if(empleados != NULL && size >0 )
    {
        printf("      ID        NOMBRE           HORAS        SUELDO\n");
        printf("      --        ------           -----        ------\n");
        for(int i = 0; i<size; i++)
        {
            mostrarEmpleado(ll_get(empleados, i));
            isOk = 1;
        }
    }
    if(size == 0)
        isOk = -1;

    return isOk;
}


int ordenarXSueldo(void* emp1, void* emp2)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;
    if(emp1 != NULL && emp2 != NULL)
    {
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->sueldo > p2->sueldo)
        {
            retorno = 1;
        }
        else if(p1->sueldo < p2->sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarXHoras( void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL){

            p1 = (Employee*) emp1;
            p2 = (Employee*) emp2;

            if( p1->horasTrabajadas > p2->horasTrabajadas){
                retorno = 1;
            }
            else if( p1->horasTrabajadas < p2->horasTrabajadas){
                retorno = -1;
            }
            else{
                retorno = 0;
            }

    }

    return retorno;
}

int ordenarXNombre( void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL){

            p1 = (Employee*) emp1;
            p2 = (Employee*) emp2;

            if( strcmp(p1->nombre, p2->nombre) > 0){
                retorno = 1;
            }
            else if( strcmp(p1->nombre, p2->nombre) < 0){
                retorno = -1;
            }
            else{
                retorno = 0;
            }

    }

    return retorno;
}

int ordenarXId( void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL){

            p1 = (Employee*) emp1;
            p2 = (Employee*) emp2;

            if( p1->id > p2->id){
                retorno = 1;
            }
            else if( p1->id < p2->id){
                retorno = -1;
            }
            else{
                retorno = 0;
            }

    }

    return retorno;
}


int altaEmployee(LinkedList* pArrayListEmployee)
{
    char id[11];
    char nombre[21];
    char horasTrabajadas[11];
    char sueldo[11];
    int todoOk = 0;
    Employee* emp;
    if(pArrayListEmployee != NULL)
    {
        if(!getStringNumeros("Ingrese el id: ", id))
        {
            printf("Ingrese solo numeros!!\n");
            return todoOk;
        }
        if(atoi(id) < 0)
        {
            printf("Ingrese un ID positivo\n");
            return todoOk;
        }
        if(!getStringLetras("Ingrese nombre: ", nombre))
        {
            printf("Ingrese solo letras!!\n");
            return todoOk;
        }
        nombre[0] = toupper(nombre[0]);
        if(!getStringNumeros("Ingrese las horas trabajadas: ", horasTrabajadas))
        {
            printf("Ingrese solo numeros!!\n");
            return todoOk;
        }
        if(!getStringNumeros("Ingrese el sueldo: ", sueldo))
        {
            printf("Ingrese solo numeros!!\n");
            return todoOk;
        }
        emp = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
        if(emp != NULL)
        {
            if(ll_add(pArrayListEmployee, emp)== 0)
                todoOk = 1;
        }
    }

    return todoOk;
}

int modificarEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp = employee_new();
    int isOk = 0;
    int indice;
    char auxId[11];
    char auxIdMod[11];
    char nombre[21];
    char horasTrabajadas[11];
    char sueldo[11];
    char confirma;
    char seguir = 's';
    if(auxEmp == NULL)
        return isOk;
    if(!getStringNumeros("Ingrese ID: ", auxId))
    {
        printf("Ingrese solo numeros!!\n");
        return isOk;
    }
    if(atoi(auxId) < 0)
    {
        printf("El ID debe ser positivo!!\n");
        return isOk;
    }
    indice = buscarXId(pArrayListEmployee, atoi(auxId));
    if(indice == -1)
    {
        printf("El ID no se encuentra en el sistema!!\n");
        return isOk;
    }
    mostrarEmpleado(ll_get(pArrayListEmployee, indice));
    auxEmp = (Employee*) ll_get(pArrayListEmployee, indice);
    do{
    switch(menuModificar())
    {
        case 1:
            if(!getStringNumeros("Ingrese el nuevo ID:", auxIdMod))
            {
                printf("Ingrese solo numeros!!\n");
                break;
            }
            if(atoi(auxIdMod) < 0)
            {
                printf("Ingrese un ID positivo\n");
                return isOk;
            }
            if(buscarXId(pArrayListEmployee, atoi(auxIdMod)) >= 0)
            {
                printf("El ID ya se encuentra en el sistema!!\n");
                break;
            }
            printf("El nuevo id es: %d. ", atoi(auxIdMod));
            confirma = tolower(getChar(" Confirma? s/n: "));
            if(confirma == 's')
            {
                employee_setId(auxEmp, atoi(auxIdMod));
                ll_set(pArrayListEmployee, indice, (Employee*) auxEmp);
                printf("Modificacion exitosa!!\n");
                isOk = 1;
                seguir = 'n';
                break;
            }
            else{
                printf("Modificacion cancelada!\n");
                seguir = 'n';
            }
            break;
        case 2:
            if(!getStringLetras("Ingrese el nuevo nombre: ", nombre))
            {
                printf("Ingrese solo letras!!\n");
                break;
            }
            printf("El nuevo nombre es: *%s. ");
            confirma = tolower(getChar(" Confirma? s/n: "));
            if(confirma == 's')
            {
                employee_setNombre(auxEmp, nombre);
                ll_set(pArrayListEmployee, indice, (Employee*) auxEmp);
                printf("Modificacion exitosa!!\n");
                isOk = 1;
                seguir = 'n';
                break;
            }
            else{
                printf("Modificacion cancelada!\n");
                seguir = 'n';
            }
            break;
        case 3:
            if(!getStringNumeros("Ingrese las horas trabajadas: ", horasTrabajadas))
            {
                printf("Ingrese solo numeros!!\n");
                break;
            }
            printf("El nuevo horasTrabajadas es: %s. ");
            confirma = tolower(getChar(" Confirma? s/n: "));
            if(confirma == 's')
            {
                employee_setHorasTrabajadas(auxEmp, atoi(horasTrabajadas));
                ll_set(pArrayListEmployee, indice, (Employee*) auxEmp);
                printf("Modificacion exitosa!!\n");
                isOk = 1;
                seguir = 'n';
                break;
            }
            else{
                printf("Modificacion cancelada!\n");
                seguir = 'n';
            }
            break;
        case 4:
            if(!getStringNumeros("Ingrese sueldo: ", sueldo))
            {
                printf("Ingrese solo numeros!!\n");
                break;
            }
            printf("El nuevo sueldo es: %s. ");
            confirma = tolower(getChar(" Confirma? s/n: "));
            if(confirma == 's')
            {
                employee_setSueldo(auxEmp, atoi(sueldo));
                ll_set(pArrayListEmployee, indice, (Employee*) auxEmp);
                printf("Modificacion exitosa!!\n");
                isOk = 1;
                seguir = 'n';
                break;
            }
            else{
                printf("Modificacion cancelada!\n");
                seguir = 'n';
            }
            break;
        case 5:
            seguir = getChar("\nDesea salir s/n?: ");
                if( tolower(seguir) == 's')
                {
                    seguir = 'n';
                }
                system("pause");
                break;

    }
    }while(seguir == 's');
    return isOk;
}


int buscarXId(LinkedList* pArrayListEmployee, int id)
{
    int tam;
    int auxId;
    int indice = -1;
    tam = ll_len(pArrayListEmployee);
    for(int i = 0; i < tam; i++)
    {
        if(employee_getId(ll_get(pArrayListEmployee, i), &auxId))
        {
            if(id == auxId)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int employee_delete(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int indice;
    char confirma;
    char auxId[11];
    if(!getStringNumeros("Ingrese ID: ", auxId))
    {
        printf("Ingrese solo numeros!!\n");
        return isOk;
    }
    if(atoi(auxId) < 0)
    {
        printf("Ingrese un ID positivo\n");
        return isOk;
    }
    indice = buscarXId(pArrayListEmployee, atoi(auxId));
    if(indice == -1)
    {
        printf("El ID no se encuentra en el sistema!\n");
        return isOk;
    }
    mostrarEmpleado(ll_get(pArrayListEmployee, indice));
    confirma = tolower(getChar("Desea dar de baja? s/n: "));
    if(confirma == 's')
    {
        ll_remove(pArrayListEmployee, indice);
        isOk = 1;
        printf("Baja exitosa!!\n");
    }
    else
        printf("Baja cancelada!!\n");
    return isOk;
}

int ordenarEmpleados(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int opcion;
    if(pArrayListEmployee != NULL)
    {
       switch(menuOrdenar())
       {
            case 1:
                opcion = subMenuOrdenar();
                if(opcion == 1)
                    ll_sort(pArrayListEmployee, ordenarXId, 1);
                else if(opcion == 2)
                    ll_sort(pArrayListEmployee, ordenarXId, 0);
                else{
                    printf("Opcion incorrecta.\n");
                    return isOk;
                }
                isOk = 1;
                break;
            case 2:
                opcion = subMenuOrdenar();
                if(opcion == 1)
                    ll_sort(pArrayListEmployee, ordenarXNombre, 1);
                else if(opcion == 2)
                    ll_sort(pArrayListEmployee, ordenarXNombre, 0);
                else{
                    printf("Opcion incorrecta.\n");
                    return isOk;
                }
                isOk = 1;
                break;
            case 3:
                opcion = subMenuOrdenar();
                if(opcion == 1)
                    ll_sort(pArrayListEmployee, ordenarXHoras, 1);
                else if(opcion == 2)
                    ll_sort(pArrayListEmployee, ordenarXHoras, 0);
                else{
                    printf("Opcion incorrecta.\n");
                    return isOk;
                }
                isOk = 1;
                break;
            case 4:
                opcion = subMenuOrdenar();
                if(opcion == 1)
                    ll_sort(pArrayListEmployee, ordenarXSueldo, 1);
                else if(opcion == 2)
                    ll_sort(pArrayListEmployee, ordenarXSueldo, 0);
                else{
                    printf("Opcion incorrecta.\n");
                    return isOk;
                }
                isOk = 1;
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
       }
    }
    return isOk;
}
