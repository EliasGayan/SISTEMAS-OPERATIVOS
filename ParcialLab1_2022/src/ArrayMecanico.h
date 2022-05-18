/*
 * ArrayeMecanico.h
 *
 *  Created on: 15 may. 2022
 *      Author: Elias
 */

#ifndef ARRAYeMecanico_H_
#define ARRAYeMecanico_H_


typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char cambioAceite;
	char reparacioMotor[20];
	char suspension[20];
}eDiagnostico;

typedef struct
{
	int idMecanico;
    int idServicio;
    char nombreCliente[50];
    eFecha fecha;
    int idDiagnostico;
    float cotizacionServicio;
    int isEmpty;
}eServicio;


typedef struct
{
    int idMecanico;
    char nombreMecanico[50];
    char especialidadeMecanico[20];
    int isEmpty;
}eMecanico;

int Inicializar(eMecanico* mecanico, eServicio* servicio, int len, int tam);

/*------------------------------------------------------------------------------------------------------------------------------------*/

int ObtenerId();

/*------------------------------------------------------------------------------------------------------------------------------------*/

int BuscarLibre(eServicio* list, int len);
int BuscarPorId(eServicio* list, int len, int id);
eDiagnostico BuscarDiagnostico(eDiagnostico* diagnostico, int len, int id);
eMecanico BuscarMecanico(eMecanico* mecanico, int len, int id);
eServicio BuscarServicio(eServicio* listServicio, int len, int id);

/*------------------------------------------------------------------------------------------------------------------------------------*/

int PedirDatos(eServicio* list, int len);

/*------------------------------------------------------------------------------------------------------------------------------------*/

int Alta(eServicio* servicio, int lenServicio, char nombre[], int fechaDia, int fechaMes, int fechaAnio, float cotizacion, int idDiagnostico, int idMecanico);

/*------------------------------------------------------------------------------------------------------------------------------------*/

void MostrarUno(eServicio list);
int MostrarTodos(eServicio* list, int len);
int Mostrar(eServicio servicio, eMecanico mecanico[], eDiagnostico diagnostico[], int lenght, int  tamMec, int tamDiag);
int listarServicio(eServicio servicio[], int tamSer, eMecanico mecanico[], eDiagnostico diagnostico[], int tamDiag, int tamMec);
/*------------------------------------------------------------------------------------------------------------------------------------*/

int Harcodeo(eServicio* list, int tamList, int* id, int* contador);

int ModificarServicio(eServicio* servicio, int tamList, eMecanico mecanico[], eDiagnostico diagnostico[], int tamMec, int tamDiag);
//int removeeMecanico(eMecanico* list, int len, int id);


#endif /* ARRAYeMecanico_H_ */
