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
  CodedMessage TurboDecoder::run(const CodedMessage& codedMessage) {
    BitsSet message = codedMessage.message;
    TurboBitset code1 = correct(codedMessage.code1);
    TurboBitset code2 = correct(codedMessage.code2);
    CodedMessage result;
    result.message = message;
    result.code1.bits() = rsc_.decode(code1);
    result.code2.bits() = deinterleave(rsc_.decode(code2));
    return result;
  }

  // Runs the soft decoder.
  CodedMessage TurboDecoder::run_soft(const CodedMessage& codedMessage) {
    BitsSet message = codedMessage.message;
    TurboBitset code1 = codedMessage.code1;
    TurboBitset code2 = codedMessage.code2;
    for (uint16_t i = 0; i < MESSAGE_SIZE; i++) {
      evaluate_bit(i, code1);
      evaluate_bit(i, code2);
    }
    CodedMessage result;
    result.message = message;
    result.code1.bits() = rsc_.decode(code1);
    result.code2.bits() = deinterleave(rsc_.decode(code2));
    return result;
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
      return 0;
    }
    else {
      totalCount++;
      uint calculatedError = correct_message(value, message, pos);
      TurboBitset messageCero = message;
      TurboBitset messageOne = message;
      const uint errorCero = viterbi(0, messageCero, calculatedError, pos + 1);
      const uint errorOne = viterbi(1, messageOne, calculatedError, pos + 1);
      if (errorCero < errorOne) {
        message = messageCero;
        return error + errorCero;
      } else {
        message = messageOne;
        return error + errorOne;
      }
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

  // Evalúa el bit para el soft decoder.
  void TurboDecoder::evaluate_bit(const uint16_t& pos, TurboBitset& message) {
    StatesSet prevStates(0);
    if (pos != 0) {
      prevStates = message.get_states(pos - 1);
    }
    StatesSet cero = calculate_states(0, prevStates);
    StatesSet one = calculate_states(1, prevStates);
    uint8_t errorCero = 0;
    uint8_t errorOne = 0;
    if (message.get_bit(pos) != 0) {
      errorCero++;
    }
    for (uint8_t i = 0; i < STATES_SIZE; i++) {
      if (message.get_states(pos)[i] != cero[i]) {
        errorCero++;
      }
    }
    if (message.get_bit(pos) != 1) {
      errorOne++;
    }
    for (uint8_t i = 0; i < STATES_SIZE; i++) {
      if (message.get_states(pos)[i] != one[i]) {
        errorOne++;
      }
    }
    if (errorCero < errorOne) {
      message.set_bit(pos, 0);
      message.set_states(pos, cero);
    }
    else {
      message.set_bit(pos, 1);
      message.set_states(pos, one);
    };
  }

  // Recibe un mensaje y lo reordena.
  BitsSet TurboDecoder::deinterleave(const BitsSet& message) {
    BitsSet result(0);
    for (uint16_t i = 0; i < MESSAGE_SIZE; i++) {
      result[i] = message[((3 * i) + 1) % MESSAGE_SIZE];
    }
    return result;
  }

}
