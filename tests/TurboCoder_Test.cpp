/**
 * @author Hugo Fernández Solís
 * @date 24/04/2022
 * @file TurboCoder_Test.cpp
 * @brief Prueba los métodos de la clase TurboCoder.
 */

#include <gtest/gtest.h>

#include "../lib/TurboCoder.h"

///////////////////////////////////////////////////////////////////////////////
//      TESTS PARA COMPROBAR EL FUNCIONAMIENTO DE LA CLASE TURBOCODER        //
///////////////////////////////////////////////////////////////////////////////


// Comprobamos que la clase se inicializa correctamente.
// Los resultados han sido calculados a mano.
TEST(TurboCoder, Inicialization) {
  // Creamos un mensaje de prueba.
  const ttc::BitsSet testBits("01010111001110101010001100111110");
  // Creamos el resultado que deberíamos obtener.
  const ttc::BitsSet resultBits("01101110010001101101010010011010");
  // Creamos los estados que deberíamos obtener.
  const std::array<ttc::StatesSet , ttc::MESSAGE_SIZE> resultStates = {
      ttc::StatesSet("00"), ttc::StatesSet("10"), ttc::StatesSet("01"), ttc::StatesSet("00"),
      ttc::StatesSet("10"), ttc::StatesSet("01"), ttc::StatesSet("10"), ttc::StatesSet("11"),
      ttc::StatesSet("11"), ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("10"),
      ttc::StatesSet("11"), ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("00"),
      ttc::StatesSet("00"), ttc::StatesSet("10"), ttc::StatesSet("11"), ttc::StatesSet("11"),
      ttc::StatesSet("11"), ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("10"),
      ttc::StatesSet("01"), ttc::StatesSet("00"), ttc::StatesSet("10"), ttc::StatesSet("11"),
      ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("00"), ttc::StatesSet("00")
  };

  // Codificamos el mensaje.
  const ttc::CodedMessage codedBits = ttc::TurboCoder().code(testBits);

  // Comprobamos los resultados.
  for (uint16_t i = 0; i < ttc::MESSAGE_SIZE; i++) {
    EXPECT_EQ(codedBits.message[i], testBits[i])
    << "El bit " << i << " del mensaje ha sido modificado!!!";
    EXPECT_EQ(codedBits.code1.get_bit(i), resultBits[i])
    << "El bit " << i << " del code1, no se ha codificado correctamente!!!";
    EXPECT_EQ(codedBits.code1.get_states(i), resultStates[i])
    << "El estado " << i << "del code1,  no se ha codificado correctamente!!!";
  }

  // Vamos a comprobar que el interleaver funciona correctamente.
  const ttc::BitsSet prueba = ttc::BitsSet(0).flip();
  const ttc::BitsSet result = ttc::TurboCoder::interleave(prueba);
  for (uint16_t i = 0; i < ttc::MESSAGE_SIZE; i++) {
    EXPECT_EQ(prueba[i], 1)
    << "La posición " << i << " no se adjunta en el interleaver!!!";
  }
}