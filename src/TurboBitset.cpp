/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file common.h
 * @brief Implementa una clase para representar un bit con sus estados asociados.
 */

#include "../lib/TurboBitset.h"

namespace ttc {

  // Constructor por defecto.
  // Inicializa todos los bits y los estados a 0.
  TurboBitset::TurboBitset() = default;

  // Bits attribute accessor.
  // Devuelve una referencia al conjunto de bits.
  BitsSet& TurboBitset::bits() {
    return bits_;
  }

  // Bits const attribute accessor.
  // Devuelve una referencia constante al conjunto de bits.
  const BitsSet& TurboBitset::bits() const {
    return bits_;
  }

  // States attribute accessor.
  // Devuelve una referencia al array de estados.
  StatesArray& TurboBitset::states() {
    return states_;
  }

  // States const attribute accessor.
  // Devuelve una referencia constante al array de bits.
  const StatesArray& TurboBitset::states() const {
    return states_;
  }

  // Devuelve el valor del bit en una posición determinada.
  bool TurboBitset::get_bit(const uint16_t& pos) const {
    return bits()[pos];
  }

  // Modifica el valor del bit en una posición determinada.
  void TurboBitset::set_bit(const uint16_t& pos, const bool& val) {
    bits()[pos] = val;
  }

  // Devuelve el valor del estado en una posición determinada.
  StatesSet TurboBitset::get_states(const uint16_t& pos) const {
    StatesSet result;
    for (uint8_t i = 0; i < STATES_SIZE; i++) {
      result[i] = states()[i][pos];
    }
    return result;
  }

  // Modifica el valor del estado en una posición determinada.
  void TurboBitset::set_states(const uint16_t& pos, const StatesSet& val) {
    for (uint8_t i = 0; i < STATES_SIZE; i++) {
      states()[i][pos] = val[i];
    }
  }
}
