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
#include "TurboCoder.h"


namespace ttc {

  // Estructura que almacena un TurboBitset y se va corrigiendo poco a poco, almacenando el número de errores.
  struct DecoBitset {
    TurboBitset bits = {};
    uint errors = 0;

    explicit DecoBitset(const TurboBitset& message): bits(message), errors(0){}
  };

  // Implementa un decodificador.
  // Este recibe un CodedMessage y se encargará de decodificarlo y corregir los errores.
  class TurboDecoder {
    private:
      Rsc rsc_;     // Codificador sistemático recursivo.

    public:
      TurboDecoder();     // Constructor por defecto.

      BitsSet run(const CodedMessage& codedMessage);      // Decodifica el mensaje pasado.

      static BitsSet deinterleave(const BitsSet& message);     // Reordena el mensaje.

    private:
      TurboBitset correct(const TurboBitset& message);
      uint viterbi(const bool& value, TurboBitset& message, const uint& error, const uint16_t& pos);
      uint correct_message(const bool& value, TurboBitset& message, const uint16_t& pos);
      StatesSet calculate_states(const bool& value, const StatesSet& prevStates);
  };

}

#endif //TURBOCODES_TURBODECODER_H
