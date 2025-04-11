/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package examen_23.pkg2_p1_java;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author asant
 */
public class PrimeraClase extends Pasajero{
    private final ArrayList<String> articulosSolicitados;
    
    public PrimeraClase(){
        articulosSolicitados = new ArrayList<>();
    }
    
    @Override
    public String getTipo(){
        return "P";
    }
    
    @Override
    public void leerDatos(Scanner arch){
        int numeroDeArticulos;
        String articulo;
        
        super.leerDatos(arch);
        numeroDeArticulos = arch.nextInt();
        for(int i=0;i<numeroDeArticulos;i++){
            articulo = arch.next();
            articulosSolicitados.add(articulo);            
        }
    }
    
    @Override
    public void imprimirDatos(){
        super.imprimirDatos();
        System.out.printf("Pasajero de Primera Clase - Extras:");
        for(String articulo: articulosSolicitados)
            System.out.printf("%s ", articulo);
        System.out.println();
        
    }
}
