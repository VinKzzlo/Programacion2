/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pregunta01_programa_en_java;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author asant
 */
public class Pregunta01_Programa_En_JAVA {

    /**
     * @param args the command line arguments
     * @throws java.lang.Exception
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        Empresa empresa = new Empresa();
        File archivo = new File("Datos.txt");
        Scanner arch = new Scanner(archivo);
        
        empresa.leerBuses(arch);
        empresa.ubicarPasajeros(arch);
        empresa.imprimeBuses();
        
    }
    
}
