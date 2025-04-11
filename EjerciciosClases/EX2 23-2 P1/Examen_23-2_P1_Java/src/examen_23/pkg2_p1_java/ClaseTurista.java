/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package examen_23.pkg2_p1_java;

import java.util.Scanner;

/**
 *
 * @author asant
 */
public class ClaseTurista extends Pasajero{
    private boolean valija;
    private boolean almuerzo;
    private double tarifaExtra;

    public ClaseTurista() {
        valija = false;
        almuerzo = false;
        tarifaExtra = 0.0;
    }

    /**
     * @return the valija
     */
    public boolean isValija() {
        return valija;
    }

    /**
     * @param valija the valija to set
     */
    public void setValija(boolean valija) {
        this.valija = valija;
    }

    /**
     * @return the almuerzo
     */
    public boolean isAlmuerzo() {
        return almuerzo;
    }

    /**
     * @param almuerzo the almuerzo to set
     */
    public void setAlmuerzo(boolean almuerzo) {
        this.almuerzo = almuerzo;
    }

    /**
     * @return the tarifaExtra
     */
    public double getTarifaExtra() {
        return tarifaExtra;
    }

    /**
     * @param tarifaExtra the tarifaExtra to set
     */
    
    public void setTarifaExtra(double tarifaExtra) {
        this.tarifaExtra = tarifaExtra;
    }
    
    @Override
    public String getTipo(){
        return "P";
    }
    
    @Override
    public void leerDatos(Scanner arch){
        String SN;
        
        super.leerDatos(arch);
        
        SN = arch.next();
        if(SN.compareTo("S")==0){
            valija = true;
            tarifaExtra += 85.5;
        }
        
        SN = arch.next();
        if(SN.compareTo("S")==0){
            almuerzo = true;
            tarifaExtra += 55.90;
        }
    }
    
    @Override
    public void imprimirDatos(){
        super.imprimirDatos();
        System.out.printf("Pasajero de Clase Turista - Extras:");
        if(isValija())
            System.out.printf("Valija ");
        if(isAlmuerzo())
            System.out.printf("Almuerzo ");
        System.out.printf("Tarifa Extra: %f\n", tarifaExtra);
        System.out.println();
        
    }
}
