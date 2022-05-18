/*
 * ArrayMecanico.c
 *
 *  Created on: 15 may. 2022
 *      Author: Elias
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayMecanico.h"
#include "input.h"
#include "validacion.h"


static int idIncremental = 0;

/*-------------------------------------------------------------------------------------------------------*/

int Inicializar(eMecanico* mecanico, eServicio* servicio, int len, int tam)
{
	int rtn = -1;

	if(mecanico != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			mecanico[i].idMecanico = -1;
			mecanico[i].isEmpty = 1;
		}

		for(int i=0; i<tam; i++)
		{
			servicio[i].idServicio = -1;
			servicio[i].isEmpty = 1;
		}
		rtn = 0;
	}


	return rtn;
}


/*-------------------------------------------------------------------------------------------------------*/
//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION

int ObtenerId()
{
	return idIncremental += 1;
}


/*-------------------------------------------------------------------------------------------------------*/


int BuscarLibre(eServicio* list, int len)
{
	int rtn=-1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------*/

int BuscarPorId(eServicio* list, int len, int id)
{
	int rtn = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].idServicio == id && list[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------*/

void MostrarUno(eServicio list)
{
	printf("%d   \n", list.idDiagnostico);
}

/*-------------------------------------------------------------------------------------------------------*/

int MostrarTodos(eServicio* list, int len)//por puntero se pasa cuando voy a cambiar algo de la esstructura

{
	int rtn = -1;

	printf("LISTADO MECANICOS\n");

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				MostrarUno(list[i]);
				rtn=0;
			}
		}
	}
	return rtn;
}


int PedirDatos(eServicio* list, int len)
{
	int rtn=-1;

	char nombre[50];
	int fechaDia;
	int fechaMes;
	int fechaAnio;
	int idDiagnostico;
	float cotizacionPrecio;
	int idMecanico;


	if(list != NULL && len > 0)
	{
		getString(nombre,"Ingrese el Nombre: \n", "error\n", 50);
		PedirFecha(&fechaDia, &fechaMes, &fechaAnio);
		getInt("Ingrese el Tipo de diagnostico: \n", &idDiagnostico);
		getFloat("Ingrese el precio de cotizacion: \n", &cotizacionPrecio);
		getInt("Ingrese el Id del Mecanico:\n", &idMecanico);

		Alta(list, len, nombre, fechaDia, fechaMes, fechaAnio, cotizacionPrecio, idDiagnostico, idMecanico);

		rtn=0;
	}


	return rtn;
}


eServicio BuscarServicio(eServicio* listServicio, int len, int id)
{
	eServicio auxServicio;

	if(listServicio != NULL && len > -1 && id > -1)
	{
		for(int i = 0; i<len; i++)
		{
			if(listServicio[i].idServicio == id)
			{
				auxServicio = listServicio[i];
			}
		}
	}
	return auxServicio;
}


int Alta(eServicio* servicio, int lenServicio, char nombre[], int fechaDia, int fechaMes, int fechaAnio, float cotizacion, int idDiagnostico, int idMecanico)
{
	int rtn = -1;
	int i;

	i = BuscarLibre(servicio, lenServicio);

	if(i != -1)
	{
		strcpy(servicio[i].nombreCliente, nombre);
		servicio[i].fecha.dia = fechaDia;
		servicio[i].fecha.mes = fechaMes;
		servicio[i].fecha.anio = fechaAnio;
		servicio[i].cotizacionServicio = cotizacion;
		servicio[i].idDiagnostico = idDiagnostico;
		servicio[i].idMecanico = idMecanico;
		servicio[i].idServicio = ObtenerId();
		servicio[i].isEmpty = 0;

		rtn = 0;
	}
	return rtn;
}

eDiagnostico BuscarDiagnostico(eDiagnostico* diagnostico, int len, int id)
{
	eDiagnostico auxDiagnostico;

	if(diagnostico != NULL && len > -1 && id > -1)
	{
		for(int i = 0; i<len; i++)
		{
			if(diagnostico[i].id == id)
			{
				auxDiagnostico = diagnostico[i];
			}
		}
	}
	return auxDiagnostico;
}


eMecanico BuscarMecanico(eMecanico* mecanico, int len, int id)
{
	eMecanico auxMecanico;

		if(mecanico != NULL && len > -1 && id > -1)
		{
			for(int i = 0; i<len; i++)
			{
				if(mecanico[i].idMecanico == id)
				{
					auxMecanico = mecanico[i];
				}
			}
		}
		return auxMecanico;
}


