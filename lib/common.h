/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file common.h
 * @brief Incluye definiciones generales y tipos de datos globales para el proyecto.
 */

#ifndef TURBOCODES_COMMON_H
#define TURBOCODES_COMMON_H

#include <cstdint>
#include <bitset>

namespace ttc {

  constexpr uint8_t STATES_SIZE = 2;                    // Número de estados asociados a un bit.
  constexpr uint16_t MESSAGE_SIZE = 32;                 // Tamaño del mensaje a codificar.
  constexpr uint16_t BITSET_SIZE = STATES_SIZE + 1;     // Tamaño del bitset.

  bool get_bit(const char& bitset, const uint8_t& pos);                   // Devuelve el valor del bit.
  void set_bit(char& bitset, const uint8_t& pos, const bool& value);      // Establece un nuevo valor al bit.
  void toggle_bit(char& bitset, const uint8_t& pos);                      // Cambia el valor del bit.
}

#endif // TURBOCODES_COMMON_H
