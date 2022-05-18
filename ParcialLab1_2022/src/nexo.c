/*
 * nexo.c
 *
 *  Created on: 15 may. 2022
 *      Author: Elias
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"
#include "nexo.h"
#include "ArrayMecanico.h"

/*

int AgregarMecanico(Mecanico* list, int tamList, int* id)
{
	int rtn = -1;

	char nombre[51];
    char especialidadMecanico[20];

	if(list != NULL && tamList > 0 && id != NULL)
	{
		getString(nombre,"Ingrese el Nombre: \n", "error\n", 51);
		getString(especialidadMecanico,"Ingrese la especialidad del mecanico: \n", "error\n", 51);


		addMecanico(list, tamList, *id, nombre, especialidadMecanico);

		*id = *id + 1;

		printf("Se ha ingresado con Exito!!\n");
		rtn = 0;
	}

	return rtn;
}




int ModificarMecanico(Mecanico* list, int tamList)
{
	int rtn = -1;
	int modificar;
	int id;
	int i;
	Mecanico nuevoMecanico;

	if(list != NULL && tamList > 0)
	{
		printMecanico(list, tamList);
		getInt("¿Que Id de pasajero desea modificar?\n", &id);
		i = findMecanicoById(list, tamList, id);

		if(i > -1)
		{
		    nuevoMecanico = list[i];
		//nuevoServicio = list[i];
			getInt("Para modificar:\n1. NOMBRE\n2. APELLIDO\n3. PRECIO\n4. CODIGO DE VUELO\n5. TIPO DE PASAJERO\n", &modificar);

			switch(modificar)
			{

				case 1:
					getString(nuevoMecanico.nombreMecanico,"Ingrese el Nombre a modificar: \n", "ERROR, Reingrese nuevamente el nombre:\n", 15);
				break;

				case 2:
					getString(nuevoMecanico.,"Ingrese el apellido a modificar: \n", "ERROR, Reingrese nuevamente el apellido:\n", 15);
				break;

				case 3:
					getFloat("Ingrese el precio a modificar: \n", &nuevoPasajero.price);
				break;

				case 4:
					getString(nuevoPasajero.flyCode,"Ingrese el codigo de vuelo a modificar: \n", "ERROR, Reingrese nuevamente el codigo de vuelo:\n", 10);
				break;

				case 5:
					getInt("Ingrese la fecha de servicio a modificar: \n", &nuevoMecanico.otroServicio.fecha);
				break;
			}

			list[i] = nuevoMecanico;
			//list[i] = nuevoServicio;
			rtn=0;
		}
		else
		{
			printf("NO SE HA ENCONTRADO NINGUN DATO PARA SER MODIFICADO\n");
		}

	}

	return rtn;
}





int EliminarMecanico(Mecanico* list, int tamList)
{
	int rtn=-1;
	int flag = -1;
	int id;

	if(list!=NULL && tamList > 0)
	{
		printMecanico(list, tamList);
		printf("Ingrese el ID que desea eliminar: \n");
		scanf("%d", &id);
		flag = removeMecanico(list, tamList, id);

		if(flag!=0)
		{
			printf("El ID ingresado no existe\n");
		}
		else
		{
			printf("El ID ingresado se ha Eliminado correctamente\n");
		}

		rtn=0;
	}

	return rtn;
}

*/

