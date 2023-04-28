#ifndef Funciones_answer_h
#define Funciones_answer_h

#include "hashmap.h"
#include "stack.h"

typedef struct Jugador Jugador;

void mostrarOpciones();

void mostrarMenu(HashMap * map);

Jugador * createJugador(char * nombre, HashMap * map);

void crearPerfilJugador(HashMap * map);

void mostrarPerfilJugador(HashMap * map);

void agregarItemJugador(HashMap * map);

void eliminarItemJugador(HashMap * map);

void agregarPuntosHabilidad(HashMap * map);

void mostrarJugadorConItem(HashMap* map);

void deshacerUltimaAccion(HashMap * map);

void exportarArchivoCSV(char * nombre_archivo, HashMap * map);

char * toString(int num);

#endif /* Funciones_answer_h */