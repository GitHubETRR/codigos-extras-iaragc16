#include <iostream>
using namespace std;

class triangulo{
    public:
        float area;
        float base;
        float altura;
        void calcarea (){
            area = base*altura/2;
            cout<<"el area es "<<area;
        };
        void calcaltura (){
            altura = area/base*2;
            cout<<"la altura es "<<altura;
        };
        void calcbase (){
            base = area/altura*2;
            cout<<"la base es "<<base;
        };
}mitriangulo;

int main(){
do{
    cout<<"Escriba la altura del triangulo, si no la sabe escriba 0\n";
    cin>>mitriangulo.altura;
    cout<<"Escriba la base del triangulo, si no la sabe escriba 0\n";
    cin>>mitriangulo.base;
    cout<<"Escriba el area del triangulo, si no la sabe escriba 0\n";
    cin>>mitriangulo.area;
    if ((mitriangulo.base==0 && mitriangulo.altura==0) || (mitriangulo.base==0 && mitriangulo.area ==0) || (mitriangulo.area==0 && mitriangulo.altura==0)){
        cout<<"No hay suficiente informacion\n";
    }
}while((mitriangulo.base==0 && mitriangulo.altura==0) || (mitriangulo.base==0 && mitriangulo.area ==0) || (mitriangulo.area==0 && mitriangulo.altura==0));
if (mitriangulo.base==0){
    mitriangulo.calcbase();
}
if (mitriangulo.altura==0){
    mitriangulo.calcaltura();
}
if (mitriangulo.area==0){
    mitriangulo.calcarea();
}
}