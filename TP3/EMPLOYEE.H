#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_delete(LinkedList* pArrayListEmployee);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int mostrarEmpleado(Employee* empleado);
int mostrarEmpleados(LinkedList* empleados, int size);
int ordenarXSueldo(void* emp1, void* emp2);
int altaEmployee(LinkedList* pArrayListEmployee);
int buscarXId(LinkedList* pArrayListEmployee, int id);
int ordenarEmpleados(LinkedList* pArrayListEmployee);
int modificarEmployee(LinkedList* pArrayListEmployee);

#endif // employee_H_INCLUDED
