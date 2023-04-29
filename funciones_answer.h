#ifndef Funciones_answer_h
#define Funciones_answer_h

#include "hashmap.h"
#include "stack.h"

typedef struct Jugador Jugador;

void mostrarOpciones();

void mostrarMenu(HashMap * map);

Jugador * createJugador(HashMap * map, char * nombre);
//OPCION 1
void crearPerfilJugador(HashMap * map);
//OPCION 2
void mostrarPerfilJugador(HashMap * map);
//OPCION 3
void agregarItemJugador(HashMap * map);
//OPCION 4
void eliminarItemJugador(HashMap * map);
//OPCION 5
void agregarPuntosHabilidad(HashMap * map);
//OPCION 6
void mostrarJugadorConItem(HashMap* map);
//OPCION 7
void deshacerUltimaAccion(HashMap * map);
//OPCION 8
void exportarArchivoCSV(char * nombre_archivo, HashMap * map);
//OPCION 9
void importarArchivoCSV(char* nombre_archivo, HashMap* map);

char * toString(int num);

#endif /* Funciones_answer_h */