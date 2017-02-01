#include <iostream>
#include "Ordenar.h"

using namespace std;

// metodo para mostrar los elementos del vector
void mostrarVector(Ordenar *obj)
{
    cout << "============ ELEMENTOS DEL VECTOR ============" << endl;
    for (int i = 0; i < obj->getNumElementos(); i++)
    {
        cout << "Posicion " << i << ": " << obj->getVectorDatos(i) << endl;
    }
}

int main(void)
{
    Ordenar *obj = new Ordenar();

    // declaramos una variable de tipo entero llamada num_elementos
    int num_elementos;
    // pedimos al usuario que digite el tamaño del vector
    cout << "Digite el numero de elementos del vector" << endl;
    cout << ">> ";
    // guardamos el tamaño en la variable num_elementos
    cin >> num_elementos;
    // encapsulamos la variable num_elementos
    obj->setNumElementos(num_elementos);
    // llamamos al metodo que creara el vector crearVector()
    obj->crearVector();
    // recorremos el vector con el ciclo for
    for(int i = 0; i < obj->getNumElementos(); i++)
    {
        // declaramos una variable de tipo entero llamada dato
        int dato;
        // pedimos al usuario que digite el elemento de cada posicion del vector
        cout << "Digite el elemento de la posicion " << i << endl;
        cout << ">> ";
        // guardamos cada elemento en la variable dato
        cin >> dato;
        // encapsulamos la variable dato en la posicion actual de i
        obj->setVectorDatos(i, dato);
    }

    // cuando se haya llenado el vector, se mostrara el mensaje
    cout << "Vector lleno." << endl;

    // llamamos al metodo mostrarVector() y le pasamos como parametro el objeto, obj para mostrar los datos actuales del vector
    mostrarVector(obj);
    // declaramos una variable de tipo entero llamada opcion
    int opcion;
    // ahora el usuario debera digitar la opcion con la que desea ordenar sus datos del vector
    cout << "====== Seleccione el Metodo de Ordenamiento ======" << endl << endl;
    cout << "1. Ordenamiento Burbuja" << endl;
    cout << "2. Ordenamiento por Intercambio" << endl;
    cout << "3. Ordenamiento por Seleccion" << endl;
    cout << "4. Ordenamiento por Shell" << endl;
    cout << "5. Ordenar por QuickSort" << endl;
    cout << ">> ";
    // se guarda en la variable opcion
    cin >> opcion;
    // dependiendo de la opcion digitada, el condicional switch eligira el metodo para ordenar y mostrar los elemento del vector
    switch(opcion)
    {
        case 1:
            obj->ordenarBurbuja();
            mostrarVector(obj);
            break;
        case 2:
            obj->ordenarIntercambio();
            mostrarVector(obj);
            break;
        case 3:
            obj->ordenarSeleccion();
            mostrarVector(obj);
            break;
        case 4:
            obj->ordenarShell();
            mostrarVector(obj);
            break;
        case 5:
            obj->ordenarQuickSort(0, obj->getNumElementos()-1);
            mostrarVector(obj);
            break;
        default:
            cout << "¡No selecciono una opción valida entre 1 y 5!" << endl;
            break;
    }
}
