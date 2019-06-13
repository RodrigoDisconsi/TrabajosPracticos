#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    int cant;
    int isOk = 0;
    char buffer[4][21];
    if(pFile != NULL && pArrayListEmployee != NULL){
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(pFile))
        {
            cant =  fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                if(cant < 4){

                if( feof(pFile))
                    break;
                else{
                    printf("Problemas para leer el archivo\n");
                    break;
                }
                }
                auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(auxEmp != NULL)
                {
                    if(ll_add(pArrayListEmployee, (Employee*) auxEmp) == 0)
                        isOk = 1;
                }

        }
    }
    fclose(pFile);

    return isOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cant;
    int isOk = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            Employee* emp = employee_new();
            if(emp != NULL)
            {
                cant = fread(emp, sizeof(Employee), 1, pFile);
                if(cant<1)
                {
                    if(feof(pFile))
                        break;
                    else
                        printf("Problemas al leer el archivo.\n");
                }
                if(cant)
                {
                    if(ll_add(pArrayListEmployee, (Employee*) emp) == 0)
                        isOk = 1;
                }
            }
        }
        fclose(pFile);
    }
    return isOk;
}

int parser_saveAsBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cant;
    int tam;
    int isOk = 0;
    Employee* auxEmp = employee_new();
    tam = ll_len(pArrayListEmployee);
    if(tam == 0)
        printf("No hay empleados cargados!!\n");
    else
    {
        for(int i = 0; i<tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            cant = fwrite(auxEmp, sizeof(Employee), 1, pFile);
            if(cant < 1)
            {
                printf("Error al guardar el archivo.\n");
                break;
            }
            else
                isOk = 1;
        }

    }
    fclose(pFile);
    return isOk;
}


int parser_saveAsText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int tam;
    int isOk = 0;
    Employee* auxEmp = employee_new();
    tam = ll_len(pArrayListEmployee);
    if(tam == 0)
        printf("No hay empleados cargados!!\n");
    else
    {
        for(int i = 0; i<tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d, %s, %d, %d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
        }
        isOk = 1;

    }
    fclose(pFile);
    return isOk;
}
