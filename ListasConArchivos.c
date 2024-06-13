// Si tengo tiempo puedo hacer que se guarde la info anterior y que se pueda borrar
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 50
#define CARGAR 1
#define IMPRIMIR 2
#define SALIR 3

typedef struct serie{
    char nombre [MAX_CHAR];
    unsigned int anio; 
    unsigned int temporadas;
    char genero [MAX_CHAR];
    struct serie *siguiente;
}serie_t;


void menu ();
void crear_serie ();
void pedir_datos (serie_t * serie);
void leer_datos (void);
void liberar_memoria ();
FILE *miArchivo; //digo que el puntero apunta a un archivo

int main (){   
    miArchivo = fopen ("series.txt", "r+");//digo el nombre del archivo y que voy a leer y escribir"
    printf("Archivo Abierto\n");
    menu();
    liberar_memoria();
    fclose(miArchivo);
    printf("Archivo Cerrado.");
    return 0;
}

serie_t *catalogo = NULL;


void menu (){
    int opcion;
    do{
        printf ("1_Cargar una serie \n2_Imprimir series \n3_Salir \n");
        scanf ("%d", &opcion);
        while (opcion != CARGAR && opcion != IMPRIMIR && opcion != SALIR){
            printf ("Error. Volver a ingresar");
            scanf ("%d", &opcion);
        } 
        if (opcion == CARGAR)crear_serie ();
        if (opcion == IMPRIMIR)leer_datos ();       
    }while (opcion != SALIR);
}

void crear_serie (){
    serie_t *serie_aux;
    serie_aux=malloc(sizeof(serie_t));//malloc es memory allocate. Sirve para pedir memoria y ubica a mi pointer alumno_aux en el comienzo de esa memoria.
    if(serie_aux == NULL){
        printf("Sin memoria\n");
    }else{
        pedir_datos(serie_aux);
        serie_aux->siguiente=catalogo; //uno mi ultima estructura con el resto de las estructuras
        catalogo=serie_aux; //hago que catálogo apunte al inicio
    }
}

void pedir_datos(serie_t * serienueva){
    printf ("\nIngrese el nombre de la serie\n");
    scanf ("\n%[^\n]%*c", &(serienueva->nombre)); //(*alumno).Nombre esto seria para modificar lo que se guarda en la direccion a la que apunta el pointer. La flechita hace lo mismo.
    printf ("\nIngrese el anio del estreno de la serie\n");
    scanf ("%d", &(serienueva->anio));
    printf ("\nIngrese la cantidad de temporadas de la serie\n");
    scanf ("%d", &(serienueva->temporadas));
    printf ("\nIngrese el genero de la serie\n");
    scanf ("\n%[^\n]%*c", &(serienueva->genero)); //escribo \n%[^\n]%*c para que se lea mi string si tiene mas de una palabra.
}

void leer_datos (){
    serie_t *lista = catalogo; 
    while (lista != NULL){
        fprintf (miArchivo, "\nnombre: %s\n", (lista->nombre));
        fprintf (miArchivo, "anio de estreno: %d\n", (lista->anio));
        fprintf (miArchivo, "cantidad de temporadas: %d\n", (lista->temporadas));
        fprintf (miArchivo, "genero de la serie: %s\n", (lista->genero));
        fprintf (miArchivo, "-----------------------------------------------------\n");
        lista = lista->siguiente;
    }
}

void liberar_memoria (){
    serie_t *liberar = NULL;
    while (catalogo != NULL){
        liberar = catalogo;
        catalogo = catalogo->siguiente;
        free(liberar);
    }
}
