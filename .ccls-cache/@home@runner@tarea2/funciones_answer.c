#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "hashmap.h"
#include "stack.h"
#include "funciones_answer.h"

#define MAXLEN 30

struct Jugador{
    char nombre[MAXLEN+1];
    int puntosHab; //puntos de habilidad
    HashMap* mapItem;
    Stack* stackAccion;
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
            crearPerfilJugador(map);
            break;
        case 2:
            printf("OPCION 2 INGRESADA\n\n");
            mostrarPerfilJugador(map);
            break;
        case 3:
            printf("OPCION 3 INGRESADA\n\n");
            agregarItemJugador(map);
            break;
        case 4:
            printf("OPCION 4 INGRESADA\n\n");
            eliminarItemJugador(map);
            break;
        case 5:
            printf("OPCION 5 INGRESADA\n\n");
            agregarPuntosHabilidad(map);
            break;
        case 6:
            printf("OPCION 6 INGRESADA\n\n");
            mostrarJugadorConItem(map);
            break;
        case 7:
            printf("OPCION 7 INGRESADA\n\n");
            deshacerUltimaAccion(map);
            break;
        case 8:
            printf("OPCION 8 INGRESADA\n\n");
            char nombre_archivo[MAXLEN+1];
            printf("INGRESE NOMBRE DEL ARCHIVO\n");
            scanf("%s", nombre_archivo);
            exportarArchivoCSV(nombre_archivo, map);
            break;
        case 9:
            printf("OPCION 9 INGRESADA\n\n");
            char nombre_archivoE[MAXLEN+1];
            printf("INGRESE NOMBRE DEL ARCHIVO\n");
            scanf("%s", nombre_archivoE);
            importarArchivoCSV(nombre_archivoE,map);
            break;
        case 0:
            printf("CERRANDO EL PROGRAMA...\n");
        }
    } while (opcion != 0);
}

Jugador * createJugador(HashMap* map, char* nombre)
{
    Jugador* jugador = (Jugador *) malloc(sizeof(Jugador));
    
    if(jugador == NULL) 
    {
        printf("NO SE PUDO RESERVAR MEMORIA PARA CREAR AL JUGADOR.\n");
        return NULL;
    }
    
    strcpy(jugador->nombre,nombre);
    jugador->puntosHab = 0;
    jugador->mapItem = createMap(10);
    jugador->stackAccion = createStack(3);
    return jugador;
}

