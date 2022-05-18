/*
 ============================================================================
 Name        : ParcialLab1_2022.c
 Author      : ELIAS GAYAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "ArrayMecanico.h"
#define TAMMECANICO 3
#define TAMSERVICIO 4
#define TAMDIAGNOSTICO 4


	eMecanico mecanico[TAMMECANICO]= {
							{101, "Pablo", "motor", 0},
							{102, "Pepe", "chasis", 0},
							{103, "Roberto", "Ruedas", 0}};


	eDiagnostico diagnostico[TAMDIAGNOSTICO]= {
							{1000, 's', "bielas", "hidraulica"},
							{1001, 'n', "bujia", "neumatica"},
							{1002, 'n', "piston", "rigida"},
							{1003, 's', "cilindro", "delantera"}};

int main(void)
{
	setbuf(stdout, NULL);

	//int id=0;
	int contador=0;
	int opcion;
	eServicio servicio[TAMSERVICIO];



		Inicializar(mecanico, servicio, TAMMECANICO, TAMSERVICIO);
	do
	{
		opcion = menu();
		switch(opcion)
		{
		case 1:
			if(contador < TAMSERVICIO)
			{
				PedirDatos(servicio, TAMSERVICIO);

				contador++;
			}
			break;

		case 2:
			if(contador < TAMSERVICIO)
			{
				ModificarServicio(servicio, TAMSERVICIO, mecanico, diagnostico, TAMMECANICO, TAMDIAGNOSTICO);
			}
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			if(contador < TAMSERVICIO)
			{
			//	Harcodeo(servicio, TAMSERVICIO, &id, &contador);
				listarServicio(servicio, TAMSERVICIO, mecanico, diagnostico, TAMMECANICO, TAMDIAGNOSTICO);
			}

			break;

		}

	}while(opcion != 6);

	printf("HAS SALIDO DEL PROGRAMA");

	return 0;
}
