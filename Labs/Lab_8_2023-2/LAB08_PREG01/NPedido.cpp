/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:27 PM
 */

#include "NPedido.h"

NPedido::NPedido() {
    cantidad=0;
    codigo=nullptr;
    peso=0;
    sig=nullptr;
}

NPedido::~NPedido() {
    if(codigo)delete[] codigo;
}

