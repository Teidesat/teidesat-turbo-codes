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
TEST(TurboDeoder, Inicialization) {
  ttc::TurboDecoder decoder;
  ttc::BitsSet orig;

  // Primero modificaremos una seria de bits y estados seleccionados aleatoriamente.
  // Para ello necesitamos un generador de números aleatorios.
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0, ttc::MESSAGE_SIZE - 1);
  std::vector<uint16_t> positions;
  // Vamos a modificar la mitad de los bits.
  while (positions.size() < ttc::MESSAGE_SIZE / 2) {
    const uint16_t pos = dist(rng);
    if (std::find(positions.begin(), positions.end(), pos) == positions.end()) {
      positions.push_back(pos);
    }
  }
  // Modificamos los valores de los bits y los estados seleccionados aleatoriamente.
  for (const uint16_t& pos: positions) {
    orig[pos] = true;
  }

  // Probamos con el deinterleaver.
  ttc::BitsSet modif = ttc::TurboDecoder::deinterleave(ttc::TurboCoder::interleave(orig));
  for (uint16_t i = 0; i < ttc::MESSAGE_SIZE; i++) {
    EXPECT_EQ(orig[i], modif[i])
    << "El bit en la posición " << i << " no se ha reordenado correctamente!!!";
  }

}