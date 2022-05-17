/**
 * @author Hugo Fernández Solís
 * @date 24/04/2022
 * @file CodedBits_Test.cpp
 * @brief Prueba los métodos de la clase TurboBits.
 */

#include <ostream>

#include <gtest/gtest.h>

#include "../lib/TurboBit.h"

/**
 * Test para probar el funcionamiento de la clase TurboBit.
 */
TEST(TurboBit, Functionallity) {

  /*** Creamos un TurboBit ***/
  ttc::TurboBit bits = {};
  char aux = 0;

  /*** Comprobamos que se han inicializado correctamente ***/
  EXPECT_EQ(bits.getBit(), 0) << "El bit no se inicializa a 0 por defecto!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se inicializan a 0 por defecto!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0000")) << "El set no se ha inicializado correctamente!!!";

  /*** Probamos a modificar los valores del bit ***/
  // Establecemos el bit a 1.
  bits.setBit(1);
  EXPECT_EQ(bits.getBit(), 1) << "El bit no se ha puesto a 1!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Se han modificado los estados cuando no debían!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0100")) << "El set no se ha modificado correctamente!!!";
  // Establecemos el bit a 0.
  bits.setBit(0);
  EXPECT_EQ(bits.getBit(), 0) << "El bit no se ha puesto a 0!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Se han modificado los estados cuando no debían!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0000")) << "El set no se ha modificado correctamente!!!";

  /*** Probamos a modificar los estados ***/
  // Establecemos los estados a 01.
  ttc::set_bit(aux, 0, 1);
  bits.setStates(aux);
  EXPECT_EQ(bits.getBit(), 0) << "Se ha modificado el bit cuando no debía!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se han puesto a 01!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0001")) << "El set no se ha modificado correctamente!!!";
  // Establecemos los estados a 11.
  ttc::set_bit(aux, 1, 1);
  bits.setStates(aux);
  EXPECT_EQ(bits.getBit(), 0) << "Se ha modificado el bit cuando no debía!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se han puesto a 10!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0011")) << "El set no se ha modificado correctamente!!!";
  // Establecemos los estados a 10.
  ttc::set_bit(aux, 0, 0);
  bits.setStates(aux);
  EXPECT_EQ(bits.getBit(), 0) << "Se ha modificado el bit cuando no debía!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se han puesto a 11!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0010")) << "El set no se ha modificado correctamente!!!";
  // Establecemos los estados a 00.
  ttc::set_bit(aux, 1, 0);
  bits.setStates(aux);
  EXPECT_EQ(bits.getBit(), 0) << "Se ha modificado el bit cuando no debía!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se han puesto a 00!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0000")) << "El set no se ha modificado correctamente!!!";
  // Establecemos los estados a 01.
  bits.setStates("01");
  ttc::set_bit(aux, 0, 1);
  EXPECT_EQ(bits.getBit(), 0) << "Se ha modificado el bit cuando no debía!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se han puesto a 00!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0001")) << "El set no se ha modificado correctamente!!!";
  // Establecemos los estados a 11.
  bits.setStates("11");
  ttc::set_bit(aux, 1, 1);
  EXPECT_EQ(bits.getBit(), 0) << "Se ha modificado el bit cuando no debía!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se han puesto a 00!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0011")) << "El set no se ha modificado correctamente!!!";
  // Establecemos los estados a 00.
  bits.setStates(std::bitset<ttc::STATES_SIZE>("00"));
  ttc::set_bit(aux, 0, 0);
  ttc::set_bit(aux, 1, 0);
  EXPECT_EQ(bits.getBit(), 0) << "Se ha modificado el bit cuando no debía!!!";
  EXPECT_EQ(bits.getStates(), aux) << "Los estados no se han puesto a 00!!!";
  EXPECT_TRUE(bits == std::bitset<4>("0000")) << "El set no se ha modificado correctamente!!!";
}