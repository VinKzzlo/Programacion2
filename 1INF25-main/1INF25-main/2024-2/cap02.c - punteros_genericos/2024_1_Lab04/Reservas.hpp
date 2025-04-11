#ifndef RESERVAS_HPP
#define RESERVAS_HPP

typedef struct {
    void *reservas[300];
    int cantidad;    
} ConjuntoReservas;

void inicializar_conjunto_de_reservas(ConjuntoReservas &conjuntoReservas);

void incluir_libro(ConjuntoReservas &conjuntoReservas, char *codigo_buffer, char *titulo_buffer, char *autor_buffer, int stock__buffer);

void incluir_fin_reserva(ConjuntoReservas &conjuntoReservas);

void operator>>(const ConjuntoReservas &conjuntoReservas, void *&reserva);

void imprimir_reservas_void(void *reserva);

void procesar_reserva(void *clientes, void *reserva, int dni_buffer, char *codigo_buffer);

void **buscar_bloque_del_libro(void *reserva, char *codigo_buffer);

#endif /* RESERVAS_HPP */

