
import javax.swing.JOptionPane;

public class Main
{
    public static void mostrarVector(Ordenar obj)
    {
        String datosVector = "";
        for (int i = 0; i < obj.getNumElementos(); i++)
        {
            datosVector = datosVector + String.valueOf("Posición " + i + ": " + obj.getVectorDatos(i) + "\n");
        }
        JOptionPane.showMessageDialog(null, "============ ELEMENTOS DEL VECTOR ============" + "\n" + datosVector);
    }
    public static void main(String[] args)
    {
        Ordenar obj = new Ordenar();
        
        int num_elementos = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite el Número de Elementos del Vector:"));
        
        obj.setNumElementos(num_elementos); //Se pasa el dato capturado al respectivo metodo modificador.
        //Se llama al metodo que crea el vector en tiempo de ejecución.
        obj.crearVector();
        for(int i = 0; i < obj.getNumElementos(); i++)
        {
            int dato = Integer.parseInt(JOptionPane.showInputDialog(null, "Digitar Elemento de la Posición " + i + ": "));
            obj.setVectorDatos(i, dato);
        }
        
        JOptionPane.showMessageDialog(null,"Vector Lleno");
        
        mostrarVector(obj);
        int opcion = Integer.parseInt(JOptionPane.showInputDialog("====== Seleccione el Metodo de Ordenamiento ====== \n" +
                "1. Ordenamiento Burbuja \n" +
                "2. Ordenamiento por Intercambio \n" +
                "3. Ordenamiento por Seleccion \n" +
                "4. Ordenamiento por Shell \n" +
                "5. Ordenar por QuickSort"));
        switch(opcion)
        {
            case 1:
                obj.ordenarBurbuja();
                mostrarVector(obj);
                break;
            case 2:
                obj.ordenarIntercambio();
                mostrarVector(obj);
                break;
            case 3:
                obj.ordenarSeleccion();
                mostrarVector(obj);
                break;
            case 4:
                obj.ordenarShell();
                mostrarVector(obj);
                break;
            case 5:
                obj.ordenarQuickSort(0, obj.getNumElementos()-1);
                mostrarVector(obj);
                break;    
            default:
                JOptionPane.showMessageDialog(null, "¡No selecciono una opción valida entre 1 y 5!");
                break;
        }
    }
}
