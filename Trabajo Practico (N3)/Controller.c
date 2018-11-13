#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "GetOnly.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;

    if (pArchivo!=NULL)
    {
        pArchivo=fopen(path, "r");
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        retorno = 1;
    }

    fclose(pArchivo);

    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    FILE* pArchivo;

    if (pArchivo != NULL)
    {
       pArchivo = fopen(path, "rb");
       parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
       retorno = 1;
    }

    fclose(pArchivo);
    return retorno;
}


int controller_nextID(LinkedList* pArrayListEmployee)
    {
        int id = 0;
        int idAnterior;
        int intAuxiliar;
        Employee* pEmployee;
        int listLen;
        int i;

        if(pArrayListEmployee != NULL)
        {
            listLen = ll_len(pArrayListEmployee);
                if(listLen > 0)
                {
                    for(i = 0; i<listLen; i++)
                        {
                            pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
                            employee_getId(pEmployee,&intAuxiliar);
                            if(intAuxiliar > id)
                            {
                                idAnterior = id;
                                id = intAuxiliar;
                                    if(idAnterior + 1 != id)
                                    {
                                        id = idAnterior;
                                        break;
                                    }
                            }
                        }
                    id++;

                }
            else
            {
                id = 1;
            }
        }
        return id;
    }




int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int retorno = -1;

    int idAuxiliar;

    char nombreChar[50];

    char sueldoChar[50];
    int sueldoCharAuxiliar;

    char horasChar[50];
    int horasCharAuxiliar;

    pEmpleado = employee_new();

    if(pArrayListEmployee != NULL)
    {

        idAuxiliar = controller_nextID(pArrayListEmployee);

        printf("Insert new name: ");
                    fflush(stdin);
                    gets(nombreChar);

                    while(isOnlyLetters(nombreChar)==0)
                    {
                        printf("You've put a wrong name. Please, try again: ");
                        fflush(stdin);
                        gets(nombreChar);
                    }
                    stringToUpper(nombreChar);


       printf("Ingrese new salary: ");
                    fflush(stdin);
                    gets(sueldoChar);

                    while(isNumeric(sueldoChar)==0)
                    {
                        printf("You've put a wrong salary. Please, try again: ");
                        fflush(stdin);
                        gets(sueldoChar);
                    }
                    sueldoCharAuxiliar= atoi(sueldoChar);


       printf("Insert the work hours: ");
                    fflush(stdin);
                    gets(horasChar);

                    while(isNumeric(horasChar)==0)
                    {
                        printf("You've put a wrong work hours. Please, try again: ");
                        fflush(stdin);
                        gets(horasChar);
                    }

                    horasCharAuxiliar= atoi(horasChar);

        if(pEmpleado != NULL)
        {
            employee_setId(pEmpleado, idAuxiliar);
            employee_setNombre(pEmpleado, nombreChar);
            employee_setSueldo(pEmpleado, sueldoCharAuxiliar);
            employee_setHorasTrabajadas(pEmpleado, horasCharAuxiliar);
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;

    int retorno = -1;
    int i;

    char idChar[10];
    int idCharAuxiliar;
    int idObtenido;

    char opcionChar[50];
    int opcionCharAuxiliar;

    char nombreChar[50];

    char sueldoChar[50];
    int sueldoCharAuxiliar;

    char horasChar[50];
    int horasCharAuxiliar;

    if(pArrayListEmployee != NULL)
    {
        printf("Insert the ID: ");
        fflush(stdin);
        gets(idChar);

        while(isNumeric(idChar)==0)
        {
            printf("You've put a wrong ID. Please, try again: ");
            fflush(stdin);
            gets(idChar);
        }
        idCharAuxiliar=atoi(idChar);

        for(i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&idObtenido);

            if(idObtenido == idCharAuxiliar)
            {
                printf("===========================================\n");
                printf("What do you want to edit? \n 1) Name \n 2) Salary \n 3) Work Hours.\n");
                printf("===========================================\n\n");

                printf("\nSelect your option: ");
                fflush(stdin);
                gets(opcionChar);

                while(isNumeric(opcionChar)==0)
                {
                    printf("You've put a wrong option. Please, try again: ");
                    fflush(stdin);
                    gets(opcionChar);
                }
                opcionCharAuxiliar=atoi(opcionChar);

                switch(opcionCharAuxiliar)
                {
                case 1:
                    printf("Insert new name: ");
                    fflush(stdin);
                    gets(nombreChar);

                    while(isOnlyLetters(nombreChar)==0)
                    {
                        printf("You've put a wrong name. Please, try again: ");
                        fflush(stdin);
                        gets(nombreChar);
                    }

                    stringToUpper(nombreChar);
                    retorno = 0;
                    employee_setNombre(empleado, nombreChar);
                    break;

                case 2:
                    printf("Insert new salary: ");
                    fflush(stdin);
                    gets(sueldoChar);

                    while(isNumeric(sueldoChar)==0)
                    {
                        printf("You've put a wrong salary. Please, try again: ");
                        fflush(stdin);
                        gets(sueldoChar);
                    }

                    sueldoCharAuxiliar= atoi(sueldoChar);
                    retorno = 0;
                    employee_setSueldo(empleado, sueldoCharAuxiliar);
                    break;

                case 3:
                    printf("Insert new work hours: ");
                    fflush(stdin);
                    gets(horasChar);

                    while(isNumeric(horasChar)==0)
                    {
                        printf("You've put a wrong work hours. Please, try again: ");
                        fflush(stdin);
                        gets(horasChar);
                    }

                    horasCharAuxiliar= atoi(horasChar);
                    retorno = 0;
                    employee_setHorasTrabajadas(empleado, horasCharAuxiliar);
                    break;

                default:
                    printf("You've put a wrong option. Please, try again: ");
                }
            }
        }
    }


    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char idChar[10];
    int retorno = -1;
    int i;
    int contador = 0;
    int idCharAuxiliar;
    int idObtenido;
    int opcionAConfirmar;

    Employee* pEmployee;

    if(pArrayListEmployee != NULL)
    {
        printf("Insert the ID: ");
        fflush(stdin);
        gets(idChar);

        while(isNumeric(idChar)==0)
        {

            printf("You've put a wrong ID. Please, try again: ");
            fflush(stdin);
            gets(idChar);
        }

        idCharAuxiliar=atoi(idChar);

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee, &idObtenido);

            if(idObtenido == idCharAuxiliar)
            {

                contador++;

                if (contador == 1)
                {
                printf("\nAre you sure you want to remove employee? (1 CONFIRMATION)\n");
                printf("1) YES!\n");
                printf("2) NO!\n");
                scanf("%d",&opcionAConfirmar);
                }
                else
                {
                printf("\nAre you sure you want to remove employee? (2 CONFIRMATION)\n");
                printf("1) YES!\n");
                printf("2) NO!\n");
                scanf("%d",&opcionAConfirmar);
                }

                switch(opcionAConfirmar)
                {

                case 1:
                employee_delete(pEmployee);
                ll_remove(pArrayListEmployee,i);
                retorno = 0;
                break;

                case 2:
                retorno = -2;
                break;

                default:
                printf("You've put a wrong option. Please, try again: ");
                retorno = -2;
                break;
                }

            }
        }
    }

    contador = 0;
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;

    char nombre[50];
    int id;
    int sueldo;
    int horasTrabajadas;

    Employee* pEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        printf("\n\nID-- \t\t   NAME \t\t SALARY \t\tHOURS \n\n");

        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getNombre(pEmpleado, nombre);
            employee_getId(pEmpleado,&id);
            employee_getSueldo(pEmpleado,&sueldo);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
            printf("------------------------------------------------------------------------\n");
            printf("%d -- %20s %20d %20d \n", id, nombre, sueldo, horasTrabajadas);
        }
    }
    return retorno;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        employee_sortEmployee(pArrayListEmployee);
        retorno = 0;
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pArchivo;
    Employee* empleadoAux;

    int retorno = -1;
    int i;

    int* auxiliarID;
    char* auxiliarNombre;
    int* auxiliarSalario;
    int* auxiliarHoras;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        retorno = 1;
        auxiliarID = malloc(sizeof(int));
        auxiliarNombre = malloc(sizeof(char)*100);
        auxiliarSalario = malloc(sizeof(int));
        auxiliarHoras = malloc(sizeof(int));

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = ll_get(pArrayListEmployee,i);
            employee_getId(empleadoAux,auxiliarID);
            employee_getSueldo(empleadoAux,auxiliarSalario);
            employee_getNombre(empleadoAux, auxiliarNombre);
            employee_getHorasTrabajadas(empleadoAux,auxiliarHoras);
            fprintf(pArchivo,"%d,%s,%d,%d\n",*auxiliarID,auxiliarNombre,*auxiliarSalario,*auxiliarHoras);
        }

        free(auxiliarNombre); free(auxiliarID); free(auxiliarSalario); free(auxiliarHoras);
        fclose(pArchivo);
    }
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pArchivo;
    Employee* empleadoAux;

    int retorno = -1;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        retorno = 1;
        pArchivo = fopen(path,"wb");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(empleadoAux, sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
    }
    return retorno;
}



void controller_firstMessage (void)
{
    printf("*********************************************************************************\n");
    printf("******************************** READ BEFORE USE ********************************\n");
    printf("******** YOU SHOULD LOAD THE LIST BEFORE USE THE LINKED LIST. IF YOU DONT *******\n");
    printf("********  THE LIST WILL BE REMPLACED AND YOU'LL LOSE ALL 1000 EMPLOYEES *********\n");
    printf("*********************************************************************************\n\n\n");

    printf("*********************************************************************************\n");
    printf("*************** THIS CODE HAS BEEN MADE FOR WINDOWS 10 (64 BITS) ****************\n");
    printf("*********************************************************************************\n\n\n");
}
