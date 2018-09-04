#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main()
{
    float numeroA = 0;
    float numeroB = 0;

    float resultadoSuma = 0;
    float resultadoResta = 0;
    float resultadoDivision = 0;
    float resultadoMultiplicar = 0;
    float resultadoFactorialA = 0;
    float resultadoFactorialB = 0;

    int estadoDeNumeroA = 0;
    int estadoDeNumeroB = 0;

    char opcion;

    do
    {
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("SOLO SE TOMARA EL PRIMER DIGITO COMO OPCION.\n");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("(1) Ingrese el numero A: (Este quedara guardado): \n");
        printf("(2) Ingrese el numero B: (Este quedara guardado): \n");
        printf("(3) Calcular todas las operaciones: \n");
        printf("(4) Informe de resultados: \n");
        printf("(5) Salir\n");

        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("El numero A es %f: \n", numeroA);
        printf("El numero B es %f: \n\n", numeroB);
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

            printf("Debe elegir una opcion a realizar: ");
            fflush(stdin);
            scanf("%c", &opcion);

            while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5')
            {
                printf("Error. Ha ingresado una opcion erronea!\n\n");
                printf("Debe elegir una opcion a realizar: ");
                fflush(stdin);
                scanf("%c", &opcion);
            }

        switch (opcion)
        {
        case '1':
        numeroA = getFloat("Ingrese el numero A: ");
        estadoDeNumeroA = 1;
            break;

        case '2':
        numeroB = getFloat("Ingrese el numero B: ");
        estadoDeNumeroB = 1;
            break;

        case '3':
        if(estadoDeNumeroA == 0 || estadoDeNumeroB == 0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados\n\n");
                }
        else
                {
                    resultadoSuma = funcionSumar(numeroA, numeroB);

                    resultadoResta = funcionRestar(numeroA, numeroB);

                    resultadoDivision = funcionDividir(numeroA, numeroB);

                    resultadoMultiplicar = funcionMultiplicar(numeroA, numeroB);

                    resultadoFactorialA = funcionFactorial(numeroA);

                    resultadoFactorialB = funcionFactorial(numeroB);

                    if (funcionFactorial(numeroA) == 0)
                        {
                            printf("\nNo se puede realizar el factorial  de un numero negativo (Numero A). \n");
                        }

                    if (funcionFactorial(numeroB) == 0)
                        {
                            printf("\nNo se puede realizar el factorial  de un numero negativo (Numero B). \n");
                        }

                    printf("\nSe han realizado todas las operaciones posibles.\n\n");
                }
            break;

        case '4':
            printf("\nEl resultado de la suma es: %.3f\n", resultadoSuma);
            printf("El resultado de la resta es: %.3f\n", resultadoResta);
            printf("El resultado de la division es: %.3f\n", resultadoDivision);
            printf("El resultado de la multiplicacion es: %.3f\n", resultadoMultiplicar);
            printf("El factorial de A es: %.3f\n", resultadoFactorialA);
            printf("El factorial de B es: %.3f\n\n", resultadoFactorialB);

            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("SE HAN REESTABLECIDO LOS VALORES CARGADOS\n");
            numeroA = 0;
            numeroB = 0;
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
            break;

        case '5':
            opcion = '5';
            printf("Usted ha finalizado el programa!\n\n");
            break;

        default:
            printf("Error. Ha ingresado una opcion erronea!\n\n");
        }
        system("pause");
        system("cls");


    }while (opcion!='5');
    printf("====================================================\n");
    printf("\t\tGracias por utilizar la calculadora!\n");
    printf("====================================================\n");
    return 0;
}
