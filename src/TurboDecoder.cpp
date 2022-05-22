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

  // Decodifica el mensaje pasado.
  // Primero separa el mensaje original de los códigos. Luego aplicará el algoritmo viterbi sobre los códigos para luego
  // reordenar el último código. Por último comprobará que los tres tengan el mismo resultado.
  BitsSet TurboDecoder::run(const CodedMessage& codedMessage) {
    BitsSet message = codedMessage.message;
    TurboBitset code1 = correct(codedMessage.code1);
    TurboBitset code2 = correct(codedMessage.code2);
    return message;
  }

  // Decodifica el TurboBitset pasado.
  // Ejecutará el algoritmo viterbi para predecir los posibles errores del mensaje.
  TurboBitset TurboDecoder::correct(const TurboBitset& message) {
    TurboBitset messageCero = message;
    TurboBitset messageOne = message;
    const uint errorCero = viterbi(0, messageCero, 0, 0);
    const uint errorOne = viterbi(1, messageOne, 0, 0);
    if (errorCero < errorOne) {
      return messageCero;
    }
    else {
      return messageOne;
    }
  }

  // Corrige los errores del mensaje.
  uint TurboDecoder::viterbi(const bool& value, TurboBitset& message, const uint& error, const uint16_t& pos) {
    if (pos >= MESSAGE_SIZE) {
      return error;
    }
    uint calculatedError = correct_message(value, message, pos);
    TurboBitset messageCero = message;
    TurboBitset messageOne = message;
    const uint errorCero = viterbi(0, messageCero, calculatedError, pos + 1);
    const uint errorOne = viterbi(1, messageOne, calculatedError, pos + 1);
    if (errorCero < errorOne) {
      message = messageCero;
      return error + errorCero;
    }
    else {
      message = messageOne;
      return error + errorOne;
    }
  }

  // Corrige el mensaje en la posición pasada.
  uint TurboDecoder::correct_message(const bool& value, TurboBitset& message, const uint16_t& pos) {
    uint error = 0;
    StatesSet mustStates = calculate_states(value, pos == 0 ? 0 : message.get_states(pos-1));
    if (message.get_bit(pos) != value) {
      error++;
      message.set_bit(pos, value);
    }
    for (uint8_t i = 0; i < STATES_SIZE; i++) {
      if (message.get_states(pos)[i] != mustStates[i]) {
        error++;
        message.get_states(pos)[i] = mustStates[i];
      }
    }
    return error;
  }

  // Calcula los estados que debería haber en el set si el estado anterior y el bit de entrada fuesen los pasados como
  // parámetros.
  StatesSet TurboDecoder::calculate_states(const bool& value, const StatesSet& prevStates) {
    StatesSet mustStates(prevStates);
    bool aux = value;
    for (uint8_t i = 0; i < (STATES_SIZE - 1); i++) {
      aux ^= mustStates[i];
      mustStates[i] = mustStates[i + 1];
    }
    mustStates[STATES_SIZE - 1] = aux ^ mustStates[STATES_SIZE - 1];
    return mustStates;
  }

  // Recibe un mensaje y lo reordena.
  BitsSet TurboDecoder::deinterleave(const BitsSet& message) {
    BitsSet result(0);
    for(uint16_t i = 0; i < MESSAGE_SIZE; i++) {
      result[i] = message[((3 * i) + 1) % MESSAGE_SIZE];
    }
    return result;
  }

}
