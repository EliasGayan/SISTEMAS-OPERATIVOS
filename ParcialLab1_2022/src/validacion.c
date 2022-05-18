/*
 * validacion.c
 *
 *  Created on: 17 may. 2022
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacion.h"


int PedirFecha(int* dia, int* mes, int* anio)
{

	int rtn=-1;
	int auxDia;
	int auxMes;
	int auxAnio;

	printf("Ingresar Fecha dd/mm/aa: \n");
	scanf("%d/%d/%d", &auxDia, &auxMes, &auxAnio);

	while(auxDia < 1 || auxDia > 31 || auxMes < 1 || auxMes > 12 || auxAnio < 2010 || auxAnio > 2022)
	{
		printf("ERROR, Reingrese fecha: \n");
		scanf("%d/%d/%d", &auxDia, &auxMes, &auxAnio);
	}


	*dia = auxDia;
	*mes = auxMes;
	*anio = auxAnio;

	rtn = 0;

	return rtn;
}


