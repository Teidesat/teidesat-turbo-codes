/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file common.h
 * @brief Implementa una clase para representar un bit con sus estados asociados.
 */

#include "../lib/TurboBit.h"

namespace ttc {

  /**
   * Constructor por defecto. Inicializa todos los bits a 0.
   */
  TurboBit::TurboBit() = default;

  /**
   * Bit getter. Devuelve el valor del bit.
   *
   * @return El valor del bit.
   */
  bool TurboBit::getBit() const {
    return get_bit(bitset(), STATES_SIZE);
  }

  /**
   * Bit setter. Establece un nuevo valor para el bit.
   *
   * @param bit Nuevo valor del bit.
   */
  void TurboBit::setBit(const bool& bit) {
    set_bit(bitset(), STATES_SIZE, bit);
  }

  /**
   * States getter. Devuelve el set de estados.
   *
   * @return El set de estados.
   */
  char TurboBit::getStates() const {
    char result = 0;
    for (uint8_t i = 0; i < STATES_SIZE; i++) {
      result |= get_bit(bitset(), i) << i;
    }
    return result;
  }

  /**
   * States setter. Establece un nuevo set de estados.
   *
   * @param states Nuevo set de estados.
   */
  void TurboBit::setStates(const char& states) {
    for (uint16_t i = 0; i < STATES_SIZE; i++) {
      set_bit(bitset(), i, get_bit(states, i));
    }
  }

  /**
   * States setter. Establece un nuevo set de estados.
   *
   * @param states Nuevo set de estados.
   */
  void TurboBit::setStates(const std::bitset<STATES_SIZE>& states) {
    for (uint16_t i = 0; i < STATES_SIZE; i++) {
      set_bit(bitset(), i, states[i]);
    }
  }

  /**
   * States setter. Establece un nuevo set de estados.
   *
   * @param states Nuevo set de estados.
   */
  void TurboBit::setStates(const std::string& states) {
    setStates(std::bitset<STATES_SIZE>(states));
  }

  /**
   * Bitset accessor.
   *
   * @return Una referencia al bitset.
   */
  char& TurboBit::bitset() {
    return bitset_;
  }

  /**
   * Bitset const accessor.
   *
   * @return Una referencia constante al bitset.
   */
  const char& TurboBit::bitset() const {
    return bitset_;
  }

  /**
   * Comparison operator overloading.
   *
   * @param set Set a comparar.
   *
   * @return El resultado de la comparación.
   */
  bool TurboBit::operator==(const std::bitset<4>& set) {
    for (uint8_t i = 0; i < 4; i++) {
      if (set[i] != get_bit(bitset(), i)) {
        return false;
      }
    }
    return true;
  }

  /**
   * Comparison operator overloading.
   *
   * @param set Set a comparar.
   *
   * @return El resultado de la comparación.
   */
  bool TurboBit::operator!=(const std::bitset<4>& set) {
    return !(*this == set);
  }

  /**
   * Ostream overloading.
   *
   * @param os OStream
   * @param data TurboBit a imprimir.
   *
   * @return Ostream
   */
  std::ostream& operator<<(std::ostream& os, const TurboBit& data) {
    os << std::bitset<4>(data.bitset());
    return os;
  }
}
