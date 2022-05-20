/**
 * @author Hugo Fernández Solís
 * @date 24/04/2022
 * @file TurboBitset_Test.cpp
 * @brief Prueba los métodos de la clase TurboBitset.
 */

#include <random>
#include <ostream>
#include <gtest/gtest.h>

#include "common.h"
#include "TurboBitset.h"

///////////////////////////////////////////////////////////////////////////////
//      TESTS PARA COMPROBAR EL FUNCIONAMIENTO DE LA CLASE TURBOBITSET       //
///////////////////////////////////////////////////////////////////////////////

// Comprobamos que la clase se inicializa correctamente.
TEST(TurboBitset, Inicialization) {
  // TurboBitset de prueba.
  ttc::TurboBitset bits;

  // Realizamos una segunda comprobación exhaustiva de los bits.
  for (uint16_t i = 0; i < ttc::MESSAGE_SIZE; i++) {
    EXPECT_EQ(bits.bits()[i], 0)
    << "El bit " << i << " se ha inicializado a " << bits.bits()[0] << "en vez de a 0!!!";
  }

  // Realizamos una segunda comprobación exhaustiva de los estados.
  for (uint8_t i = 0; i < ttc::STATES_SIZE; i++) {
    for (uint16_t j = 0; j < ttc::MESSAGE_SIZE; j++) {
      EXPECT_EQ(bits.states()[i][j], false)
      << "El estado " << i << " del bit " << j << " se ha inicializado a " << bits.states()[i][j] << "en vez de a 0!!!";
    }
  }
}

// Comprobamos que se puede acceder a los atributos de la clase.
TEST(TurboBitset, Access) {
  // TurboBitset de prueba.
  ttc::TurboBitset bits;

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
    bits.bits()[pos] = true;
    for (ttc::BitsSet& states: bits.states()) {
      states[pos] = true;
    }
  }

  // Comprobamos que los valores se han modificado correctamente.
  for (uint16_t i = 0; i < ttc::MESSAGE_SIZE; i++) {
    // Calculamos el valor que deberá tomar el bit según su posición esté entre las modificadas o no.
    const bool value = std::find(positions.begin(), positions.end(), i) != positions.end();
    // Comprobamos los valores de los bits y los estados.
    EXPECT_EQ(bits.bits()[i], value)
              << "El bit " << i << " no se ha modificado a correctamente!!!";
    for (ttc::BitsSet& states: bits.states()) {
      EXPECT_EQ(states[i], value)
                << "El estado " << i << " no se ha modificado correctamente!!!";
    }
  }
}

// Comprobamos que se pueden obtener y modificar los bits y los estados dada una posición.
TEST(TurboBitset, Modification) {
  // TurboBitset de prueba.
  ttc::TurboBitset bits;

  // Primero modificaremos una seria de bits y estados seleccionados aleatoriamente.
  // Para ello necesitamos un generador de números aleatorios.
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0,ttc::MESSAGE_SIZE-1);
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
    bits.set_bit(pos, true);
    bits.set_states(pos, ttc::StatesSet().flip());
  }

  // Comprobamos que los valores se han modificado correctamente.
  for (uint16_t i = 0; i < ttc::MESSAGE_SIZE; i++) {
    // Calculamos el valor que deberá tomar el bit según su posición esté entre las modificadas o no.
    const bool bitsValue = std::find(positions.begin(), positions.end(), i) != positions.end();
    ttc::StatesSet statesValue(0);
    if (bitsValue) {statesValue.flip();}
    // Comprobamos los valores de los bits y los estados.
    EXPECT_EQ(bits.get_bit(i), bitsValue)
    << "El bit " << i << " no se ha modificado a correctamente!!!";
    EXPECT_EQ(bits.get_states(i), statesValue)
    << "Los estados  " << i << " no se ha modificado a correctamente!!!";

  }
}