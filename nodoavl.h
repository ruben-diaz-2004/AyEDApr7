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



#ifndef NODO_AVL_H
#define NODO_AVL_H


template <class key>
class NodoAVL : public NodoB<key> {
  public:
  NodoAVL(const key& clave) : NodoB<key>(clave), bal_(0) {}

  NodoAVL<key>*& left() {
    return reinterpret_cast<NodoAVL<key>*&>(NodoB<key>::dcho_);
  }

  NodoAVL<key>*& right() {
    return reinterpret_cast<NodoAVL<key>*&>(NodoB<key>::izdo_);
  }


  int bal_; // Factor de balanceo del nodo
};



#endif