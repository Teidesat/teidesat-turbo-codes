/**
* @author Hugo Fernández Solís
* @date 17/03/2022
* @file TurboCoder.cpp
* @brief Implementa un turbo codificador. Representa un sistema de corrección de errores que recibe un mensaje y lo
 * codifica para evitar que se pierda información.
*/

#include "../lib/TurboCoder.h"

namespace ttc {

  // Constructor por defecto.
  TurboCoder::TurboCoder() = default;

  // Codifica el mensaje pasado como parámetro.
  // Devolverá el mensaje original y el mensaje codificado dos veces, una de ellas habiendo pasado el mensaje antes por
  // el interleaver.
  CodedMessage TurboCoder::code(const BitsSet& message) {
    CodedMessage result;
    result.message = message;
    result.code1 = rsc_.code(message);
    result.code2 = rsc_.code(interleave(message));
    return result;
  }

  BitsSet TurboCoder::interleave(const BitsSet& message) {
    return {};
  }
}