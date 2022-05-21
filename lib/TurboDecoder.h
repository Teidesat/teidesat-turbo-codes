/**
* @author Hugo Fernández Solís
* @date 17/03/2022
* @file TurboDecoder.h
* @brief Define un turbo decodificador. Representa un sistema de corrección de errores que recibe un mensaje y lo
* decodifica.
*/

#ifndef TURBOCODES_TURBODECODER_H
#define TURBOCODES_TURBODECODER_H


#include "Rsc.h"


namespace ttc {

  // Implementa un decodificador.
  // Este recibe un CodedMessage y se encargará de decodificarlo y corregir los errores.
  class TurboDecoder {
    private:
      Rsc rsc_;     // Codificador sistemático recursivo.

    public:
      TurboDecoder();     // Constructor por defecto.

      static BitsSet deinterleave(const BitsSet& message);     // Reordena el mensaje.
  };

}

#endif //TURBOCODES_TURBODECODER_H
