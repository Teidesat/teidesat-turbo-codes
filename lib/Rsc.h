/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file RSC.h
 * @brief Define un codificador convolucional sistemático recursivo. Este codificador consta de una entrada y una
 * salida. La entrada se conecta a un canal de estados que, mediante una serie de operaciones XOR, codificarán bit a
 * bit el código de entrada y lo enviará por la salida. Es una de las piezas claves del corrector de errores, pues es
 * la que realiza toda la reorganización de los bits.
 */


#ifndef TURBOCODES_RSC_H
#define TURBOCODES_RSC_H

#include <array>
#include <bitset>

#include "common.h"
#include "TurboBit.h"


namespace ttc {

  /**
   * Codificador convolucional sistemático recursivo. Es un conjunto de dos estados que, mediante un mensaje de entrada y
   * una serie de operaciones XOR, envía un mensaje de salida que más tarde podrá ser reordenado mediante un
   * decodificador convolucional sistemático recursivo que también tenga dos estados.
   *
   * @atribute states_
   *      - Conjunto de dos estados que usa el sistema para la codificación del mensaje.
   */
  class Rsc {
    private:
      char states_ = 0;     // Conjunto de estados del codificador.

    public:
      Rsc();      // Constructor por defecto.

      char& states();                 // Bits getter & setter
      const char& states() const;     // Bits const getter & setter

      std::array<TurboBit, MESSAGE_SIZE> code(const std::bitset<MESSAGE_SIZE>& message);      // Codifica el mensaje.

    private:
      inline void reset();                    // Resetea los estados a 0.
      inline bool get_xor_states() const;     // Realiza la operación XOR sobre los estados.
      void update_state(const bool &aux);     // Actualiza los valores de cada estado.
  };

} // ttc


#endif //TURBOCODES_RSC_H
