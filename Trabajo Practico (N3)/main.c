#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    system("color 0F");
    int option;
    int validateReturn;

    int validateOpenText = 1;
    int validateSaveText = 0;

    int validateOpenBin = 1;
    int validateSaveBin = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    controller_firstMessage();

    system("pause");
    system("cls");


    do
    {
        system("color 0F");
        printf("===================================================================\n");
        printf("===================================================================\n");
        printf("== (1) LOAD EMPLOYEES DATA FROM data.csv (TEXT).                 ==\n");
        printf("== (2) LOAD EMPLOYEES DATA FROM data.bin (BINARY).               ==\n");
        printf("== (3) ADD NEW EMPLOYEE.                                         ==\n");
        printf("== (4) EDIT EMPLOYEE.                                            ==\n");
        printf("== (5) REMOVE EMPOLYEE.                                          ==\n");
        printf("== (6) LIST EMPLOYEES.                                           ==\n");
        printf("== (7) SORT EMPLOYEES.                                           ==\n");
        printf("== (8) SAVE EMPLOYEES DATA TO data.csv (TEXT).                   ==\n");
        printf("== (9) SAVE EMPLOYEES DATA TO data.csv (BINARY).                 ==\n");
        printf("== (10) EXIT.                                                    ==\n");
        printf("===================================================================\n");
        printf("===================================================================\n\n");

        printf("\nSelect your option: ");
        scanf("%d", &option);


        switch(option)
        {
        case 1:
            if (validateOpenText == 1)
            {
                validateReturn = controller_loadFromText("data.csv",listaEmpleados);
                if (validateReturn == 1)
                {
                    printf("\n*************** File open!\n\n");
                }
                else
                {
                    printf("\nError while trying to open file!\n\n");
                }

            }
            else
            {
                system("cls");
                system("color 02");
                printf("\nYou've already open the file! You'll bug it (TEXT)!!\n\n");
            }
            validateSaveText = 1;
            validateOpenText++;
            break;

        case 2:
            if (validateOpenBin == 1)
            {

                validateReturn = controller_loadFromBinary("data.bin",listaEmpleados);
                if (validateReturn == 1)
                {
                    printf("\n*************** File open!\n\n");
                }
                else
                {
                    printf("\nError while trying to open file!\n\n");
                }
            }
            else
            {
                system("cls");
                system("color 02");
                printf("\nYou've already open the file! You'll bug it (BIN)!!\n\n");
            }
            validateSaveBin = 1;
            validateOpenBin++;
            break;

        case 3:
            validateReturn = controller_addEmployee(listaEmpleados);
            if(validateReturn == 0)
            {
                system("cls");
                system("color 02");
                printf("\nThe employee has been added!\n\n");
            }
            else
            {
                printf("\nThe employee hasn't been added!\n\n");
            }
            break;


        case 4:
            controller_ListEmployee(listaEmpleados);
            validateReturn = controller_editEmployee(listaEmpleados);
            if (validateReturn == -1)
            {
                system("cls");
                system("color 04");
                printf("\n*************** The ID doesn't exist.\n\n");
            }
            else
            {
                system("cls");
                system("color 02");
                printf("\n*************** Employee has been modify!\n\n");
            }
            break;

        case 5:
            controller_ListEmployee(listaEmpleados);
            validateReturn = controller_removeEmployee(listaEmpleados);
            if (validateReturn == -1)
            {
                system("cls");
                system("color 04");
                printf("\n*************** The ID doesn't exist.\n\n");
            }
            else if (validateReturn == -2)
            {
                system("cls");
                system("color 04");
                printf("\n*************** You have cancel the remove.\n\n");
            }
            else
            {
                system("cls");
                system("color 02");
                printf("\n*************** Employee removed!\n\n");
            }
            break;

        case 6:
            validateReturn = controller_ListEmployee(listaEmpleados);
            if (validateReturn == -1)
            {
                printf("\n*************** The list doesn't exist.\n\n");
            }
            else
            {
                printf("\n*************** The list is here!\n\n");
            }
            break;

        case 7:
            validateReturn = controller_sortEmployee(listaEmpleados);
            if (validateReturn == -1)
            {
                printf("\n*************** The list doesn't exist.\n\n");
            }
            else
            {
                printf("\n*************** The list is sorted!\n\n");
            }
            break;

        case 8:
            if (validateSaveText == 1)
            {
                validateReturn = controller_saveAsText("data.csv",listaEmpleados);
                if(validateReturn == 0)
                {
                    printf("\n*************** File has been saved.\n\n");
                }
                else
                {
                    printf("\n*************** File has not been saved\n\n");
                }
            }
            else
            {
                system("cls");
                system("color 04");
                printf("\nYou first need to open the file (TEXT)!!\n\n");
            }

            break;

        case 9:
            if (validateSaveBin == 1)
            {
                validateReturn = controller_saveAsBinary("data.bin",listaEmpleados);
                if(validateReturn == 0)
                {
                    printf("\n*************** File has been saved.\n\n");
                }
                else
                {
                    printf("\n*************** File has not been saved\n\n");
                }
            }
            else
            {
                system("cls");
                system("color 04");
                printf("\nYou first need to open the file (BIN)!!\n\n");
            }
            break;

        case 10:
            option=10;
            printf("\nExit...\n\n");
            break;

        default:
            printf("You've put a wrong option. Please, try again: ");
        }

        system("pause");
        system("cls");
    }
    while(option != 10);

    return 0;
}
