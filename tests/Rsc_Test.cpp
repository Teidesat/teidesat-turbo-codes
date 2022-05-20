/**
 * @author Hugo Fernández Solís
 * @date 24/04/2022
 * @file CodedBits_Test.cpp
 * @brief Prueba los métodos de la clase Rsc.
 */

#include <gtest/gtest.h>

#include "../lib/Rsc.h"

// Comprobamos que la clase se inicializa correctamente.
// Los resultados han sido calculados a mano.
TEST(Rsc, Inicialization) {
  // Creamos un mensaje de prueba.
  ttc::BitsSet testBits("01010111001110101010001100111110");
  // Creamos el resultado que deberíamos obtener.
  ttc::BitsSet resultBits("01101110010001101101010010011010");
  // Creamos los estados que deberíamos obtener.
  std::array<ttc::StatesSet , ttc::MESSAGE_SIZE> resultStates = {
      ttc::StatesSet("00"), ttc::StatesSet("10"), ttc::StatesSet("01"), ttc::StatesSet("00"),
      ttc::StatesSet("10"), ttc::StatesSet("01"), ttc::StatesSet("10"), ttc::StatesSet("11"),
      ttc::StatesSet("11"), ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("10"),
      ttc::StatesSet("11"), ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("00"),
      ttc::StatesSet("00"), ttc::StatesSet("10"), ttc::StatesSet("11"), ttc::StatesSet("11"),
      ttc::StatesSet("11"), ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("10"),
      ttc::StatesSet("01"), ttc::StatesSet("00"), ttc::StatesSet("10"), ttc::StatesSet("11"),
      ttc::StatesSet("11"), ttc::StatesSet("01"), ttc::StatesSet("00"), ttc::StatesSet("00")
  };

  /**
   * Aunque solo estemos poniendo 32 bits y estados, ya que es lo que hemos calculado a mano, el test funciona con los
   * MESSAGE_SIZE bits y estados.
   * Gracias a que el resto del mensaje se establece a 0 por defecto, hace que los bits faltantes serán todos 0, y que
   * por lo tanto, el resto de estados también se quede a 0. Gracias a ello podemos dejar que se establezcan a 0 por
   * defecto y realizar las comprobaciones.
   */

  // Codificamos el mensaje.
  ttc::TurboBitset codedBits = ttc::Rsc().code(testBits);

  // Comprobamos los resultados.
  for (uint16_t i = 0; i < ttc::MESSAGE_SIZE; i++) {
    EXPECT_EQ(codedBits.get_bit(i), resultBits[i])
    << "El bit " << i << " no se ha codificado correctamente!!!";
    EXPECT_EQ(codedBits.get_states(i), resultStates[i])
    << "El estado " << i << " no se ha codificado correctamente!!!";
  }
}