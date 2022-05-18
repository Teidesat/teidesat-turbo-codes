/**
 * Prueba de funcionamiento.
 */


#include "lib/TurboBit.h"
#include "lib/Rsc.h"

int main() {
  std::bitset<ttc::MESSAGE_SIZE> message("01010111001110101010001100111110");
  std::bitset<ttc::MESSAGE_SIZE> codedBits("01101110010001101101010010011010");
  ttc::Rsc a;
  std::array<ttc::TurboBit, ttc::MESSAGE_SIZE> result = a.code(message);
  for (const ttc::TurboBit& bit: result) {
    std::cout << bit.getBit();
  }
}
