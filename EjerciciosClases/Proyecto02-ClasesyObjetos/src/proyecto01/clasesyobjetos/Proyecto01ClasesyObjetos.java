/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package proyecto01.clasesyobjetos;

/**
 *
 * @author asant
 */
public class Proyecto01ClasesyObjetos {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //Primero crear los objetos
        Persona persona;
        Persona persona2;
        Persona persona3;
        //Instancias las clases
        persona = new Persona(2402020, "Juan Perez Gomez", 'm', 5746.63, true);
        persona.imprimeDatos();
        
        persona2 = new Persona();
        persona2.setDni(7171717);
        persona2.setNombre("Maria Ruiz Lopez");
        persona2.setSexo('F');
        persona2.setSueldo(8435.55);
        persona2.setActivo(true);
        persona2.imprimeDatos();
        
        persona3 = persona;
        
        persona3.setDni(111111);
        persona.imprimeDatos();
        persona3.imprimeDatos();
    }
    
}
