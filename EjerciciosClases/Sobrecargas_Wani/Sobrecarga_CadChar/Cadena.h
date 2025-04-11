
/* 
 * Archivo:   Cadena.h
 * Autor:     VinKzzlo
 *
 * Created on 27 de octubre de 2024, 21:11
 */

#ifndef CADENA_H
#define CADENA_H

class Cadena {
private:
    char *cad;
public:
    Cadena();
    void SetCad(const char* cad);
    void GetCad(char*) const;
    void imprimeCad(void);
    void operator + (const class Cadena&);
};

#endif /* CADENA_H */

