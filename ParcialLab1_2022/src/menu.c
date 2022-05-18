/*
 * menu.c
 *
 *  Created on: 15 may. 2022
 *      Author: Elias
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int menu()
{
    int opcion;
		printf("|-----------------------|\n");
		printf("         TALLER          \n");
		printf("|-----------------------|\n");
		printf("|1. ALTA SERVICIO       |\n");
		printf("|2. MODIFICAR SERVICIO  |\n");
		printf("|3. CANCELAR SERVICIO   |\n");
		printf("|4. DIAGNOSTICAR        |\n");
		printf("|5. LISTAR              |\n");
		printf("|6. SALIR DEL PROGRAMA  |\n");
		printf("|-----------------------|\n\n");
		printf("---------------------------\n");
		printf("Ingrese la opcion deseada: \n");
		printf("---------------------------\n");
		scanf("%d", &opcion);

		while(opcion < 0 || opcion > 7)
		{
			printf("ERROR, Reingrese una opcion valida");
			scanf("%d", &opcion);
		}
		return opcion;
}

