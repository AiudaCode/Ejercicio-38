#include "Ordenar.h"
#include <iostream>

using namespace std;

Ordenar::Ordenar()
{
    // al inicializar el constructor se definiran los valores iniciales de los atributos
    vectorDatos = NULL;
    numElementos = 0;
}

Ordenar::~Ordenar()
{
    //dtor
}

// metodo para crear el vector en tiempo de ejecución, posteriormente se asignara su tamaño
void Ordenar::crearVector()
{
    vectorDatos = new int[numElementos];
}

// metodos Setter y Getters de los atributos de la clase
void Ordenar::setVectorDatos(int p, int dato)
{
    vectorDatos[p] = dato;
}

int Ordenar::getVectorDatos(int p)
{
    return vectorDatos[p];
}

void Ordenar::setNumElementos(int num)
{
    numElementos = num;
}

int Ordenar::getNumElementos()
{
    return numElementos;
}

// metodo que permite intercambiar los elementos de dos posiciones del vector
void Ordenar::cambiar(int p1, int p2)
{
    int temp;
    temp = getVectorDatos(p1);
    setVectorDatos(p1, getVectorDatos(p2));
    setVectorDatos(p2, temp);
}

// método de ordenamiento Burbuja, este método compara elementos de la posición j
//con la posición j+1, es decir compara dos posiciones seguidas o continuas del vector
void Ordenar::ordenarBurbuja()
{
    for (int i = 0; i < getNumElementos(); i++)
    {
        for (int j = 0; j < getNumElementos()-2; j++)
        {
            // ordeno de menor a mayor, si se quiere hacer de mayor a menor simplemente cambie el signo, aquí se
            // compara si el elemento de la izquierda (j) es mayor que el elemento contiguo de la derecha (j+1).
            // si se cumple la condición los intercambia
            if (getVectorDatos(j) > getVectorDatos(j+1))
            {
                // para hacer el intercambio en los elementos se llama al método cambiar.
                cambiar(j, j+1);
            }
        }
    }
}

// método de ordenamiento por intercambio, este método compara un elemento de la
// posición i con todos los que le siguen, es decir con los de la posición i+1,i+2,i+3...
void Ordenar::ordenarIntercambio()
{
    for (int i = 0; i < getNumElementos(); i++)
    {
        for (int j = i+1; j < getNumElementos(); j++)
        {
            // ordeno de menor a mayor, si se quiere hacer de mayor a menor simplemente cambie el signo, aquí compara
            // si el elemento de la posición (i) a la izquierda es mayor que el elemento de la posición (j) ubicado hacia la derecha
            if (getVectorDatos(i) > getVectorDatos(j))
            {
                cambiar(i, j);
            }
        }
    }
}

// método auxiliar para buscar la posición del elemento mas pequeño del vector y realizar el intercambio
int Ordenar::posicionMenor(int inicio)
{
    // variable para establecer la posición en el vector del elemento menor
    int posMenor;
    // variable para representar el elemento menor del vector
    int menorElemento;
    posMenor = inicio;
    // a continuación se asume que el elemento mas pequeño del vector esta en la primera posición
    menorElemento = getVectorDatos(inicio);
    for (int i = inicio+1; i < getNumElementos(); i++)
    {
        // se compara si el elemento de la posición i es menor que el elemento menor
        if (getVectorDatos(i) < menorElemento)
        {
            menorElemento = getVectorDatos(i);
            posMenor = i;
        }
    }
    // se devuelve la posición en donde esta el elemento menor del vector para realizar el intercambio hacia la primera posición
    return posMenor;
}

// método que ordena el vector, llamando al método auxiliar posicionMenor() para realizar el intercambio
void Ordenar::ordenarSeleccion()
{
    for (int i = 0; i < getNumElementos(); i++)
    {
        cambiar(i, posicionMenor(i));
    }
}

// los siguientes metodos de ordenamientos son algo complejos por lo que recomendamos buscar mas informacion adicional para entender
void Ordenar::ordenarShell()
{
    int n, cont;
    n = (getNumElementos()-1)/2;
    while (n != 0)
    {
        cont = 1;
        while (cont != 0)
        {
            cont = 0;
            for(int i = n; i < getNumElementos(); i++)
            {
                if(getVectorDatos(i-n) > getVectorDatos(i))
                {
                    cambiar(i, i-n);
                    cont = cont + 1;
                }
            }
        }
        n = n/2;
    }
}

void Ordenar::ordenarQuickSort(int primero, int ultimo)
{
    int i, j, centro;
    int pivote;
    centro = (primero + ultimo)/2;
    pivote = getVectorDatos(centro);
    i = primero;
    j = ultimo;
    do
    {
        while ((i <= j) && (getVectorDatos(i) < pivote))
        {
            i = i + 1;
        }
        while((i <= j) && (getVectorDatos(j) > pivote))
        {
            j = j - 1;
        }
        if(i <= j)
        {
            cambiar(i, j);
            i = i + 1;
            j = j - 1;
        }
    }
    while (i <= j);

    if(primero < j)
    {
        ordenarQuickSort(primero, j);
    }
    if(i < ultimo)
    {
        ordenarQuickSort(i, ultimo);
    }
}
