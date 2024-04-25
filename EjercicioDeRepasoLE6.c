/*
CONSIGNA: Desarrollar un programa en C que permita ingresar información de empleados, procesarla y 
mostrar resultados relevantes a través de un menú interactivo.
*/
#include <stdio.h>
#include <stdint.h> 
#include <string.h>


#define CARACTERES 40
#define CANT_EMPLEADOS 5




struct Empleado{
    char nombre [CARACTERES];
    uint8_t edad;
    float salario; 
};




void ingresarDatos(struct Empleado [],uint8_t );
void procesarDatos(struct Empleado [], uint8_t);
void mostrarDatos(struct Empleado [], uint8_t);




int main(void){
    struct Empleado empleados[CANT_EMPLEADOS];
    int opciones;
    uint8_t empleadosIngresados=0;


    for(int i = 0; i<CANT_EMPLEADOS; i++){
        empleados[i].edad=0;
        empleados[i].salario=0;
    }


    printf("\n--- Menu ---\n1. Ingresar datos de un empleado \n2. Procesar y mostrar informacion relevante \n3. Salir \nSeleccione la opcion indicada: ");
    scanf("%d", &opciones);


    while(opciones !=3){
        while(opciones !=1 && opciones !=2){
            printf("\nLa opcion ingresada no se encuentra en el menu, recuerde que las opciones son 1, 2 y 3");
            printf("\nVuelva a ingresar una opcion: ");
            scanf("%d", &opciones);
        }
        if(opciones==1){
            ingresarDatos(empleados,empleadosIngresados);
            empleadosIngresados++;

            printf("\nEmpleado ingresado correctamente. Actualmente hay %d de 5 empleados ingresados.\n", empleadosIngresados);
            printf("\n--- Menu ---\n1. Ingresar datos de un empleado \n2. Procesar y mostrar informacion relevante \n3. Salir \nSeleccione la opcion indicada: ");
            scanf("%d", &opciones);
        }
        if(opciones==2){
            mostrarDatos(empleados, empleadosIngresados);
            procesarDatos(empleados, empleadosIngresados);
            printf("\n--- Menu ---\n1. Ingresar datos de un empleado \n2. Procesar y mostrar informacion relevante \n3. Salir \nSeleccione la opcion indicada: ");
            scanf("%d", &opciones);            
        }
    }
    printf("\nHasta luego!");
}


void ingresarDatos(struct Empleado empleados[],uint8_t empleadosIngresados){
    printf("\nIngrese el nombre del empleado: ");
    scanf("\n%[^\n]s", empleados[empleadosIngresados].nombre);
    printf("Ingrese la edad del empleado: ");
    scanf("%d", &empleados[empleadosIngresados].edad);
    printf("Ingrese el salario del empleado: ");
    scanf("%f", &empleados[empleadosIngresados].salario);
}


void procesarDatos(struct Empleado empleados[], uint8_t empleadosIngresados){
    float promedio=0;
    int max=0;
    int maxEmpleado;


    for (int i=0; i <empleadosIngresados; i++){
        if(empleados[i].salario >max){
            max=empleados[i].salario;
            maxEmpleado=i;
        }
    }
    
    for (int j=0; j <empleadosIngresados; j++){
        promedio = promedio + empleados[j].salario;
    }
    promedio = promedio/empleadosIngresados;
    
    printf("\nEl promedio de salarios es $%f", promedio);
    printf("\nEl empleado con el salario mas alto es %s con un salario de $%d\n", empleados[maxEmpleado].nombre, max);


}


void mostrarDatos(struct Empleado empleados[], uint8_t empleadosIngresados){
    printf("\n--- Informacion de empleados ---\n");
    for (int i=0; i <empleadosIngresados; i++){
        printf("%d. Nombre: %s, Edad: %d, Salario: $%f\n", i+1, empleados[i].nombre, empleados[i].edad, empleados[i].salario);
    }
}