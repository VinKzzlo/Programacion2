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
public class MesaRegular extends Mesa{
    private String camarero;
    private boolean ocupadaSegundoTurno;

    public MesaRegular() {
        camarero = "";
        ocupadaSegundoTurno = false;
    }

    @Override
    public String getTipo() {
        return "R";
    }

    /**
     * @return the camarero
     */
    public String getCamarero() {
        return camarero;
    }

    /**
     * @param camarero the camarero to set
     */
    public void setCamarero(String camarero) {
        this.camarero = camarero;
    }

    /**
     * @return the ocupadaSegundoTurno
     */
    public boolean isOcupadaSegundoTurno() {
        return ocupadaSegundoTurno;
    }

    /**
     * @param ocupadaSegundoTurno the ocupadaSegundoTurno to set
     */
    public void setOcupadaSegundoTurno(boolean ocupadaSegundoTurno) {
        this.ocupadaSegundoTurno = ocupadaSegundoTurno;
    }

    @Override
    public void leerDatos(Scanner arch) {
        super.leerDatos(arch);
        camarero = arch.next();
    }
    
    
    
    
}