void crearPerfilJugador(HashMap* map)
{
    char nombre[MAXLEN+1];
    do {
        printf("INGRESE NOMBRE DEL JUGADOR/A\n");
        scanf("%s",nombre);
        getchar();
    } while (strlen(nombre) > MAXLEN);
    
    Jugador* jugador = createJugador(map, nombre);
    insertMap(map,nombre,jugador);
    printf("PERFIL DEL JUGADOR/A CREADO EXITOSAMENTE.\n");

    Pair* auxJugador = searchMap(map,nombre);
    
    push(((Jugador *) auxJugador->value)->stackAccion,1,nombre); //se inserta accion en stack de acciones
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
    if (auxJugador == NULL)//no se encontro
    {
        printf("EL JUGADOR/A %s NO SE ENCUENTRA\n", nombre);
        return;
    }
    
    printf("PERFIL JUGADOR/A %s\n",nombre);
    printf("NOMBRE : %s\n",nombre);
    printf("CANTIDAD DE PUNTOS DE HABILIDAD : %i\n",((Jugador *)auxJugador->value)->puntosHab);
    
    if(!existenJugadores(((Jugador *)auxJugador->value)->mapItem))
    {
        printf("EL JUGADOR/A %s NO TIENE ITEMS\n",nombre);
        return;
    }
    
    Pair* auxItem = firstMap(((Jugador *)auxJugador->value)->mapItem); //primer item
    printf("ITEMS DEL JUGADOR/A:\n");
    
    int k = 1;
    while (auxItem != NULL)//recorre todos los items
    {
        printf("ITEM %d: %s\n",k,auxItem->key);
        auxItem = nextMap(((Jugador *)auxJugador->value)->mapItem);  
        k++;
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

    char item[MAXLEN+1];
    do {
        printf("INGRESE NOMBRE DEL ITEM A AGREGAR\n");
        scanf("%[^\n]s", item);
        getchar();
    } while (strlen(item) > MAXLEN);
    
    insertMap(((Jugador *)auxJugador->value)->mapItem, strdup(item), strdup(item));
    printf("EL ITEM %s HA SIDO AGREGADO AL JUGADOR/A %s.\n",item,nombre);
    push(((Jugador *) auxJugador->value)->stackAccion,3,item);
} 

void eliminarItemJugador(HashMap* map){
    char nombre[MAXLEN +1];
    do {
        printf("INGRESE NOMBRE DEL JUGADOR/A\n");
        scanf("%s",nombre);
        getchar();
    } while (strlen(nombre) > MAXLEN);
    
    Pair* auxJugador = searchMap(map, nombre);
    
    if (auxJugador == NULL){
        printf("EL JUGADOR/A %s NO SE ENCUENTRA\n", nombre);
        return;
    }
    Jugador* jugador = auxJugador->value;

    char item[MAXLEN +1];
    do {
        printf("INGRESE NOMBRE DEL ITEM A ELIMINAR\n");
        scanf("%30[^\n]s", item);
        getchar();
    } while (strlen(item) > MAXLEN);
    
    Pair* auxItem = searchMap(jugador->mapItem,item);

    if (auxItem == NULL){ 
        printf("ITEM A ELIMINAR NO SE ENCUENTRA\n");
        return;
    }
    
    eraseMap(jugador->mapItem,item);
    
    printf("EL ITEM %s HA SIDO ELIMINADO DEL JUGADOR/A %s.\n",item,nombre);
    push(((Jugador *)auxJugador->value)->stackAccion,4,item);
}

void agregarPuntosHabilidad(HashMap* map)
{
    char nombre[MAXLEN+1];
    do {
        printf("INGRESE NOMBRE DEL JUGADOR/A A AGREGAR PUNTOS DE HABILIDAD\n");
        scanf("%s", nombre);
        getchar();
    } while (strlen(nombre) > MAXLEN);

    Pair* auxJugador = searchMap(map,nombre);
    
    if (auxJugador == NULL)
    {
        printf("EL JUGADOR/A %s NO SE ENCUENTRA\n", nombre);
        return;
    }

    int puntosHab;
    do {
        printf("INGRESE CANTIDAD DE PUNTOS DE HABILIDAD A AGREGAR\n");
        scanf("%i",&puntosHab);
    } while (puntosHab <= 0);
    ((Jugador *)auxJugador->value)->puntosHab += puntosHab;
    
    push(((Jugador *)auxJugador->value)->stackAccion,5,toString(puntosHab));
}

void mostrarJugadorConItem(HashMap* map)
{
     if(!existenJugadores(map))
    {
        printf("NO EXISTEN JUGADORES/AS GUARDADOS\n");
        return;
    }
    
    char item[MAXLEN+1];
    do {
        printf("INGRESE NOMBRE DE ITEM A BUSCAR\n");
        scanf("%s", item);
        getchar();
    } while (strlen(item) > MAXLEN);
    
    bool encontrado = false; //verifica si se encontraron jugadores con item
    Pair* pair = firstMap(map);
    while (pair != NULL)
    {
        Jugador* auxJugador = (Jugador *) pair->value;
        Pair* auxItem = searchMap(auxJugador->mapItem,item);
        
        if (auxItem != NULL){
            if (!encontrado)
                printf("JUGADORES CON EL ITEM %s\n",item);
            
            printf("JUGADOR/A : %s\n",auxJugador->nombre);
            encontrado = true;
        }
        pair = nextMap(map);
    }
    
    if (encontrado == false) printf("NO SE ENCONTRARON JUGADORES/AS CON EL ITEM %s",item);
    return;            
}

void deshacerUltimaAccion(HashMap* map){
    
    if(!existenJugadores(map))
    {
        printf("NO EXISTEN JUGADORES/AS GUARDADOS\n");
        return;
    }
    
    char nombre[MAXLEN+1];
    do {
        printf("INGRESE NOMBRE DE JUGADOR/A\n");
        scanf("%s", nombre);
        getchar();
    } while (strlen(nombre) > MAXLEN);
    
    Pair* auxJugador = searchMap(map,nombre);
    if (auxJugador == NULL)
    {
        printf("EL JUGADOR/A %s NO SE ENCUENTRA\n", nombre);
        return;
    }
    Jugador* jugador = auxJugador->value;
    Info* elemen= pop(((Jugador *)auxJugador->value)->stackAccion);

    int opcion = elemen->accion;
    char* valorAccion = elemen->valorAccion;
    
    if (opcion == -1){
        printf("NO HAY ULTIMA ACCION REGISTRADA\n");
        return;
    }
    
    switch(opcion)
    {   
        case 1:
            eraseMap(map,nombre);
            printf("PERFIL DE JUGADOR %s ELIMINADO\n",nombre);
            break;
        
        case 3:
            eraseMap(jugador->mapItem,valorAccion);
            printf("EL ITEM %s DEL JUGADOR/A %s HA SIDO ELIMINADO\n",valorAccion,jugador->nombre);
            break;
        
        case 4:
            insertMap(((Jugador *)auxJugador->value)->mapItem, strdup(valorAccion), strdup(valorAccion));
            printf("EL ITEM %s DEL JUGADOR/A %s HA SIDO AGREGADO\n",valorAccion,jugador->nombre);
            break;
        
        case 5:
            jugador->puntosHab -= atoi(valorAccion);
            printf("SE HAN ELIMINADO %d PUNTOS DE HABILIDAD AL JUGADOR/A %s\n",atoi(valorAccion),jugador->nombre);//atoi transforma char a int
            break;
        
        default:
            printf("LA OPCION INGRESADA NO SE PUEDE DESHACER\n");
    }
}

void exportarArchivoCSV(char * nombre_archivo, HashMap * map) {
  FILE * archivo = fopen(nombre_archivo, "w");
    
  if (archivo == NULL) //verifica que se pudo abrir
  { 
    printf("NO SE PUDO EDITAR EL ARCHIVO %s.\n", nombre_archivo);
    return;
  }
    
  Jugador * jugador;
  Pair * pair = firstMap(map);
  while (pair != NULL) 
  {
      if (pair != NULL && pair -> value != NULL) 
      {
          jugador = (Jugador * ) pair -> value;
          fprintf(archivo, "%s,%d,%d", jugador -> nombre, jugador -> puntosHab,sizeMap(jugador->mapItem));
          
          Pair* parItem = firstMap(jugador->mapItem);
          while (parItem!=NULL) 
          {
              fprintf(archivo, ",%s", parItem->key);
              parItem = nextMap(jugador->mapItem);
          }
      }
      fprintf(archivo, "\n");
      pair = nextMap(map);
  }
  fclose(archivo);
  printf("SE HA COMPLETADO LA EXPORTACION DE LOS DATOS DE LOS JUGADORES AL ARCHIVO %s.\n", nombre_archivo);

}

void importarArchivoCSV(char* nombre_archivo, HashMap* map) {
    FILE* archivo = fopen(nombre_archivo, "r");
    
    if (archivo == NULL) {
        printf("NO SE PUDO ABRIR EL ARCHIVO %s\n", nombre_archivo);
        return;
    }
    
    char* linea = NULL;
    size_t longitud = 0;
    ssize_t leido;
    int cont = 0;
    while ((leido = getline(&linea, &longitud, archivo)) != -1)
    {
        char* nombre = strtok(linea, ",");
        int puntosHab = atoi(strtok(NULL, ","));
        int items_map = atoi(strtok(NULL, ","));
        
        Jugador* jugador = (Jugador*) malloc(sizeof(Jugador));
        strcpy(jugador->nombre, nombre);
        jugador->puntosHab = puntosHab;
        //jugador->cantidadItems=items_map;
        jugador->mapItem = createMap(items_map);
        
        for (int i = 0; i < items_map; i++) {
            char* item_nombre = strtok(NULL, ",");
            
            if (i == items_map - 1) //elimina el \n en el ultimo item almacenado
                item_nombre[strlen(item_nombre) - 2] = '\0';
            
            Pair* item = searchMap(jugador->mapItem, item_nombre);
            
            if (item == NULL) { 
                insertMap(jugador->mapItem, strdup(item_nombre), strdup(item_nombre));
            }
            
        }
        
        if (cont != 0) { //para no leer primera linea del csv
              jugador->stackAccion = createStack(3);
              push(jugador->stackAccion,1,nombre);
              insertMap(map, jugador->nombre, jugador);
         }
        cont++;
    }

    free(linea);
    fclose(archivo);
    printf("LOS DATOS DE LOS JUGADORES SE HAN CARGADO DESDE %s\n", nombre_archivo);
}

//transforma un entero a string 
char *toString(int num) {
    char string[10];
    sprintf(string, "%d", num);
    return strdup(string);
}