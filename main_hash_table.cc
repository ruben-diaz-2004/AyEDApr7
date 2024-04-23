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

#include <iostream>
#include <fstream>
#include "parameters.cc"
#include "arbolbinario.h"
#include "abequilibrado.h"
#include "abbusqueda.h"
#include "nif.h"
#include "nodob.h"

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

int main(int argc, char *argv[]) {
  parameters options = parse_args(argc, argv);

  AB<Nif>* arbol;
  switch (options.tipo_de_arbol) {
    case 0:
      arbol = new ABE<Nif>();
      break;
    case 1:
      arbol = new ABB<Nif>();
      break;
  }

  Nif* nif;
  long clave;
  switch (options.init_code) {
    case 0:
      // arbol->InicializarManual();
      std::cout << "Introduce las claves a insertar (0 para terminar):" << std::endl;
      while (true) {
        std::cin >> clave;
        if (clave == 0) {
          break;
        }
        nif = new Nif(clave);
        arbol->Insertar(*nif);
      }
      break;
    case 1:
      // arbol->InicializarAleatorio(options.numero_de_elementos);
      srand(time(NULL));
      for (int i{0}; i < options.numero_de_elementos; i++) {
        clave = rand();
        nif = new Nif(clave);
        arbol->Insertar(*nif);
      }
      break;
    case 2:
      // arbol->InicializarFichero(options.numero_de_elementos, options.file_name);
      std::ifstream file(options.file_name);
      for (int i{0}; i < options.numero_de_elementos; i++) { 
        file >> clave;
        nif = new Nif(clave);
        arbol->Insertar(*nif);
      }
      break;
  }


  int opcion;
  bool running = true;
  while (running) {
    std::cout << std::endl;
    ImprimeMenu();
    std::cin >> opcion;
    switch (opcion) {
      case 0:
        running = false;
        break;
      case 1:
        std::cout << "Introduce la clave a insertar: ";
        std::cin >> clave;
        nif = new Nif(clave);
        arbol->Insertar(*nif);
        break;
      case 2:
        std::cout << "Introduce la clave a buscar: ";
        std::cin >> clave;
        nif = new Nif(clave);
        if (arbol->Buscar(*nif)) {
          std::cout << "Clave encontrada" << std::endl;
        } else {
          std::cout << "Clave no encontrada" << std::endl;
        }
        break;
      case 3:
        arbol->Inorden(arbol->raiz_);
        std::cout << std::endl;
        break;
      default:
        std::cout << *arbol << std::endl;
        break;
    }
    std::cout << *arbol << std::endl;
  } 


  return 0;
}