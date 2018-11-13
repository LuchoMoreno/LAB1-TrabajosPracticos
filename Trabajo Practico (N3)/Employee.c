#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


Employee* employee_new()
{
    Employee* newEmployee;

    newEmployee = (Employee*)malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;
}


Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int auxiliarId;
    int auxiliarHoras;
    int auxiliarSueldo;

    auxiliarId= atoi(idStr);
    auxiliarHoras= atoi(horasTrabajadasStr);
    auxiliarSueldo= atoi(sueldoStr);


    if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setNombre(newEmployee, nombreStr);
        employee_setId(newEmployee, auxiliarId);
        employee_setHorasTrabajadas(newEmployee, auxiliarHoras);
        employee_setSueldo(newEmployee, auxiliarSueldo);
    }
    return newEmployee;
}



void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}


int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if (this!=NULL && id !=NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 0;
        }
    }
    return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo = sueldo;
        retorno=0;
    }
    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


int employee_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
                printf("\n===========================================\n");
                printf("How do you want to order? \n 1) By Name \n 2) By Salary \n 3) By work hours.\n");
                printf("===========================================\n\n");

                printf("\nSelect your option: ");
                scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    printf("\n*************** PLEASE - Wait a moment.\n\n");
                    printf("\n*************** THIS CAN TAKE 1-2 MINUTES.\n\n");
                    ll_sort(pArrayListEmployee, employee_ordenarPorNombre, 1);
                    break;
                case 2:
                    printf("\n*************** PLEASE - Wait a moment.\n\n");
                    printf("\n*************** THIS CAN TAKE 1-2 MINUTES.\n\n");
                    ll_sort(pArrayListEmployee, employee_ordenarPorSueldo, 1);
                    break;
                case 3:
                    printf("\n*************** PLEASE - Wait a moment.\n\n");
                    printf("\n*************** THIS CAN TAKE 1-2 MINUTES.\n\n");
                    ll_sort(pArrayListEmployee, employee_ordenarPorHoras, 1);
                    break;
                default:
                    printf("\nOpcion invalida!");
            }

        retorno = 0;
    }

    return retorno;
}



int employee_ordenarPorSueldo(void* variableA, void* variableB)
{
    int sueldoA;
    int sueldoB;
    int retorno = 0;

    employee_getSueldo(variableA, &sueldoA);
    employee_getSueldo(variableB, &sueldoB);

    if(sueldoA > sueldoB)
    {
        retorno = 1;
    }
    else if(sueldoA < sueldoB)
    {
        retorno = -1;
    }

    return retorno;
}


int employee_ordenarPorNombre(void* variableA, void* variableB)
{
    char nombreA[50];
    char nombreB[50];
    int retorno = 0;

    employee_getNombre(variableA, nombreA);
    employee_getNombre(variableB, nombreB);

    if(strcmp(nombreA, nombreB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA, nombreB) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_ordenarPorHoras(void* variableA, void* variableB)
{
    int horasA;
    int horasB;
    int retorno = 0;

    employee_getHorasTrabajadas(variableA, &horasA);
    employee_getHorasTrabajadas(variableB, &horasB);

    if(horasA > horasB)
    {
        retorno = 1;
    }
    else if(horasA < horasB)
    {
        retorno = -1;
    }

    return retorno;
}
