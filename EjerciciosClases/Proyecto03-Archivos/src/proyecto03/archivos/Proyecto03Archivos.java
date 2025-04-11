/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package proyecto03.archivos;

import java.io.File;
import java.util.Locale;
import java.util.Scanner;

/**
 *
 * @author asant
 */
public class Proyecto03Archivos {

    /**
     * @param args the command line arguments
     * @throws java.lang.Exception
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        File archivo = new File("personal.txt");
        Scanner arch = new Scanner(archivo);
        arch.useLocale(Locale.US);
        Persona persona = new Persona();
        int dni;
        String nombre, palabra;
        char sexo;
        double sueldo;
        while(arch.hasNext()){
            dni = arch.nextInt();
            palabra = arch.next();
            sexo = palabra.charAt(0);
            nombre = arch.next();
            sueldo = arch.nextDouble();
            persona.setDni(dni);
            persona.setSexo(sexo);
            persona.setNombre(nombre);
            persona.setSueldo(sueldo);
            persona.setActivo(true);
            persona.imprimeDatos();
        }
    }
    
}
