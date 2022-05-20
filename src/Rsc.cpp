/**
* @author Hugo Fernández Solís
* @date 17/03/2022
* @file RSC.cpp
* @brief Implementa un codificador convolucional sistemático recursivo. Este codificador consta de una entrada y una
* salida. La entrada se conecta a un canal de estados que, mediante una serie de operaciones XOR, codificarán bit a
* bit el código de entrada y lo enviará por la salida. Es una de las piezas claves del corrector de errores, pues es
* la que realiza toda la reorganización de los bits.
*/

#include "../lib/Rsc.h"

namespace ttc {

  /**
   * Constructor por defecto.
   */
  Rsc::Rsc() = default;

  /**
   * States accessor.
   *
   * @return El estado actual del RSC.
   */
  char& Rsc::states() {
    return states_;
  }

  /**
   * Const states accessor.
   *
   * @return El estado actual del RSC.
   */
  const char& Rsc::states() const {
    return states_;
  }

  /**
   * Codifica el mensaje pasado como parámetro.
   *
   * @param message - Mensaje a codificar.
   *
   * @return El mensaje codificado.
   */
  std::array<TurboBitset, MESSAGE_SIZE> Rsc::code(const char* message) {
    std::array<TurboBitset, MESSAGE_SIZE> result;
    for (size_t i = 0; i < MESSAGE_SIZE / sizeof(char); i++) {
      for (uint16_t j = 0; j < sizeof(char); j++) {
        const bool aux = (get_bit(message[i], j) ^ get_xor_states());
        result[i].setBit(aux ^ get_bit(states(), 0));
        result[i].setStates(states());
        update_state(aux);
      }
    }
    reset();
    return result;
  }

  /**
   * Resetea a 0 los estados.
   */
  void Rsc::reset() {
    states() = 0;
  }

  /**
   * Realiza la operación xor sobre los estados.
   *
   * @return Un bit con el resultado de la operación.
   */
  bool Rsc::get_xor_states() const {
    bool result = get_bit(states(), 0);
    for (uint8_t i = 1; i < STATES_SIZE; i++) {
      result ^= get_bit(states(), i);
    }
    return result;
  }

  /**
   * Actualiza los valores de cada estado.
   *
   * @param aux Valor del bit de entrada.
   */
  void Rsc::update_state(const bool& aux) {
    for (uint8_t i = 0; i < (STATES_SIZE - 1); i++) {
      set_bit(states(), i, get_bit(states(), i + 1));
    }
    set_bit(states(), STATES_SIZE - 1, aux);
  }

}
