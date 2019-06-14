#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "Employee.h"
#include "disconsi.h"

/** \brief Carga el id de un empleado
 * \param this Puntero employee a cargar
 * \param id Entero ID que se va a guardar
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */


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

/** \brief Obtiene el id de un empleado
 * \param this Puntero employee
 * \param id Puntero a entero donde se va a guardar
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */


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

/** \brief Carga el nombre de un empleado
 * \param this Puntero employee
 * \param nombre Puntero a char
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */

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

/** \brief Obtiene el nombre de un empleado
 * \param this Puntero employee
 * \param nombre Puntero a char
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */

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

/** \brief Carga el HorasTrabajadas de un empleado
 * \param this Puntero employee
 * \param horasTrabajadas Entero
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */

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

/** \brief Obtiene el HorasTrabajadas de un empleado
 * \param this Puntero employee
 * \param horasTrabajadas Puntero a entero
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */

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

/** \brief Carga el sueldo de un empleado
 * \param this Puntero employee
 * \param sueldo Entero
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */

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

/** \brief Obtiene el sueldo de un empleado
 * \param this Puntero employee
 * \param sueldo Puntero a entero
 * \return retorna 1 si tuvo exito 0 si no lo tuvo
 */

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

/** \brief Guarda espacio en memoria dinamica para un empleado y lo inicializa en 0
 * \param void
 * \return retorna un puntero a Employee si tuvo exito y NULL si no lo tuvo
 */


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

/** \brief Guarda espacio en memoria dinamica para un empleado y lo inicializa con los parametros pasados
 * \param idStr Puntero a char
 * \param nombreStr Puntero a char
 * \param horasTrabajadasStr Puntero a char
 * \param sueldoStr Puntero a char
 * \return retorna un puntero a Employee si tuvo exito y NULL si no lo tuvo
 */

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

/** \brief Muestra un empleado
 * \param empleado Puntero a Employee
 * \return retorna 0 si es NULL y 1 si tuvo exito.
 */


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

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList*
 * \param size Entero tamaño de la linkedlist
 * \return int 0 si el size es negativo, 0 o si la linkedlist es NULL y 1 si tuvo exito.
 */

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

/** \brief Ordenar 2 empleados por sueldo
 * \param emp1 Puntero a void
 * \param emp2 Puntero a void
 * \return 1 si el primero es mayor -1 si el primero es menor 0 si son iguales.
 */

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

/** \brief Ordena 2 empleados por horas
 * \param emp1 Puntero a void
 * \param emp2 Puntero a void
 * \return 1 si el primero es mayor -1 si el primero es menor 0 si son iguales.
 */

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

/** \brief Ordena 2 empleados por nombre
 * \param emp1 Puntero a void
 * \param emp2 Puntero a void
 * \return 1 si el primero es mayor -1 si el primero es menor 0 si son iguales.
 */

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

/** \brief Ordena 2 empleados por id
 * \param emp1 Puntero a void
 * \param emp2 Puntero a void
 * \return 1 si el primero es mayor -1 si el primero es menor 0 si son iguales.
 */

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

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList*
  * \param id Puntero a id para que sea autoincremental
 * \return retorna 0 si hubo algun problema y 1 si el alta fue exitosa.
 *
 */


int altaEmployee(LinkedList* pArrayListEmployee, int* id)
{
    char idAux[11];
    char nombre[21];
    char horasTrabajadas[11];
    char sueldo[11];
    int todoOk = 0;
    Employee* emp;
    if(pArrayListEmployee != NULL)
    {
       /* if(!getStringNumeros("Ingrese el id: ", id))
        {
            printf("Ingrese solo numeros!!\n");
            return todoOk;
        }
        if(atoi(id) < 1000)             //Comente esto ya que hice el ID autoincremental. Me parecia mas practico ya que en el TP dice que va dirigido a una "empresa"
        {
            printf("Ingrese un ID valido\n");
            return todoOk;
        }*/
        sprintf(idAux, "%d", *id);
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
        emp = employee_newParametros(idAux, nombre, horasTrabajadas, sueldo);
        if(emp != NULL)
        {
            if(ll_add(pArrayListEmployee, emp)== 0)
                todoOk = 1;
        }
        *id = *id +1;
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

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

/** \brief Recibe por parametro e id y lo busca en la linkedlist
 * \param pArrayListEmployee Puntero a linkedlist
 * \param id Entero
 * \return retorna -1 si no lo encuentra y sino retorna el indice
 */



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

/** \brief Baja empleado
 * \param pArrayListEmployee Puntero a linkedlist
 * \return 0 si hubo un problema 1 si no lo hay.
 *
 */


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

/** \brief Ordenar los empleados de la linkedlist
 * \param pArrayListEmployee Puntero a linkedlist
 * \return retorna 0 si hubo algun problema y 1 si no lo hay.
 */


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
