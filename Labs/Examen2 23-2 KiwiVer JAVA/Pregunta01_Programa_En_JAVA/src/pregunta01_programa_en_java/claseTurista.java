/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pregunta01_programa_en_java;

import java.util.Scanner;

/**
 *
 * @author asant
 */
public class claseTurista extends Pasajero{
    private boolean valija;
    private boolean almuerzo;
    private double tarifaExtra;

    public claseTurista() {
        valija = false;
        almuerzo = false;
        tarifaExtra = 0.0;
    }

    @Override
    public String getTipo() {
        return "T";
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
    public void leerDatos(Scanner arch) {
        String lleva;
        super.leerDatos(arch);
        lleva = arch.next();
        if(lleva.compareTo("S")==0){
            valija = true;
            tarifaExtra += 85.5;
        }
        lleva = arch.next();
        if(lleva.compareTo("S")==0){
            almuerzo = true;
            tarifaExtra += 55.90;
        }
    }

    @Override
    public void imprimeDatos() {
        super.imprimeDatos();
        System.out.print("  Pasajero de Clase Turista - Extras: ");
        if(isValija()) System.out.print("Valija ");
        if(isAlmuerzo()) System.out.print("Almuerzo ");
        System.out.printf(" - Tarifa extra: %8.2f\n", tarifaExtra);
    }
    
    
    
}
