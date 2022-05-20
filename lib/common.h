/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file common.h
 * @brief Incluye definiciones generales y tipos de datos globales para el proyecto.
 */

#ifndef TURBOCODES_COMMON_H
#define TURBOCODES_COMMON_H

#include <array>
#include <bitset>
#include <cstdint>

namespace ttc {

  // Número de estados que tendrá el RSC.
  // Se recomienda números bajos para mayor eficiencia, ya que reduce el número de operaciones para codificar un bit.
  constexpr uint8_t STATES_SIZE = 2;

  // Tamaño del mensaje a codificar.
  // Se recomienda que sea múltiplo de 8 para mayor eficiencia debido a que los bitsets aumentan su tamaño de 8 en 8.
  constexpr uint16_t MESSAGE_SIZE = 256;

  // Almacena un conjunto de bits de tamaño MESSAGE_SIZE.
  typedef std::bitset<MESSAGE_SIZE> BitsSet;

  // Un array de tamaño STATES_SIZE que almacena un conjunto de estados.
  // Cada estado corresponderá a cada una de las posiciones dentro del array, y cada valor que haya tomado el estado,
  // será cada una de las posiciones. Es decir, si queremos acceder a los estados del bit N, tendremos que acceder
  // mediante StatesArray[M][N], donde M será cada uno de los estados.
  typedef std::array<BitsSet, STATES_SIZE> StatesArray;
}

#endif // TURBOCODES_COMMON_H
