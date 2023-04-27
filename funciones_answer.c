#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#include "hashmap.h"
#include "stack.h"
#include "funciones_answer.h"

#define MAXLEN 30

struct Jugador{
    char nombre[MAXLEN+1];
    int puntosHab;
    int cantItem;
    char** item;
    Stack* stack;
};

void mostrarOpciones(){
    printf("*********************************************************\n");
    printf("1. INGRESE 1 SI DESEA CREAR PERFIL DE JUGADOR/A\n");
    printf("2. INGRESE 2 SI DESEA MOSTRAR PERFIL DE JUGADOR/A\n");
    printf("3. INGRESE 3 SI DESEA AGREGAR ITEM A JUGADOR/A\n");
    printf("4. INGRESE 4 SI DESEA ELIMINAR ITEM DE JUGADOR/A\n");
    printf("5. INGRESE 5 SI DESEA AGREGAR PUNTOS DE HABILIDAD A EL/LA JUGADOR/A\n");
    printf("6. INGRESE 6 SI DESEA MOSTRAR JUGADORES CON ITEM ESPECIFICO\n");
    printf("7. INGRESE 7 SI DESEA DESHACER ULTIMA ACCION DE JUGADOR/A\n");
    printf("8. INGRESE 8 SI DESEA EXPORTAR DATOS DE JUGADORES A UN ARCHIVO CSV\n");
    printf("9. INGRESE 9 SI DESEA CARGAR DATOS DE JUGADORES DESDE UN ARCHIVO CSV\n");
    printf("10.INGRESE 0 SI DESEA SALIR\n");
    printf("*********************************************************\n\n");
}

void mostrarMenu(HashMap * map)
{
    int opcion;
    do {
        printf("\n");
        mostrarOpciones();
        
        scanf("%d", &opcion);
        switch (opcion) {
        case 1:
            printf("OPCION 1 INGRESADA\n\n");
            break;
        case 2:
            printf("OPCION 2 INGRESADA\n\n");
            break;
        case 3:
            printf("OPCION 3 INGRESADA\n\n");
            break;
        case 4:
            printf("OPCION 4 INGRESADA\n\n");
            break;
        case 5:
            printf("OPCION 5 INGRESADA\n\n");
            break;
        case 6:
            printf("OPCION 6 INGRESADA\n\n");
            break;
        case 7:
            printf("OPCION 7 INGRESADA\n\n");
            break;
        case 8:
            printf("OPCION 8 INGRESADA\n\n");
            char nombre_archivo[MAXLEN+1];
            printf("INGRESE NOMBRE DEL ARCHIVO\n");
            scanf("%s", nombre_archivo);
            break;
        case 9:
            printf("OPCION 9 INGRESADA\n\n");
            char nombre_archivoE[MAXLEN+1];
            printf("INGRESE NOMBRE DEL ARCHIVO\n");
            scanf("%s", nombre_archivoE);
            break;
        case 0:
            printf("CERRANDO EL PROGRAMA...\n");
        }
    } while (opcion != 0);
}

Jugador * createJugador(char *nombre, HashMap* map)
{
    Jugador* jugador = (Jugador *) malloc(sizeof(Jugador));
    
    if(jugador == NULL) 
    {
        printf("NO SE PUDO RESERVAR MEMORIA PARA CREAR AL JUGADOR.\n");
        return NULL;
    }
    
    strcpy(jugador->nombre,nombre);
    jugador->puntosHab = 0;
    jugador->cantItem = 0;
    jugador->item = NULL;
    jugador->stack = createStack(3);
    return jugador;
}

void crearPerfilJugador(HashMap* map){

    char nombre[MAXLEN+1];
    do {
        printf("INGRESE NOMBRE DEL JUGADOR/A\n");
        scanf("%s",nombre);
        getchar();
    } while (strlen(nombre) > MAXLEN);
    
    Jugador* jugador = createJugador(nombre, map);
    insertMap(map,nombre,jugador);
    printf("Perfil de jugador/a creado exitosamente.\n");

    Pair* auxJugador = searchMap(map,nombre);
    
    push(((Jugador *) auxJugador->value)->stack,1,nombre); 
}

void mostrarPerfilJugador(HashMap* map)
{
    char nombre[MAXLEN+1];
    do {
    printf("INGRESE NOMBRE DEL JUGADOR/A A MOSTRAR\n");
    scanf("%s", nombre);
    getchar();
    } while (strlen(nombre) > MAXLEN);
    
    Pair* auxJugador = searchMap(map,nombre);
    if (auxJugador == NULL)
    {
        printf("EL JUGADOR/A %s NO SE ENCUENTRA\n", nombre);
        return;
    }
    
    printf("PERFIL JUGADOR/A %s\n",nombre);
    printf("NOMBRE : %s\n",nombre);
    printf("CANTIDAD DE PUNTOS DE HABILIDAD : %i\n",((Jugador *)auxJugador->value)->puntosHab);
    
    if (((Jugador *)auxJugador->value)->cantItem == 0) 
    {
        printf("EL JUGADOR/A %s NO TIENE ITEMS\n",nombre);
        return;
    }
    
    printf("CANTIDAD DE ITEMS : %i\n",((Jugador *)auxJugador->value)->cantItem);
    for (size_t k = 0; k < ((Jugador *)auxJugador->value)->cantItem ;k++)
    {
        printf("ITEM %zd : %s \n",k+1,((Jugador *)auxJugador->value)->item[k]);
    }
}

void agregarItemJugador(HashMap * map){
    char nombre[MAXLEN+1];
    
    do {
        printf("INGRESE NOMBRE DEL JUGADOR/A A AGREGAR ITEM\n");
        scanf("%s", nombre);
        getchar();
    } while (strlen(nombre) > MAXLEN);

    Pair* auxJugador = searchMap(map,nombre);
    
    if (auxJugador == NULL)
    {
        printf("EL JUGADOR/A %s NO SE ENCUENTRA\n", nombre);
        return;
    }

    do {
        printf("INGRESE NOMBRE DEL ITEM A AGREGAR\n");
        scanf("%s", nombre);
        getchar();
    } while (strlen(nombre) > MAXLEN);

    Jugador* current = auxJugador->value;
    int i = current->cantItem;
    current->item =  realloc(current->item, sizeof(char *) * (i+1));
    current->item[i] = (char *) malloc(sizeof(char)*(strlen(nombre)+1));

    if (current->item == NULL){
        printf("ERROR AL RESERVAR MEMORIA\n");
        return;
    }
    strcpy(current->item[i],nombre);
    
    (current->cantItem)++;
    push(((Jugador *)auxJugador->value)->stack,3,nombre);
    
} 