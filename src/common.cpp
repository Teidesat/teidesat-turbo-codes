/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file common.h
 * @brief Implementa definiciones generales y tipos de datos globales para el proyecto.
 */

#include "../lib/common.h"

namespace ttc {

  /**
   * Devuelve el valor del bit.
   *
   * @param bitset Conjunto de bits.
   * @param pos Posición del bit a obtener.
   *
   * @return El valor leído.
   */
  bool get_bit(const char& bitset, const uint8_t& pos) {
    return (bitset >> pos) & 1U;
  }

  /**
   * Devuelve el valor del bit.
   *
   * @param bitset Conjunto de bits.
   * @param pos Posición del bit a obtener.
   *
   * @return El valor leído.
   */
  bool get_bit(const char* bitset, const uint8_t& pos) {
    return (bitset[pos/4] >> pos%4) & 1U;
  }

  /**
   * Establece el valor del bit.
   *
   * @param bitset Conjunto de bits.
   * @param pos Posición del bit a modificar.
   * @param value Nuevo valor del bit.
   */
  void set_bit(char& bitset, const uint8_t& pos, const bool& value) {
    if (value == 1) {
      bitset |= 1U << pos;
    }
    else if (value == 0) {
      bitset &= ~(1U << pos);
    }
  }

  /**
   * Cambia el valor del bit al opuesto.
   *
   * @param bitset Conjunto de bits.
   * @param pos Posición del bit a cambiar.
   */
  void toggle_bit(char& bitset, const uint8_t& pos) {
    bitset ^= 1U << pos;
  }

}