int Mostrar(eServicio servicio, eMecanico mecanico[], eDiagnostico diagnostico[], int lenght, int  tamMec, int tamDiag)
{
	eMecanico auxMecanico;
	eDiagnostico auxDiagnostico;
	int rtn = -1;



			auxMecanico = BuscarMecanico(mecanico, tamMec, servicio.idMecanico);
			auxDiagnostico = BuscarDiagnostico(diagnostico, tamDiag, servicio.idDiagnostico);
			printf("%d  |   %10s |%d/%d/%d     |   %20s   |    %.2f   |    %10s   \n  ",    servicio.idServicio,
																							servicio.nombreCliente,
																							servicio.fecha.dia,
																							servicio.fecha.mes,
																							servicio.fecha.anio,
																							auxDiagnostico.reparacioMotor,
																							servicio.cotizacionServicio,
																							auxMecanico.nombreMecanico);

			printf("\n--------------------------------------------------------------------------------\n\n");

			rtn=0;


	printf("********************************************************************************\n\n");
	return rtn;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

int listarServicio(eServicio servicio[], int tamSer, eMecanico mecanico[], eDiagnostico diagnostico[], int tamDiag, int tamMec)
{
    int todoOk = 0;
    int flag = 0;
    if(servicio != NULL && tamSer > 0)
    {
    	printf("-------------------------------------------------------------------------------------\n");
		printf("ID   |  NOMBRE CLIENTE  |FECHA  |   DIAGNOSTICO   |   COTIZACION   |   MECANICO   \n");
		printf("-------------------------------------------------------------------------------------\n");
        for(int i=0; i < tamSer; i++)
        {
            if(!servicio[i].isEmpty )
            {
            	Mostrar(servicio[i], mecanico, diagnostico, tamSer, tamMec, tamDiag);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("NO HAY SERVICIOS EN EL SISTEMA");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

int ModificarServicio(eServicio* servicio, int tamList, eMecanico mecanico[], eDiagnostico diagnostico[], int tamMec, int tamDiag)
{
	int rtn = -1;
	int modificar;
	int id;
	int i;
	eServicio nuevoServicio;


	if(servicio != NULL && tamList > 0)
	{
		listarServicio(servicio, tamList, mecanico, diagnostico, tamMec, tamDiag);
		getInt("Ingrese el Id de SERVICIO: \n", &id);
		i = BuscarPorId(servicio, tamList, id);

		if(i > -1)
		{
		    nuevoServicio = servicio[i];
			getInt("\n1. NOMBRE DE CLIENTE\n2. FECHA DE SERVICIO\n3. MECANICO\n\n INGRESE QUE DESEA MODIFICAR:\n", &modificar);

			switch(modificar)
			{

				case 1:
					getString(nuevoServicio.nombreCliente,"Ingrese el Nombre de Cliente a modificar: \n", "ERROR, Reingrese nuevamente el nombre:\n", 15);
				break;

				case 2:
					PedirFecha(&nuevoServicio.fecha.dia, &nuevoServicio.fecha.mes, &nuevoServicio.fecha.anio);
				break;

				case 3:
					getInt("Ingrese el Mecanico a modificar: \n", &nuevoServicio.idMecanico);
				break;
			}

			servicio[i] = nuevoServicio;
			rtn=0;
		}
		else
		{
			printf("NO SE HA ENCONTRADO NINGUN DATO PARA SER MODIFICADO\n");
		}

	}

	return rtn;
}





/*------------------------------------------------------------------------------------------------------------------------------------*/

/*
int Harcodeo(eServicio* list, int tamList, int* id, int* contador)
{
	int rtn =-1;

	eServicio eHarcodeo = {
						{1000, 's', "bielas", "hidraulica"},
						{1001, 'n', "bujia", "neumatica"},
						{1002, 'n', "piston", "rigida"},
						{1003, 's', "cilindro", "delantera"}};



	if(list != NULL && tamList > 0 && id != NULL)
	{
		for(int i=0; i<10; i++)
		{
			//list[i] = eHarcodeo[i];
			list[i].idServicio = *id;
			*id = *id + 1;
			*contador = *contador + 1;
		}
		rtn=0;
	}
	return rtn;
}

*/



/*

int removeMecanico(Mecanico* list, int len, int id)
{
	int rtn = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty==0)
			{
				list[i].isEmpty = 1;
				rtn=0;
				break;
			}
		}
	}

	return rtn;
}
 */





/*

int addMecanico(Mecanico* list, int len, int id, char name[], char specialty)
{
	int rtn = -1;

	if(list != NULL && len > 0 && name != NULL && specialty != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].idMecanico = id;
				list[i].especialidadMecanico = specialty;
				strcpy(list[i].nombreMecanico = name);
				list[i].isEmpty = 0;
				rtn = 0;
				break;
			}
		}

	}

	return rtn;
}


*/





