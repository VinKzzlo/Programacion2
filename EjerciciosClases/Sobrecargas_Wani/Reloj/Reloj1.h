
/* 
 * Archivo:   Reloj1.h
 * Autor:     Vinkzzlo
 *
 * Creado el 22 de octubre de 2024, 18:30
 */

#ifndef RELOJ1_H
#define RELOJ1_H

class Reloj1 {
private:
    int hora;
    int minuto;
    int segundo;
public:
    Reloj1(int h=0, int m=0, int s=0);
    //Argumentos por defecto, constructor con parametros
    void SetSegundo(int segundo);
    int GetSegundo() const;
    void SetMinuto(int minuto);
    int GetMinuto() const;
    void SetHora(int hora);
    int GetHora() const;
    //Sobrecarga ++prefijo
    void operator ++(void);
};

#endif /* RELOJ1_H */

