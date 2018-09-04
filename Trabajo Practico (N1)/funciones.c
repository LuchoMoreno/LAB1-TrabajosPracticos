#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

//************GETS****************//


int getInt (char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);


    return auxiliarInt;
}

char getChar (char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);


    return auxiliarChar;
}

float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}


//************VALIDACIONES****************//

int esNumerico (char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
        return 0;
        i++;
        }

    }
    return 1;
}



int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones = 0;
    while (str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if (str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if (contadorGuiones==1)
    {
        return 1;
    }

        return 0;
}



int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
        return 0;
        i++;
        }

    }
    return 1;
}



int esAlfaNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
        return 0;
        i++;
        }

    }
    return 1;
}

//************FUNCIONES SOBRE CALCULAR****************//


float funcionSumar (float numeroA, float numeroB)
{
    float suma;
    suma = numeroA + numeroB;
    return suma;
}


float funcionRestar (float numeroA, float numeroB)
{
    float resta;
    resta = numeroA - numeroB;
    return resta;
}

float funcionDividir (float numeroA, float numeroB)
{
    float division;

    if (numeroB == 0) // Se habilita la condicion de IF, para qué en caso que se ingrese un numero negativo, avise del error.
    {
        printf("\nLa division entre cero no esta permitida. Usted ingreso un 0 (Numero B).\n");
    }
    else
    {
    division = numeroA / numeroB;
    }

    return division;
}


float funcionMultiplicar (float numeroA, float numeroB)
{
    float multiplicacion;
    multiplicacion = numeroA * numeroB;
    return multiplicacion;
}


float funcionFactorial(float numero)
{
    float factorial;
    if (numero==0)
    {
        factorial = 1;
    }

    else if (numero<0)
    {
        factorial = 0;
    }
    else
    {
    factorial = numero * funcionFactorial(numero-1);
    }

    return factorial;
}
