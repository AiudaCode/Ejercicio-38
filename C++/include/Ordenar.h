#ifndef ORDENAR_H
#define ORDENAR_H


class Ordenar
{
    public:
        Ordenar();
        virtual ~Ordenar();
        void crearVector();
        void setVectorDatos(int p, int dato);
        int getVectorDatos(int p);
        void setNumElementos(int num);
        int getNumElementos();
        void cambiar(int p1, int p2);
        void ordenarBurbuja();
        void ordenarIntercambio();
        int posicionMenor(int inicio);
        void ordenarSeleccion();
        void ordenarShell();
        void ordenarQuickSort(int primero, int ultimo);
    protected:

    private:
        int *vectorDatos;
        int numElementos;
};

#endif // ORDENAR_H
