#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"

#define A 6

int main()
{
    int comprobarInicializacion;
    int comprobarIngreso;
    int comprobarBaja;
    int comprobarModificacion;

    Employee listaEmployees[A];

    comprobarInicializacion = initEmployees(listaEmployees, A);
    if (comprobarInicializacion == 0)
    {
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("Todos los estados se han inicializado.");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    }
    else
    {
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("Ha ocurrido un error al inicializar estados.\n\n\n");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    }

    inicializarEmployeesConDatos(listaEmployees, A);


    system("pause");
    system("cls");

    char opcion;

    do
    {
        system("color 02"); // AÑADE COLOR A LA CONSOLA.
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("SOLO SE TOMARA EL PRIMER DIGITO COMO OPCION.\n");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("(1) CARGAR EMPLEADO. \n");
        printf("(2) MODIFICAR EMPLEADO. \n");
        printf("(3) BAJA DE EMPLEADO. \n");
        printf("(4) LISTA DE EMPLEADOS. \n");
        printf("(5) LISTA DE EMPLEADOS (ORDENADA). \n");
        printf("(6) PROMEDIO SALARIAL. \n");
        printf("(7) Salir\n");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");


        printf("Debe elegir una opcion a realizar: ");
        fflush(stdin);
        scanf("%c", &opcion);

        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6' && opcion!='7')
        {
            printf("Error. Ha ingresado una opcion erronea!\n\n");
            printf("Debe elegir una opcion a realizar: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }

        switch (opcion)
        {
        case '1':
            comprobarIngreso = addEmployeesModificado(listaEmployees, A);
            if (comprobarIngreso == 0)
            {
                printf("\n\nEl empleado ha sido dado de alta!\n\n");
            }
            else
            {
                system("cls");
                system("color 04");
                printf("\nNo quedan espacios libres!\n\n");
            }
            break;


        case '2':
            comprobarModificacion = modificacionDeEmpleado(listaEmployees, A);

            if (comprobarModificacion == -2)
            {
                system("cls");
                system("color 04");
                printf("\nNo se ha encontrado ningun usuario con esa ID!\n\n");
            }
            else if (comprobarModificacion == -3)
            {
                printf("\nError. Se ha ingresado una opcion invalida.\n");
            }

            break;


        case '3':
            comprobarBaja = removeEmployee(listaEmployees, A, 5);
            if (comprobarBaja == 0)
            {
                printf("\n\nEl empleado ha sido dado de baja!\n\n");
            }
            else if (comprobarBaja == -2)
            {
                printf("\n\nSe ha cancelado la baja!\n\n");
            }
            else
            {
                system("cls");
                system("color 04");
                printf("\nNo se ha encontrado ningun usuario con esa ID!\n\n");
            }
            break;


        case '4':
            printEmployees(listaEmployees, A);
            break;


        case '5':
            sortEmployees(listaEmployees, A, 0);
            printEmployees(listaEmployees, A);
            break;

        case '6':

            break;


        case '7':
            opcion = '7';
            printf("\n\nUsted ha finalizado el programa!\n\n\n");
            break;

        default:
            printf("Error. Ha ingresado una opcion erronea!\n\n");
        }

        system("pause");
        system("cls");


    }
    while (opcion!='7');
                system("cls");
                system("color 04");
    printf("====================================================\n");
    printf("Finalizacion!\n");
    printf("====================================================\n");
    return 0;
}


