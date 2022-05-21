/**
* @author Hugo Fernández Solís
* @date 17/03/2022
* @file TurboDecoder.cpp
* @brief Implementa un turbo decodificador. Representa un sistema de corrección de errores que recibe un mensaje y lo
* decodifica.
*/

#include "../lib/TurboDecoder.h"

namespace ttc {

  // Constructor por defecto.
  ttc::TurboDecoder::TurboDecoder() = default;

  // Recibe un mensaje y lo reordena.
  BitsSet TurboDecoder::deinterleave(const BitsSet& message) {
    BitsSet result(0);
    for(uint16_t i = 0; i < MESSAGE_SIZE; i++) {
      result[i] = message[((3 * i) + 1) % MESSAGE_SIZE];
    }
    return result;
  }
}
