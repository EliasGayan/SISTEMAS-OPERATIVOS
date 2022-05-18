/*
 * input.c
 *
 *  Created on: 15 may. 2022
 *      Author: Elias
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "ArrayMecanico.h"



int getString(char* chain, char* message, char* messageMistake, int max)
{
	int ret = -1;
	char buffer[256];
	int len;

	if(chain != NULL && message != NULL && messageMistake != NULL && max > 0)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);

		while(len > max)
		{
			printf("%s", messageMistake);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			len = strlen(buffer);
		}

		strcpy(chain, buffer);
		ret = 0;
	}

	return ret;
}

/*----------------------------------------------------------------------------------------------------------*/

int getFloat(char cadena[], float* numero)
{
	int rtn = -1;
	float numeroFuncion;

	if(cadena != NULL && numero != NULL)
	{
		printf("%s", cadena);
		fflush(stdin);
		scanf("%f", &numeroFuncion);
		*numero = numeroFuncion;
		rtn = 0;
	}

	while(numeroFuncion < 1)
	{
		printf("ERROR, VUELVA A INGRESAR UN NUMERO MAYOR QUE CERO: \n");
		fflush(stdin);
		scanf("%f", &numeroFuncion);
	}

	return rtn;
}

/*----------------------------------------------------------------------------------------------------------*/

int getInt(char cadena[], int* numero)
{
	int rtn=-1;
	int numeroFuncion;

	if(cadena != NULL && numero != NULL)
	{
		printf("%s", cadena);
		fflush(stdin);
		scanf("%d", &numeroFuncion);
		*numero = numeroFuncion;
		rtn=0;
	}

	while(numeroFuncion < 1)
	{
		printf("ERROR, VUELVA A INGRESAR UN NUMERO MAYOR QUE CERO: \n");
		fflush(stdin);
		scanf("%d", &numeroFuncion);
	}

	return rtn;
}


/*----------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------------------------------------*/



