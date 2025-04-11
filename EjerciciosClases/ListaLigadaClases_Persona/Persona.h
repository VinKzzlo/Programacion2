/* 
 * Archivo:   Persona.h
 * Autor:     VinKzzlo
 *
 * Creado el  5 de noviembre de 2024, 9:35
 */

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    int dni;
    char *nombre;
    double precio;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *cad) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator=(const Persona &per);
};

void operator>>(ifstream &, class Persona &per);

#endif /* PERSONA_H */

