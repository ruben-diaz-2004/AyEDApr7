/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 13/04/2024
  * @brief árbol binario de búsqueda
  */


#ifndef NODOB_H
#define NODOB_H

#include <iostream>


template <class key>
class NodoB {
  public:
    // Constructor
    NodoB(const key& dato, NodoB<key>* izdo = NULL, NodoB<key>* dcho = NULL): dato_(dato), izdo_(izdo), dcho_(dcho) {}

    // Miembros
    key dato_;
    NodoB<key>* izdo_;
    NodoB<key>* dcho_;
};

#endif