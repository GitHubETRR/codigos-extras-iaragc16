
//FALTA ELIMINAR VEHICULO Y HACER USUARIOS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vehiculo {
public:
    string marca;
    string modelo;
    bool disponible;
    string patente;

    vehiculo(string marca, string modelo, string patente) : marca(marca), modelo(modelo), patente(patente), disponible(1) {} //constructor 

    virtual double calcularAlquiler(int dias) = 0; //polimorfismo
    virtual void mostrarDetalles() {
        cout << "Marca: " << marca << ", Modelo: " << modelo << ", Patente: " << patente <<  endl;
    }
};

class autito : public vehiculo {
public:
    double precioDia;

    autito(string marca, string modelo, string patente, double precioDia) : vehiculo(marca, modelo, patente), precioDia(precioDia) {}

    double calcularAlquiler(int dias) override {
        return dias * precioDia;
    }

    void mostrarDetalles() override {
        vehiculo::mostrarDetalles();
        cout << "   Tipo: auto, Precio por dia: $" << precioDia << endl;
        if(disponible){
            cout << "   Disponible" << endl;
        }else{
            cout << "   NO disponible" << endl;
        }
    }
};

class moto : public vehiculo {
public:
    double precioDia;

    moto(string marca, string modelo, string patente, double precioDia) : vehiculo(marca, modelo, patente), precioDia(precioDia) {}

    double calcularAlquiler(int dias) override {
        return dias * precioDia;
    }

    void mostrarDetalles() override {
        vehiculo::mostrarDetalles();
        cout << "   Tipo: moto, Precio por dia: $" << precioDia << endl;
        if(disponible){
            cout << "   Disponible" << endl;
        }else{
            cout << "   NO disponible" << endl;
        }
    }
};

class camioneta : public vehiculo {
public:
    double precioDia;

    camioneta(string marca, string modelo, string patente, double precioDia) : vehiculo(marca, modelo, patente), precioDia(precioDia) {}

    double calcularAlquiler(int dias) override {
        return dias * precioDia;
    }

    void mostrarDetalles() override {
        vehiculo::mostrarDetalles();
        cout << "   Tipo: camioneta, Precio por dia: $" << precioDia << endl;
        if(disponible){
            cout << "   Disponible" << endl;
        }else{
            cout << "   NO disponible" << endl;
        }
    }
};

class Agencia {
public:
    vector <vehiculo*> vehiculos; //Punteros a mis vehiculos (de tipo vehiculo) array dinámico

    void agregarvehiculo(vehiculo* vehiculo) { 
        vehiculos.push_back(vehiculo);
    }

    void mostrarCatalogo() {
        if (vehiculos.empty()) {
            cout << "No hay vehiculos en el catalogo." << endl;
        } else {
            for (int i = 0; i < vehiculos.size(); ++i) {
                cout << i + 1 << ". ";
                vehiculos[i]->mostrarDetalles();
            }
        }
    }

    void calcularAlquiler(int i, int dias) {
        if (i < 0 || i >= vehiculos.size()) {
            cout << "Vehiculo no valido." << endl;
        } else {
            cout << "El alquiler cuesta $" << vehiculos[i]->calcularAlquiler(dias) << " por " << dias << " dias" << endl;
        }
    }
};

int menu() {
    int opcion;
    cout << "\nMenu:" << endl;
    cout << "1. Mostrar catalogo" << endl;
    cout << "2. Calcular alquiler" << endl;
    cout << "3. Ingresar nuevo vehiculo" << endl;
    cout << "4. Alquilar vehiculo" << endl;
    cout << "5. Devolver vehiculo" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    return opcion;
}

int main() {
    Agencia miAgencia;

    // vehiculos iniciales
    miAgencia.agregarvehiculo(new autito("Toyota", "Corolla", "AA123AA", 50));
    miAgencia.agregarvehiculo(new moto("Harley", "Sportster", "BB123BB", 30));
    miAgencia.agregarvehiculo(new camioneta("Volvo", "FH16", "CC123CC", 100));

    int opcion;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                miAgencia.mostrarCatalogo();
                break;
            case 2: {
                int num, dias;
                cout << "Selecciona el numero del vehiculo: ";
                cin >> num;
                cout << "Ingrese el numero de dias de alquiler: ";
                cin >> dias;
                miAgencia.calcularAlquiler(num - 1, dias);
                break;
            }
            case 3: {
                int tipo;
                string marca, modelo, patente;
                double precioDia;
                cout << "Elige el tipo de vehiculo: " << endl;
                cout << "1. auto\n2. moto\n3. camioneta\n";
                cin >> tipo;
                cout << "Marca: ";
                cin >> marca;
                cout << "Modelo: ";
                cin >> modelo;
                cout << "Patente: ";
                cin >> patente;
                cout << "Precio por dia: ";
                cin >> precioDia;

                if (tipo == 1) {
                    miAgencia.agregarvehiculo(new autito(marca, modelo, patente, precioDia));
                } else if (tipo == 2) {
                    miAgencia.agregarvehiculo(new moto(marca, modelo, patente, precioDia));
                } else if (tipo == 3) {
                    miAgencia.agregarvehiculo(new camioneta(marca, modelo, patente, precioDia));
                }
                break;
            }
            case 4:{
                int num, dias;
                cout << "Selecciona el numero del vehiculo que quieras alquilar: ";
                cin >> num;
                while (!(miAgencia.vehiculos[(num-1)]->disponible)){
                cout << "\nEl vehiculo no esta disponible, elija otro vehiculo";
                cin >> num;
                }
                cout << "\nIngrese el numero de dias de alquiler: " << endl;
                cin >> dias;
                miAgencia.calcularAlquiler(num - 1, dias);
                miAgencia.vehiculos[(num-1)]->disponible = 0;
                break;
            } 
            case 5:{
                int num;
                cout << "Escriba el numero del vehiculo que desea devolver" << endl;
                cin >> num;
                if (miAgencia.vehiculos[(num-1)]->disponible){
                    cout << "La agencia ya cuenta con ese vehiculo" << endl; 
                }
                if (!(miAgencia.vehiculos[(num-1)]->disponible)){
                    miAgencia.vehiculos[(num-1)]->disponible = true;
                    cout << "El vehiculo ha sido ingresado" << endl;
                }
                if (num>miAgencia.vehiculos.size()){
                    cout << "Esta agencia no cuenta con ese vehiculo";
                }
                break;
            }
            case 0:
                cout << "FIN" << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 0);

    for (int i=0; i<miAgencia.vehiculos.size();i++) { //libera memoria
        delete miAgencia.vehiculos[i];
    }

    return 0;
}
