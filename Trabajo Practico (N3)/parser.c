#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* pEmployee;

    char auxiliarID[50];
    char auxiliarNombre[50];
    char auxiliarHorasTrabajadas[50];
    char auxiliarSueldo[50];
    int retorno = -1;
    int flagPrimario = 1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

            if(flagPrimario)
            {
                flagPrimario = 0;

                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxiliarID, auxiliarNombre, auxiliarHorasTrabajadas, auxiliarSueldo);
            }

            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxiliarID, auxiliarNombre, auxiliarHorasTrabajadas, auxiliarSueldo);
            printf("%s - %s - %s - %s\n", auxiliarID, auxiliarNombre, auxiliarHorasTrabajadas, auxiliarSueldo);

            pEmployee = employee_newParametros(auxiliarID, auxiliarNombre, auxiliarHorasTrabajadas, auxiliarSueldo);

            if(pEmployee != NULL)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0;
            }
        }
    }

    return retorno;
}



int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee;

    if(pFile != NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            pEmployee = employee_new();
            fread(pEmployee,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee,pEmployee);
        }

    }

    return retorno;
}
