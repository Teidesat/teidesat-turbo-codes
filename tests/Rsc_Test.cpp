/**
 * @author Hugo Fernández Solís
 * @date 24/04/2022
 * @file CodedBits_Test.cpp
 * @brief Prueba los métodos de la clase Rsc.
 */

#include <ostream>

#include <gtest/gtest.h>

#include "../lib/Rsc.h"

/**
 * Test para probar el funcionamiento de la clase TurboBitset.
 */
TEST(Rsc, Functionallity) {
  char* message(  "01010111001110101010001100111110");
  std::bitset<ttc::MESSAGE_SIZE> codedBits("01101110010001101101010010011010");
  std::array<ttc::TurboBitset, ttc::MESSAGE_SIZE> result = ttc::Rsc().code(message);
  for (uint i = 0; i < ttc::MESSAGE_SIZE; i++) {
    EXPECT_EQ(result[i].getBit(), codedBits[i]) << "El bit " << i << " no se ha codificado correctamente!!!";
  }
}