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



#ifndef AVL_H
#define AVL_H



#include <iostream>
#include "nodoavl.h"

template <class key> class NodoAVL;

template <class key>
class AVL : public ABB<key> {
  public:
  AVL() : ABB<key>() {}
  bool Insertar(const key& clave);
  void Inserta_bal(NodoAVL<key>* &nodo, NodoAVL<key>* nuevo, bool& crece);
  void insert_re_balancea_izda(NodoAVL<key>* &nodo, bool& crece);
  void insert_re_balancea_dcha(NodoAVL<key>* &nodo, bool& crece);
  void rotacion_II(NodoAVL<key>* &nodo);
  void rotacion_DD(NodoAVL<key>* &nodo);
  void rotacion_ID(NodoAVL<key>* &nodo);
  void rotacion_DI(NodoAVL<key>* &nodo);
  NodoAVL<key>*& root() {
    return reinterpret_cast<NodoAVL<key>*&>(ABB<key>::raiz_);
  }
};

template <class key>
bool AVL<key>::Insertar(const key& clave) {
  if (this->Buscar(clave)) return false;
  NodoAVL<key>* nuevo =  new NodoAVL<key>(clave);
  bool crece = false;
  Inserta_bal(this->root(), nuevo, crece);
  return true;
}


template <class key>
void AVL<key>::Inserta_bal(NodoAVL<key>* &nodo, NodoAVL<key>* nuevo, bool& crece) {
  if (nodo == NULL) {
    std::cout << "Nodo = NULL\n";
    nodo = nuevo;
    crece = true;
  }
  else if (nuevo->dato_ > nodo->dato_) {
    Inserta_bal(nodo->left(), nuevo, crece);
    if (crece) insert_re_balancea_izda(nodo, crece);
  }
  else {
    Inserta_bal(nodo->right(), nuevo, crece);
    if (crece) insert_re_balancea_dcha(nodo, crece);
  }
}



template <class key>
void AVL<key>::insert_re_balancea_izda(NodoAVL<key>* &nodo, bool& crece) {
  switch (nodo->bal_) {
    case -1: 
      nodo->bal_ = 0;
      crece = false;
      break;
    case 0:
      nodo->bal_ = 1;
      break;
    case 1:
    nodo->bal_ = 2;
      NodoAVL<key>* nodo1 = nodo->left();
      if (nodo1->bal_ == 1) {
        rotacion_II(nodo);
      }
      else {
        rotacion_ID(nodo);
        crece = false;
      }
      break; ////////////////////
  }
}



template <class key>
void AVL<key>::insert_re_balancea_dcha(NodoAVL<key>* &nodo, bool& crece) {
  switch (nodo->bal_) {
    case 1: 
      nodo->bal_ = 0;
      crece = false;
      break;
    case 0:
      nodo->bal_ = -1;
      break;
    case -1:
      nodo->bal_ = -2;
      NodoAVL<key>* nodo1 = nodo->right();
      if (nodo1->bal_ == -1) {
        rotacion_DD(nodo);
      }
      else {
        rotacion_DI(nodo);
        crece = false;
      }
      break; ////////////////////
  }
}



template <class key>
void AVL<key>::rotacion_II(NodoAVL<key>* &nodo) {
  NodoAVL<key>* nodo1 = nodo->left();
  nodo->left() = nodo1->right();
  nodo1->right() = nodo;
  if (nodo1->bal_ == 1) {
    nodo->bal_ = 0;
    nodo1->bal_ = 0;
  }
  else {
    nodo->bal_ = 1;
    nodo1->bal_ = -1;
  }
  nodo = nodo1;
}



template <class key>
void AVL<key>::rotacion_DD(NodoAVL<key>* &nodo) {
  NodoAVL<key>* nodo1 = nodo->right();
  nodo->right() = nodo1->left();
  nodo1->left() = nodo;
  if (nodo1->bal_ = -1) {
    nodo->bal_ = 0;
    nodo1->bal_ = 0;
  }
  else {
    nodo->bal_ = -1;
    nodo1->bal_ = 1;
  }
  nodo = nodo1;
}



template <class key>
void AVL<key>::rotacion_ID(NodoAVL<key>* &nodo) {
  NodoAVL<key>* nodo1 = nodo->left();
  NodoAVL<key>* nodo2 = nodo1->right();
  nodo->left() = nodo2->right();
  nodo2->right() = nodo;
  nodo1->right() = nodo2->left();
  nodo2->left() = nodo1;
  if (nodo2->bal_ == -1) {
    nodo1->bal_ = 1;
  }
  else {
    nodo1->bal_ = 0;
  }

  if (nodo2->bal_ == 1) {
    nodo->bal_ = -1;
  }
  else {
    nodo->bal_ = 0;
  }
  nodo2->bal_ = 0;
  nodo = nodo2;
}



template <class key>
void AVL<key>::rotacion_DI(NodoAVL<key>* &nodo) {
  NodoAVL<key>* nodo1 = nodo->right();
  NodoAVL<key>* nodo2 = nodo1->left();
  nodo->right() = nodo2->left();
  nodo2->left() = nodo;
  nodo1->left() = nodo2->right();
  nodo2->right() = nodo1;
  if (nodo2->bal_ == 1) {
    nodo1->bal_ = -1;
  }
  else {
    nodo1->bal_ = 0;
  }

  if (nodo2->bal_ == -1) {
    nodo->bal_ = 1;
  }
  else {
    nodo->bal_ = 0;
  }
  nodo2->bal_ = 0;
  nodo = nodo2;
}



#endif