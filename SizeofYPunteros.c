#include <stdio.h>

int main()
{
    char var=2;
    char * var_ptr=&var;
    
    printf("el valor de var es: %d\n" ,var);
    printf("la direccion de var es: %d\n" ,&var);
    printf("el valor del puntero es: %d\n" ,var_ptr);
    printf("la direccion del puntero es: %d\n" ,&var_ptr);
    printf ("Los bytes que ocupa el puntero son: %d\n", sizeof (var_ptr));
}