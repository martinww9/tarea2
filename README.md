(1) cómo compilar y ejecutar la tarea:

Para ejecutar la tarea primero compilamos el codigo, para que se cree un archivo ejecutable que es el programa. Al ejecutarlo se mostrara un menu con opciones y se debe escribir por teclado el numero que señale esa opcion y por consiguiente el enter, algunas opciones y recomendaciones son las siguientes:

OPCION 1 CREAR PERFIL DE JUGADOR/A: Se registra un jugador, se debe escribir por teclado el nombre del jugador/a que se creara el perfil. Importante que todo campo que sea letra tiene un maximo de 30 caracteres, si este se supera se volvera a pedir ese dato en concreto.

OPCION 2 MOSTRAR PERFIL DE JUGADOR/A: Se muestra el perfil del jugador/a que se desea encontrar, si no es hallado se mostrara por mensaje que el jugador/a no se encuentra, para saber especificamente a quien se busca se debe escribir por teclado el nombre. La informacion a mostrar corresponde a el nombre del jugador/a,cantidad de puntos de habilidad e items que posee. Si el jugador no tiene items se mostrara un aviso.

OPCION 3 AGREGAR ITEM A UN JUGADOR/A: Esta funcion agrega un item a un jugador en especifico almacenado en un HashMap. Primero, se solicita al usuario que ingrese el nombre del jugador y se verifica si existe en el mapa. Si el jugador no existe en el mapa, se muestra por pantalla que no se encuentra y se termina la función. Caso contrario se solicita el nombre del item que se quiere agregar y se inserta en el mapa de acciones. Por ultimo, se agrega el item a una pila de acciones realizadas por el jugador y se muestra un mensaje indicando que el item fue agregado al jugador.

OPCION 4 ELIMINAR ITEM DE JUGADOR/A: Esta funcion  elimina un item específico del inventario de un jugador. Se ingresa el nombre del jugador/a y el nombre del item a eliminar. Luego, se verifica si el jugador/a se encuentra en el mapa. Si no está en el mapa, se muestra un mensaje de error y da fin a la funcion. Si el jugador/a está en el mapa, se busca el item en el mapa de items del jugador/a. Si el item no está en el mapa de los items, se muestra un mensaje de error y se sale de la función. Si el item se encuentra en el mapa, se elimina del mapa de items del jugador/a y se muestra un mensaje de éxito.

OPCION 5 AGREGAR PUNTOS DE HABILIDAD A JUGADOR/A: Primero se pide al usuario que ingrese el nombre del jugador al que se le van a agregar los puntos de habilidad, y se verifica si el jugador existe. Si el jugador no existe, se muestra un mensaje y se retorna. En el caso de que exista, se pide al usuario que ingrese la cantidad de puntos de habilidad que se van a agregar, comprobando. Luego se agrega la cantidad de puntos ingresados a la cantidad actual de puntos de habilidad del jugador. Finalmente, se guarda la operación en el stack del jugador y se indica que se agregaron puntos de habilidad y la cantidad de puntos agregados.

OPCION 6 MOSTRAR JUGADORES CON ITEM ESPECIFICO: Esta función muestra en pantalla los nombres de los jugadores que tienen un determinado ítem en su inventario. Primero verifica si hay jugadores guardados en el mapa. Luego, solicita al usuario que ingrese el nombre del ítem a buscar. Para cada jugador, busca el ítem en su mapa de ítems y en caso de ser encontrado, muestra el nombre del jugador. Si no se encuentra ningún jugador con ese ítem, se muestra un mensaje indicándolo.

OPCION 7 DESHACER ULTIMA ACCION DE JUGADOR/A: Como indica el nombre esta función deshace la ultima accion de un jugador indicado por el usuario. Primero, se verifica si existen jugadores en el mapa, de lo contrario, se muestra un mensaje y se retorna. Si no es el caso se solicita al usuario que ingrese el nombre del jugador/a cuya última acción desea deshacer. Si el jugador no se encuentra en el mapa, se muestra un mensaje y se retorna. Se busca el jugador/a en la estructura de datos y se saca el último elemento de su pila de acciones. Se obtiene la acción y el valor de la acción realizada y se procede a deshacerla según corresponda. Por ejemplo: Si la acción es la ultima accion es crear un perfil de jugador/a (opción 1), se elimina el jugador/a de la estructura de datos.
*IMPORTANTE* 
Las acciones relacionadas a importar, exportar y mostrar informacion de un jugador no son consideradas al momento de deshacer ya que no tienen relevancia ni accion contraria que realizar.

