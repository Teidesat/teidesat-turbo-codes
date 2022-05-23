/**
 * @author Hugo Fernández Solís
 * @date 24/04/2022
 * @file TurboDecoder_Test.cpp
 * @brief Prueba los métodos de la clase TurboCoder.
 */

#include <gtest/gtest.h>
#include <random>

#include "../lib/TurboCoder.h"
#include "../lib/TurboDecoder.h"

///////////////////////////////////////////////////////////////////////////////
//     TESTS PARA COMPROBAR EL FUNCIONAMIENTO DE LA CLASE TURBODECODER       //
///////////////////////////////////////////////////////////////////////////////


// Comprobamos que la clase se inicializa correctamente.
// Los resultados han sido calculados a mano.
TEST(TurboDecoder, Inicialization) {
  ttc::TurboDecoder decoder;
  // Creamos un mensaje de prueba.
  const ttc::BitsSet testBits("01010111001110101010001100111110");

  // Codificamos el mensaje.
  ttc::CodedMessage codedBits = ttc::TurboCoder().code(testBits);
  EXPECT_EQ(codedBits.message, decoder.runSoft(codedBits).message)
  << "No se ha corregido el mensaje correctamente!!!";

  std::cout << "Total count: " << decoder.total_count << std::endl;
}