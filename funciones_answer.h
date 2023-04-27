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

#endif /* Funciones_answer_h */