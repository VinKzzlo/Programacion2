/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package proyecto04.leepersona;

import java.io.File;
import java.util.Locale;
import java.util.Scanner;

/**
 *
 * @author asant
 */
public class Proyecto04LeePersona {

    /**
     * @param args the command line arguments
     * @throws java.lang.Exception
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        File archivo = new File("person.txt");
        Scanner arch = new Scanner(archivo);
        Persona persona = new Persona();
////        arch.useLocale(Locale.US);
        while(arch.hasNext()){
            persona.leeDatos(arch);
            persona.imprimeDatos();
        }
//        Persona persona1 = new Persona(20223006, "Yoshimar Yotun", 'M', 1585.25, true);
//        persona1.imprimeDatos();
    }
    
}