OPCION 8 EXPORTAR DATOS DE JUGADORES A UN ARCHIVO CSV: Esta funcion se encarga de exportar la información de los jugadores de un HashMap a un archivo CSV. Primero se abre un archivo en modo escritura y se comprueba si se pudo crear correctamente. Luego se recorre el HashMap a través de un ciclo while utilizando la función firstMap() y nextMap(), y se van obteniendo los datos de cada jugador. Estos datos se escriben en el archivo utilizando la función fprintf() en un formato específico que consiste en el nombre del jugador, sus puntos de habilidad, la cantidad de items que tiene y la lista de los nombres de sus items separados por comas. Finalmente, se cierra el archivo y se muestra un mensaje de confirmación de la exportación.

OPCION 9 CARGAR DATOS DE JUGADORES DESDE UN ARCHIVO CSV: Este funcion recibe como parámetros el nombre de un archivo y un mapa HashMap. La función abre el archivo y lee su contenido línea por línea utilizando la función getline. Luego, separa cada línea en campos utilizando la función strtok y crea un objeto Jugador con los datos obtenidos. Finalmente, agrega este objeto al mapa utilizando la función insertMap. Además, la función crea un stack para el jugador, lo que sugiere que se trata de un juego donde los jugadores pueden acumular objetos en su inventario. En caso de que no se pueda abrir el archivo, la función muestra un mensaje de error. Al finalizar, muestra un mensaje indicando que la carga de datos ha sido completada.

(2) las opciones que funcionan correctamente y las que no lo hacen indicando posibles causas;
Todas las opciones funcionan correctamente

(3) coevaluación del trabajo en equipo (usando rúbrica):
participacion activa: 20
resolucion de conflictos: 20
colaboracion: 20
responsabilidad: 20
comunicacion: 20

(4) coevaluación del aporte individual de cada integrante (usando rúbrica).

puntaje asignado en coevaluacion:
participacion:Claudio Cabello 20, David Martinez 20, Martin Vazquez 20, Matias Prado 15
responsabilidad:Claudio Cabello 20,David Martinez 20, Martin Vazquez 20, Matias Prado 20
comunicacion:Claudio Cabello 20,David Martinez 20, Martin Vazquez 20, Matias Prado 20
calidad de trabajo:Claudio Cabello 20,David Martinez 20, Martin Vazquez 20, Matias Prado 20
trabajo en equipo:Claudio Cabello 20,David Martinez 20, Martin Vazquez 20, Matias Prado 20
puntaje final:Claudio Cabello 100, David Martinez 100, Martin Vazquez 100, Matias Prado 95

*ASPECTOS POSITIVOS*

CLAUDIO CABELLO:
Siempre viene a clases y participativo
Tiene la iniciativa
Buena participacion


DAVID MARTINEZ:
Asiste a clases y aporta tarea
Pariticpativo en tarea y actividades en clases
Dispuesto ayudar

MATIAS PRADO
Aporta en clases
Activo en actividad en clases

MARTIN VASQUEZ
Aporta en tarea y asiste a clases
dispuesto ayudar en dudas
aporta en actividad en equipo

*ASPECTOS NEGATIVOS*

MATIAS PRADO:
Poco aporte en la tarea y actividades
Responsabilidad en horario de clases


*APORTE INDIVIDUAL*
iIMPLEMENTACION DE TDAS: Claudio Cabello
MENU: Claudio Cabello/David Martinez
OPCION 1: David Martinez
OPCION 2: David Martinez
OPCION 3: Claudio Cabello
OPCION 4: Claudio Cabello/Matias Prado
OPCION 5: Claudio Cabello/David Martinez
OPCION 6: David Martinez
OPCION 7: David Martinez/Claudio Cabello
OPCION 8: Martin Vasquez
OPCION 9: Martin Vasquez
README: Claudio Cabello/Matias Prado

(5)Herramientras utilizadas en el desarrollo:

La principal herramienta de trabajo que utilizamos en el desarrollo del menu es el IDE online 'replit'. Esta nos nos permitio trabajar colaborativamente en el mismo codigo y compilarlo. Tambien nos otorgo memoria virtual para crear archivos que separen el codigo.

Otra herramienta que se utilizo es la herramienta de control de versiones 'git' la cual nos permitio añadir, actualizar y subir nuestro avance a un repositorio ubicado en github.

Por ultimo la plataforma 'github' la cual nos permitio crear nuestro repositorio y almacenar el codigo.
