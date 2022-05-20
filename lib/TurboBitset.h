/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file common.h
 * @brief Define una clase para representar un bit con sus estados asociados.
 */

#ifndef TURBOCODES_TURBOBITSET_H
#define TURBOCODES_TURBOBITSET_H

#include <array>
#include <bitset>
#include <iostream>
#include <string>

#include "common.h"

namespace ttc {

  // Almacena un bit y sus estados asociados.
  // Por defecto todos los bits se inicializan 0 al igual que sus estados asociados.
  // Cada bit tendrá tantos estados asociados como STATES_SIZE dicte. La definición de esta variable podrá encontrarse
  // en "lib/common.h".
  class TurboBitset {
    private:
      BitsSet bits_;            // Conjunto de bits.
      StatesArray states_;      // Estados asociados a los bits.

    public:
      TurboBitset();     // Constructor por defecto.

      BitsSet& bits();                 // Bits attribute accessor.
      const BitsSet& bits() const;     // Bits const attribute accessor.

      StatesArray& states();                 // States attribute accessor.
      const StatesArray& states() const;     // States const attribute accessor.
  };
}

#endif // TURBOCODES_TURBOBITSET_H
