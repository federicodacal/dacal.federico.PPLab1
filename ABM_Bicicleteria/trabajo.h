#include "fecha.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    Fecha fechaTrabajo;
    int isEmpty;
}Trabajo;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "bicicleta.h"
#include "tipo.h"
#include "servicio.h"

int initTrabajos(Trabajo trabajos[], int len);
//int findEmptyIndex(Trabajo trabajos[], int len);
void printTrabajo(Trabajo unTrabajo);
//int printBicicletas(Trabajo trabajos[], int len);

#endif // TRABAJO_H_INCLUDED
