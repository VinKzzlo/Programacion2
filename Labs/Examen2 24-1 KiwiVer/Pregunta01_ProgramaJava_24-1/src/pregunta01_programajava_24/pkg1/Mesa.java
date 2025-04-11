/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pregunta01_programajava_24.pkg1;

import java.util.Scanner;

/**
 *
 * @author asant
 */
public abstract class  Mesa {
    private String codigo;
    private String ubicacion;
    private int capacidad;
    private boolean ocupadaPrimerTurno;

    public Mesa() {
        codigo = "";
        ubicacion = "";
        capacidad = 0;
        ocupadaPrimerTurno = false;
    }

    /**
     * @return the codigo
     */
    public String getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    /**
     * @return the ubicacion
     */
    public String getUbicacion() {
        return ubicacion;
    }

    /**
     * @param ubicacion the ubicacion to set
     */
    public void setUbicacion(String ubicacion) {
        this.ubicacion = ubicacion;
    }

    /**
     * @return the capacidad
     */
    public int getCapacidad() {
        return capacidad;
    }

    /**
     * @param capacidad the capacidad to set
     */
    public void setCapacidad(int capacidad) {
        this.capacidad = capacidad;
    }

    /**
     * @return the ocupadaPrimerTurno
     */
    public boolean isOcupadaPrimerTurno() {
        return ocupadaPrimerTurno;
    }

    /**
     * @param ocupadaPrimerTurno the ocupadaPrimerTurno to set
     */
    public void setOcupadaPrimerTurno(boolean ocupadaPrimerTurno) {
        this.ocupadaPrimerTurno = ocupadaPrimerTurno;
    }
    
    public abstract String getTipo();
    
    public void leerDatos(Scanner arch){
        codigo = arch.next();
        ubicacion = arch.next();
        capacidad = arch.nextInt();
    }
    
    public void imprimeDatos(){
        System.out.printf("Codigo: %-10s\n", getCodigo());
        System.out.printf("Ubicacion: %-20s\n", getUbicacion());
        System.out.printf("Capacidad: %10d\n", getCapacidad());
        if(isOcupadaPrimerTurno())
            System.out.println("Ocupada para las 07:30 p.m.");
    }
    
}
