/* 
 * Archivo:   Persona.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de octubre de 2024, 23:59
 */

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    int dni;
    char *nombre;
    double sueldo;
public:
    Persona(void);
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(char* nombre);
    char* GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;

};

istream & operator >>(istream &, class Persona &);
ostream & operator <<(ostream &, const class Persona &);

#endif /* PERSONA_H */

