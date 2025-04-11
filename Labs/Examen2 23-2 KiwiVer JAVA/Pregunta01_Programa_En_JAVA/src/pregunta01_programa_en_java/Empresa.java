/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pregunta01_programa_en_java;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author asant
 */
public class Empresa {
    private final ArrayList<Omnibus> flota;

    public Empresa() {
        flota = new ArrayList<>();
    }
    
    public void leerBuses(Scanner arch){
        Omnibus omnibus;
        
        while(true){
            omnibus = new Omnibus();
            if(!omnibus.leerDatos(arch)) return;
            flota.add(omnibus);
        }
        
    }
    
    public void ubicarPasajeros(Scanner arch){
        Pasajero pasajero;
        String tipo;
        
        while(arch.hasNext()){
            tipo = arch.next();
            if(tipo.compareTo("P")==0) pasajero = new PrimeraClase();
            else pasajero = new claseTurista();
            pasajero.leerDatos(arch);
            
            for(Omnibus omnibus: flota){
                if(omnibus.sePuedeUbicar(pasajero)) break;
            }
            
        }
        
    }
    
    public void imprimeBuses(){
        int n=1;
        System.out.println("EMPRESA DE TRANSPORTE TURISTICO");
        for(Omnibus omnibus: flota){
            for(int i=0;i<99;i++) System.out.print("=");
            System.out.println();
            System.out.printf("OMNIBUS NRO: %3d\n",n);
            omnibus.imprimeDatos();
            n++;
        }
    }
    
    
}
