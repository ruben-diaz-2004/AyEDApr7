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


#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>
#include "nodob.h"
#include <queue>


template <class key> class NodoB;

template <class key>
class AB {
  public:
  AB(): raiz_(nullptr) {}
  ~AB() { Podar(raiz_); }
  void Podar(NodoB<key>* &nodo);
  virtual bool Insertar(const key& k) = 0;
  virtual bool Buscar(const key& k) = 0;
  void Inorden(NodoB<key>* nodo) const;
  const int Tamano() { return TamRama(raiz_); }
  const int TamRama(NodoB<key>* nodo);
  const int Altura() { return AlturaN(raiz_); }
  const int AlturaN(NodoB<key>* nodo);
  // void RecorreN(NodoB<key>* nodo);
  // Sobrecarga del operador salida para impresión por niveles
  friend std::ostream& operator<<(std::ostream& os, const AB<key>& arbol) {
    std::queue<std::pair<NodoB<key>*, int>> cola;
    NodoB<key>* nodo_actual;
    NodoB<key>* raiz = arbol.raiz_;
    int nivel, nivel_actual = 0;
    cola.push(std::make_pair(raiz, 0));
    os << "Nivel " << nivel_actual << ": ";
    while (!cola.empty()) {
      nodo_actual = cola.front().first;
      nivel = cola.front().second;
      cola.pop();
      if (nivel > nivel_actual) {
        os << std::endl;
        os << "Nivel " << nivel << ": ";
        nivel_actual = nivel;
      }
      if (nodo_actual != NULL) {
        os << "[" << nodo_actual->dato_ << "] ";
        cola.push(std::make_pair(nodo_actual->izdo_, nivel + 1));
        cola.push(std::make_pair(nodo_actual->dcho_, nivel + 1));
      } else {
        os << "[.] ";
      }
    }
    return os;
  }

  // protected:
  NodoB<key>* raiz_;
};


/**
 * @brief Podar un árbol binario
 * @param nodo Nodo a podar
*/
template <class key>
void AB<key>::Podar(NodoB<key>* &nodo) {
  if (nodo == NULL) return;
  Podar(nodo->izdo_);
  Podar(nodo->dcho_);
  delete nodo;
  nodo = NULL;
}



/**
 * @brief Recorre un árbol en inorden
 * @param nodo Nodo a recorrer
*/
template <class key>
void AB<key>::Inorden(NodoB<key>* nodo) const {
  if (nodo == NULL) return;
  Inorden(nodo->izdo_);
  // Procesa(nodo->clave_);
  std::cout << nodo->dato_ << std::endl;
  Inorden(nodo->dcho_);
}



/**
 * @brief Calcula el tamaño de un árbol
 * @param nodo Nodo a calcular
*/
template <class key>
const int AB<key>::TamRama(NodoB<key>* nodo) {
  if (nodo == NULL) return 0;
  return (1 + TamRama(nodo->izdo_) + TamRama(nodo->dcho_));
}



/**
 * @brief Calcula la altura de un árbol
 * @param nodo Nodo a calcular
*/
template <class key>
const int AB<key>::AlturaN(NodoB<key>* nodo) {
  if (nodo == NULL) return 0;
  int alt_izq = AlturaN(nodo->izdo_);
  int alt_dcho = AlturaN(nodo->dcho_);
  if (alt_dcho > alt_izq) return ++alt_dcho;
  return ++alt_izq;
}







#endif