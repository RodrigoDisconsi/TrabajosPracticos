#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "disconsi.h"
#include "menu.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    FILE* pFile = fopen(path, "r");
    if(pFile == NULL || path == NULL || pArrayListEmployee == NULL)
        return isOk;
    isOk = parser_EmployeeFromText(pFile, pArrayListEmployee);
    fclose(pFile);

    return isOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    FILE* pFile = fopen(path, "rb");
    if(pFile == NULL || path == NULL || pArrayListEmployee == NULL)
        return isOk;
    isOk = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    fclose(pFile);
    return isOk;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int isOk = 0;
    if(pArrayListEmployee != NULL)
    {
       isOk = altaEmployee(pArrayListEmployee, id);
    }

    return isOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    if(pArrayListEmployee != NULL)
        isOk = modificarEmployee(pArrayListEmployee);
    return isOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    if(pArrayListEmployee != NULL)
        isOk = employee_delete(pArrayListEmployee);
    return isOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    if(pArrayListEmployee != NULL)
        isOk = mostrarEmpleados(pArrayListEmployee, ll_len(pArrayListEmployee));
    return isOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    if(pArrayListEmployee != NULL)
        isOk = ordenarEmpleados(pArrayListEmployee);
    return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    FILE* pFile = fopen(path, "a");
    if(pFile == NULL || path == NULL || pArrayListEmployee == NULL)
        return isOk;
    isOk = parser_saveAsText(pFile, pArrayListEmployee);
    fclose(pFile);
    return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    FILE* pFile = fopen(path, "a");
    if(pFile == NULL || path == NULL || pArrayListEmployee == NULL)
        return isOk;
    isOk = parser_saveAsBinary(pFile, pArrayListEmployee);
    fclose(pFile);
    return isOk;
}

