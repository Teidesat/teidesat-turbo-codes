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

  // Constructor por defecto.
  // Inicializa los estados a 0.
  Rsc::Rsc() = default;

  // States attribute accessor.
  // Devuelve una referencia al conjunto de estados.
  StatesSet& Rsc::states() {
    return states_;
  }

  // States const attribute accessor.
  // Devuelve una referencia constante al conjunto de estados.
  const StatesSet& Rsc::states() const {
    return states_;
  }

  // Codifica el mensaje pasado como parámetro.
  // Devolverá un TurboBitset con el mensaje codificado y los estados asociados a cada bit.
  TurboBitset Rsc::code(const BitsSet& message) {
    TurboBitset result;
    for (size_t i = 0; i < MESSAGE_SIZE; i++) {
      const bool aux = message[i] ^ get_xor_states();
      result.set_bit(i, (aux ^ states()[0]));
      update_state(aux);
      result.set_states(i, states());
    }
    reset();
    return result;
  }

  // Decodifica el mensaje pasado como parámetro.
  BitsSet Rsc::decode(const TurboBitset& message) {
    BitsSet result;
    for (size_t i = 0; i < MESSAGE_SIZE; i++) {
      const bool xorStates = get_xor_states();
      const bool auxCero = xorStates;
      const bool outCero = auxCero ^ states()[0];
      if (message.get_bit(i) == outCero && message.get_states(i) == get_states(auxCero))  {
        result[i] = 0;
        update_state(0);
      }
      else {
        result[i] = 1;
        update_state(1);
      }
    }
    reset();
    return result;
  }

  // Resetea a 0 el valor de los estados.
  void Rsc::reset() {
    states().reset();
  }

  // Realiza la operación XOR con los estados y devuelve el resultado.
  // Esta operación se utiliza en el proceso de codificación.
  bool Rsc::get_xor_states() const {
    bool result = states()[0];
    for (uint8_t i = 1; i < STATES_SIZE; i++) {
      result ^= states()[i];
    }
    return result;
  }

  // Actualiza el valor de los estados.
  // Rueda todos los valores una posición a la derecha e introduce el valor entrante al final.
  void Rsc::update_state(const bool& aux) {
    for (uint8_t i = 0; i < (STATES_SIZE - 1); i++) {
      states()[i] = states()[i + 1];
    }
    states()[STATES_SIZE - 1] = aux;
  }

  StatesSet Rsc::get_states(const bool& aux) {
    StatesSet result = states();
    for (uint8_t i = 0; i < (STATES_SIZE - 1); i++) {
      result[i] = result[i + 1];
    }
    result[STATES_SIZE - 1] = aux;
    return result;
  }

}
