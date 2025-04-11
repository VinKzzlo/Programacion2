/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package proyecto05.arraylist;

import java.util.Scanner;

/**
 *
 * @author asant
 */
public class Persona {

    private int dni;
    private String nombre;
    private char sexo;
    private double sueldo;
    private boolean activo;

    //constructores
    public Persona() {
        sueldo = 0;
        activo = false;
    }

    public Persona(int dni, String nombre, char sexo, double sueldo,
            boolean activo) {
        this.dni = dni;
        this.nombre = nombre;
        this.sexo = sexo;
        this.sueldo = sueldo;
        this.activo = activo;
    }

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
     * @return the sexo
     */
    public char getSexo() {
        return sexo;
    }

    /**
     * @param sexo the sexo to set
     */
    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    /**
     * @return the sueldo
     */
    public double getSueldo() {
        return sueldo;
    }

    /**
     * @param sueldo the sueldo to set
     */
    public void setSueldo(double sueldo) {
        this.sueldo = sueldo;
    }

    /**
     * @return the activo
     */
    public boolean isActivo() {
        return activo;
    }

    /**
     * @param activo the activo to set
     */
    public void setActivo(boolean activo) {
        this.activo = activo;
    }

    public void leeDatos(Scanner arch) {
        String palabra;
        dni = arch.nextInt();
        palabra = arch.next();
        sexo = palabra.charAt(0);
        nombre = arch.next();
        sueldo = arch.nextDouble();
        activo = true;
    }

    public void imprimeDatos() {
        System.out.printf("%10d %-30s %3c %10.2f %-10b\n",
                dni, nombre, sexo, sueldo, activo);
    }

}
