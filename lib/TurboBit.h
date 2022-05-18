/**
 * @author Hugo Fernández Solís
 * @date 17/03/2022
 * @file common.h
 * @brief Define una clase para representar un bit con sus estados asociados
 */

#ifndef TURBOCODES_TURBOBIT_H
#define TURBOCODES_TURBOBIT_H

#include <bitset>
#include <iostream>
#include <string>

#include "common.h"

namespace ttc {

  /**
   * Almacena un bit y sus estados asociados.
   *
   * @atribute bitset_
   *    - Set de bits con el bit y sus estados.
   */
  class TurboBit {
    private:
      char bitset_ = 0;     // Conjunto de bits

    public:
      TurboBit();     // Constructor por defecto

      bool getBit() const;              // Bit getter
      void setBit(const bool& bit);     // Bit setter

      char getStates() const;                                     // States getter
      void setStates(const char& states);                         // States setter
      void setStates(const std::bitset<STATES_SIZE>& states);     // States setter
      void setStates(const std::string& states);                  // States setter

      char& bitset();                 // Bitset accessor
      const char& bitset() const;     // Bitset const accessor

      bool operator==(const std::bitset<4>& set);     // Comparison operator overloading.
      bool operator!=(const std::bitset<4>& set);     // Comparison operator overloading.

      friend std::ostream& operator<<(std::ostream& os, const TurboBit& data);    // Ostream overloading.
  };
}

#endif // TURBOCODES_TURBOBIT_H
