public class Ordenar
{
    private int vectorDatos[];
    private int numElementos;
    
    public Ordenar()
    {
        vectorDatos = null;
        numElementos = 0;
    }
    
    public void crearVector()
    {
        vectorDatos = new int[numElementos];
    }
    
    public void setVectorDatos(int p, int dato)
    {
        vectorDatos[p] = dato;
    }
    //Se implementa el metodo que permitira obtener los elementos del vector.
    public int getVectorDatos(int p)
    {
        return vectorDatos[p];
    }
    
    public void setNumElementos(int num)
    {
        numElementos = num;
    }
    
    public int getNumElementos()
    {
        return numElementos;
    }
    
    public void cambiar(int p1, int p2)
    {
        int temp;
        temp = getVectorDatos(p1);
        setVectorDatos(p1, getVectorDatos(p2));
        setVectorDatos(p2, temp);
    }
    
    public void ordenarBurbuja()
    {
        int i, j;
        for (i = 0; i < getNumElementos(); i++)
        { 
            for (j = 0; j < getNumElementos()-2; j++)
            {
                if (getVectorDatos(j) > getVectorDatos(j+1))
                {
                    cambiar(j, j+1);
                }
            }
        }
    }
    
    public void ordenarIntercambio()
    {
        int i, j;
        for (i = 0; i < getNumElementos(); i++)
        {
            for (j = i+1; j < getNumElementos(); j++)
            {
                if (getVectorDatos(i) > getVectorDatos(j))
                {
                    cambiar(i, j);
                }
            }
        }
    }
    
    public int posicionMenor(int inicio)
    {
        int i;
        int posMenor;
        int menorElemento;
        posMenor = inicio;
        menorElemento = getVectorDatos(inicio);
        for (i = inicio+1; i < getNumElementos(); i++)
        {
            if (getVectorDatos(i) < menorElemento)
            {
                menorElemento = getVectorDatos(i);
                posMenor = i;
            }
        }
        return posMenor;
    }
    
    public void ordenarSeleccion()
    {
        for (int i = 0; i < getNumElementos(); i++)
        {
            cambiar(i, posicionMenor(i));
        }
    }
    
    public void ordenarShell()
    {
        int i, n, cont;
        n = (getNumElementos()-1)/2;
        while (n != 0)
        {
            cont = 1;
            while (cont != 0)
            {
                cont = 0;
                for(i = n; i < getNumElementos(); i++)
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
    
    public void ordenarQuickSort(int primero, int ultimo)
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
}