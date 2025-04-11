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
public abstract class Pasajero {
    private int dni;
    private String nombre;
    private String destino;

    /**
     * @return the dni
     */
    public int getDni() {
        return dni;
    }

    /**
     * @param dni the dni to set
     */
    public void setDni(int dni) {
        this.dni = dni;
    }

    /**
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * @return the destino
     */
    public String getDestino() {
        return destino;
    }

    /**
     * @param destino the destino to set
     */
    public void setDestino(String destino) {
        this.destino = destino;
    }
    
    public abstract String getTipo();
    
    public void leerDatos(Scanner arch){
        dni = arch.nextInt();
        nombre = arch.next();
        destino = arch.next();
    }
    
    public void imprimirDatos(){
        System.out.printf("DNI: %10d  Nombre: %-40s  Destino: %-10s",
                           dni, nombre, destino);
        
    }
    
}
    