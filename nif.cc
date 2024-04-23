/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 15/03/2024
  * @brief Búsqueda mediante tablas de dispersión
  */



#include "nif.h"
#include <iostream>
#include <ctime>

/**
 * Constructor por defecto que inicializa el NIF a un valor aleatorio
 */
Nif::Nif() {
  srand(time(NULL));
    nif_ = rand();
    while (nif_ % 100000000 != nif_) {
      nif_ /= 10;
    }
}


/**
 * Constructor que inicializa el NIF a un valor dado
 * @param nif Valor del NIF
 */
Nif::Nif(const long& nif) {
  long new_nif = nif;
  while (new_nif / 100000000 == 0) {
    new_nif *= 10;
  }

  while (new_nif % 100000000 != new_nif) {
    new_nif /= 10;
  }

  nif_ = new_nif;
}


/**
 * Operador de asignación
 * @param num Valor del NIF
 */
// void Nif::operator=(int num) {
//   if (num / 100000000 != 0) {
//     while (num / 100000000 == 0) {
//       num *= 10;
//     }
//     while (num % 100000000 != num) {
//       num /= 10;
//   }
//   }
//   nif_ = num;
// }


/**
 * Operador de asignación
 * 
*/
void Nif::operator=(const Nif& nif) {
  nif_ = long(nif);
}



/**
 * Operador de comparación
 * @param nif NIF a comparar
 * @return true si son iguales, false en caso contrario
 */
bool Nif::operator==(const Nif& nif) const {
  return nif_ == nif.nif_;
  // return nif_ == long(nif);
}


/**
 * Operador de comparación
 * @param nif NIF a comparar
 * @return true si son distintos, false en caso contrario
 */
bool Nif::operator!=(const Nif& nif) const {
  return nif_ != nif.nif_;
}


/**
 * Operador de comparación
 * @param nif NIF a comparar
 * @return true si es menor, false en caso contrario
 */
bool Nif::operator<(const Nif& nif) const {
  return nif_ < nif.nif_;
}


/**
 * Operador de comparación
 * @param nif NIF a comparar
 * @return true si es mayor, false en caso contrario
 */
bool Nif::operator>(const Nif& nif) const {
  return nif_ > nif.nif_;
}

/**
 * Conversión implícita a long
 * @return Valor del NIF
 */
Nif::operator long() const {
  return nif_;
}