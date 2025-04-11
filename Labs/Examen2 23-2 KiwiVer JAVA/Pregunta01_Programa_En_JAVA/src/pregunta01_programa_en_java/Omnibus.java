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
public class Omnibus {
    private String placa;
    private String chofer;
    private final ArrayList<String> ruta;
    private int asientosPC;
    private int asientosCT;
    private final ArrayList<Pasajero> pasajeros;

    public Omnibus(){
        ruta = new ArrayList<>();
        pasajeros = new ArrayList<>();
    }
    
    /**
     * @return the placa
     */
    public String getPlaca() {
        return placa;
    }

    /**
     * @param placa the placa to set
     */
    public void setPlaca(String placa) {
        this.placa = placa;
    }

    /**
     * @return the chofer
     */
    public String getChofer() {
        return chofer;
    }

    /**
     * @param chofer the chofer to set
     */
    public void setChofer(String chofer) {
        this.chofer = chofer;
    }

    /**
     * @return the asientosPC
     */
    public int getAsientosPC() {
        return asientosPC;
    }

    /**
     * @param asientosPC the asientosPC to set
     */
    public void setAsientosPC(int asientosPC) {
        this.asientosPC = asientosPC;
    }

    /**
     * @return the asientosCT
     */
    public int getAsientosCT() {
        return asientosCT;
    }

    /**
     * @param asientosCT the asientosCT to set
     */
    public void setAsientosCT(int asientosCT) {
        this.asientosCT = asientosCT;
    }
    
    public boolean leerDatos(Scanner arch){
        String ciudad;
        
        setPlaca(arch.next());
        
        if(getPlaca().compareTo("FIN")==0) return false;
        
        setChofer(arch.next());
        
        while(!arch.hasNextInt()){
            ciudad = arch.next();
            ruta.add(ciudad);
        }
        
        setAsientosPC(arch.nextInt());
        setAsientosCT(arch.nextInt());
        
        return true;
    }
    
    public boolean sePuedeUbicar(Pasajero pasajero){
        String destino, tipoPasajero;
        
        destino = pasajero.getDestino();
        tipoPasajero = pasajero.getTipo();
        
        if(pasaPor(destino)){
            if(tipoPasajero.equals("P") && getAsientosPC()>0){
                pasajeros.add(pasajero);
                setAsientosPC(getAsientosPC()-1);
                return true;
            }
            else
                if(tipoPasajero.equals("T") && getAsientosCT()>0){
                    pasajeros.add(pasajero);
                    setAsientosCT(getAsientosCT()-1);
                    return true;
                }
        }
        return false;
        
    }
    
    public boolean pasaPor(String destino){
        for(String ciudad: ruta)
            if(ciudad.equals(destino)) return true;
        return false;
    }
    
    
    public void imprimeDatos(){
        int n=1;
        System.out.printf("Placa: %s\n", getPlaca());
        System.out.printf("Chofer: %s\n", getChofer());
        System.out.printf("Asientos Libres Primera Clase: %3d\n", getAsientosPC());
        System.out.printf("Asientos Libres Clase Turista: %3d\n", getAsientosCT());
        System.out.print("RUTA: ");
        for(String ciudad: ruta)
            System.out.printf("  %s",ciudad);
        System.out.println();
        System.out.println("Pasajeros: ");
        for(Pasajero pasajero: pasajeros){
            System.out.printf("%3d) ",n);
            pasajero.imprimeDatos();
            n++;
        }
    }
    
}
