//NO FUNCIONA
#include <stdio.h>
#include <stdint.h> 
#include <string.h>

union numeros{
    struct{
        unsigned int signo: 1;
        unsigned int exponente: 8;
        unsigned int mantisa: 23;
    }num;
    float var;
    unsigned char vect[4];
};

union numeros NumeroCompleto (void);
union numeros NumeroPorPartes (void);
void MostrarNumero (void);


int main(void){
    union numeros numero;
    char opcion;
    printf("Presione 1 si desea ingresar el numero completo, presione 2 si desea ingresarlo por partes y presione 3 si desea ver el número\n");
    scanf("%d",&opcion);
    while(opcion!=1 && opcion!=2 && opcion!=3){
        printf("El numero ingresado no es 1 ni 2 ni 2. Presione 1 si desea ingresar el numero completo, presione 2 si desea ingresarlo por partes o presione 3 si desea ver el número \n");
        scanf("%d",&opcion);
    }
    while(opcion!=3){
        if(opcion==1){
            numero=NumeroCompleto();
        }
        if(opcion==2){
            numero=NumeroPorPartes();
        }
    }
    MostrarNumero();
}

union numeros NumeroCompleto (){
    union numeros numero;
    printf("Ingresa un numero \n");
    scanf("%f",&numero.var);
    return(numero);
}

void MostrarNumero (void){
    union numeros numero;
    printf("El numero que ingresaste es\n");
    for (int i = 3; i >= 0; i--){
        printf("%x",numero.vect[i]);
    }
}

union numeros NumeroPorPartes (){
    union numeros numero;
    int temp;
    printf("Ingresa un numero para el signo. 1 si es negativo y 0 si es positivo \n");   
    scanf("%d",&temp);
    while(temp!=1 && temp!=0){
        printf("El numero ingresado no es ni 1 ni 0. Presione 1 si desea que el numero sea negativo y o si desea que sea positivo\n");
        scanf("%d",&temp);
    }
    numero.num.signo=temp;
    printf("Ingresa un numero para el exponente entre 0 y 128 \n");
    scanf("%d",&temp);
    while(temp<=0 && temp>=128){
        printf("El numero ingresado no esta entre 0 y 128. Vuelva a ingresar el valor\n");
        scanf("%d",&temp);
    }
    numero.num.exponente=temp;
    printf("Ingresa un numero para la mantisa\n");
    scanf("%d",&temp);
    numero.num.mantisa=temp;
    return(numero);
}
