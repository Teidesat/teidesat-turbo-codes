/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file RSC.h
 * @brief Define un turbo codificador. Representa un sistema de corrección de errores que recibe un mensaje y lo
 * codifica para evitar que se pierda información.
 */

#ifndef TURBOCODES_TURBOCODER_H
#define TURBOCODES_TURBOCODER_H

#include "common.h"
#include "Rsc.h"
#include "TurboBitset.h"


namespace ttc {

  // Estructura que almacena el mensaje original y los codificados.
  // El mensaje original constará de un set de MESSAGE_SIZE bits.
  // Los mensajes codificados serán un TurboBitset con los bits codificados y sus estados asociados.
  struct CodedMessage {
    BitsSet message;        // Mensaje original.
    TurboBitset code1;      // Mensaje codificado 1.
    TurboBitset code2;      // Mensaje codificado 2.
  };

  // Turbo codificador.
  // Representa un sistema de corrección de errores que recibe un mensaje y lo codifica para evitar que se pierda
  // información.
  class TurboCoder {
    private:
      Rsc rsc_;      // Codificador convolucional sistemático recursivo.

    public:
      TurboCoder();     // Constructor por defecto.

      CodedMessage code(const BitsSet& message);     // Codifica el mensaje enviado.

    private:
      BitsSet interleave(const BitsSet& message);     // Reordena el mensaje.
  };

}


#endif //TURBOCODES_TURBOCODER_H
