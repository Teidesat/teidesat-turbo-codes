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


namespace ttc {

  /**
   * Estructura para almacenar mensaje codificados y sus estados.
   */
  struct CodedMessage {
    char message;       // Mensaje original.
    //std::array<ttc::TurboBitset, ttc::MESSAGE_SIZE> result;        // Mensaje codificado 1.
   // std::array<ttc::TurboBitset, ttc::MESSAGE_SIZE> result code2;        // Mensaje codificado 2.
  };

  /**
   * Turbo codificador. Representa un sistema de corrección de errores que recibe un mensaje y lo codifica para evitar
   * que se pierda información.
   */
  class TurboCoder {
    private:
      Rsc rsc_ {};      // Codificador convolucional sistemático recursivo.

    public:
      //TurboCoder();                                                   // Constructor por defecto.

      //CodedMessage<N,S> code(const std::bitset<N>& message);          // Codifica el mensaje enviado.

    private:
      //std::bitset<N> interleave(const std::bitset<N>& message);       // Reordena el mensaje.
  };

}


#endif //TURBOCODES_TURBOCODER_H
