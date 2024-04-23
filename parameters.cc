/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 19/02/2024
  * @brief Juego de la vida
  */
 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


struct parameters {
  int tipo_de_arbol;
  int init_code;
  std::string file_name;
  int numero_de_elementos;
};

parameters parse_args(int argc, char* argv[]) {
  std::vector<std::string> args(argv + 1, argv + argc);
  parameters options;
  for (auto it = args.begin(), end = args.end(); it != end; ++it) {
    if (*it == "-ab") {
      if (*++it == "abe") options.tipo_de_arbol = 0;
      else if (*it == "abb") options.tipo_de_arbol = 1;
    } 
    else if (*it == "-init") {
      *++it;
      if (*it == "manual") {
        options.init_code = 0;
      } else if (*it == "random") {
        options.init_code = 1;
        options.numero_de_elementos = std::stoi(*++it);
      } else if (*it == "file") {
        options.init_code = 2;
        options.numero_de_elementos = std::stoi(*++it);
        *++it;
        options.file_name = *it;
      }
    } 
    else if (*it == "-h") {
      std::cout << "Usage: " << argv[0] << " [-ab <abe|abb>] [-init <manual|random <n>|file <n> <file_name>]" << std::endl;
      exit(0);
    }
    else {
      std::cerr << "Error: invalid argument " << *it << std::endl;
      exit(1);
    }
  }
  return options;
}

  

void ImprimeMenu() {
  std::cout << "[0] Salir" << std::endl;
  std::cout << "[1] Insertar clave" << std::endl;
  std::cout << "[2] Buscar clave" << std::endl;
  std::cout << "[3] Mostrar arbol inorden" << std::endl;
}