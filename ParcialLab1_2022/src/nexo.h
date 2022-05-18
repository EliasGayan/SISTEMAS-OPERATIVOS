/*
 * nexo.h
 *
 *  Created on: 15 may. 2022
 *      Author: Elias
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "ArrayMecanico.h"


int AgregarMecanico(eMecanico* list, int tamList, int* id);
int ModificarMecanico(eMecanico* list, int tamList);
int EliminarMecanico(eMecanico* list, int tamList);


#endif /* NEXO_H_ */
