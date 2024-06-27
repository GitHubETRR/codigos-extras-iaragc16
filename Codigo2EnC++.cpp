#include <iostream>
using namespace std;

class calculadora{
    public:
        float var1 = 0;
        float var2 = 0;
        float resultado;

        void sumar (){
            resultado = var1+var2;
            cout<<"el resultado es "<<resultado<<"\n";
        };
        void restar (){
            resultado = var1-var2;
            cout<<"el resultado es "<<resultado<<"\n";
        };
        void dividir (){
            resultado = var1/var2;
            cout<<"el resultado es "<<resultado<<"\n";
        };
        void multiplicar (){
            resultado = var1*var2;
            cout<<"el resultado es "<<resultado<<"\n";
        };
}micalc;

int main(){
    int opcion=1; 
    while(opcion!=0){
        cout<<"Escriba 1 para sumar, 2 para restar, 3 para dividir, 4 para multiplicar y 0 para salir.\n";
        cin>>opcion;
        if(opcion==1){
            cout<<"Escriba el valor de la primera variable\n";
            cin>>micalc.var1;
            cout<<"Escriba el valor de la segunda variable\n";
            cin>>micalc.var2;    
            micalc.sumar();
        }
        if(opcion==2){
            cout<<"Escriba el valor del minuendo\n";
            cin>>micalc.var1;
            cout<<"Escriba el valor del sustraendo\n";
            cin>>micalc.var2;    
            micalc.restar(); 
        }
        if(opcion==3){
            cout<<"Escriba el valor del numerador\n";
            cin>>micalc.var1;
            cout<<"Escriba el valor del denominador\n";
            cin>>micalc.var2;    
            micalc.dividir(); 
        }
        if(opcion==4){
            cout<<"Escriba el valor de la primera variable\n";
            cin>>micalc.var1;
            cout<<"Escriba el valor de la segunda variable\n";
            cin>>micalc.var2;
            micalc.multiplicar();
        }
        }
} 