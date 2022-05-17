#include "lib/TurboBit.h"

int main() {
  ttc::TurboBit bits = {};
  char aux = 0;

  std::cout << "Inicio del set: " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  bits.setBit(true);
  std::cout << "Bit marcado a " << std::bitset<1>(bits.getBit()) << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  ttc::set_bit(aux, 1, true);
  bits.setStates(aux);
  std::cout << "States marcados a " << std::bitset<2>(aux) << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  bits.setBit(false);
  std::cout << "Bit marcado a " << std::bitset<1>(bits.getBit()) << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  ttc::set_bit(aux, 0, true);
  bits.setStates(aux);
  std::cout << "States marcados a " << std::bitset<2>(aux) << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  ttc::set_bit(aux, 1, false);
  bits.setStates(std::bitset<ttc::STATES_SIZE>("00"));
  std::cout << "States marcados a " << std::bitset<ttc::STATES_SIZE>("00") << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  bits.setBit(true);
  std::cout << "Bit marcado a " << std::bitset<1>(bits.getBit()) << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  ttc::set_bit(aux, 1, false);
  bits.setStates(std::bitset<ttc::STATES_SIZE>("11"));
  std::cout << "States marcados a " << std::bitset<ttc::STATES_SIZE>("11") << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;

  ttc::set_bit(aux, 1, false);
  bits.setStates(std::bitset<ttc::STATES_SIZE>("01"));
  std::cout << "States marcados a " << std::bitset<ttc::STATES_SIZE>("01") << ": " << bits << std::endl;
  std::cout << "Bit: " << std::bitset<1>(bits.getBit()) << std::endl;
  std::cout << "States: " << std::bitset<2>(bits.getStates()) << std::endl << std::endl;
}
