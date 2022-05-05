#ifndef ENDIANS_H
#define ENDIANS_H

#include <cstdint>
#include <iostream>
#include <vector>

template <typename Integral> std::vector<uint8_t> get_le_bytes(Integral value) {
  std::vector<uint8_t> result{};
  result.reserve(sizeof(value));
  for (auto i = 0; i < sizeof(value); ++i) {
    result.push_back(static_cast<uint8_t>(value & 0xFF));
    value >>= 8;
  }
  return result;
}

template <typename Integral> std::vector<uint8_t> get_be_bytes(Integral value) {
  auto result = get_le_bytes(value);
  std::reverse(result.begin(), result.end());
  return result;
}

template <> std::vector<uint8_t> get_le_bytes<uint8_t>(uint8_t value) {
  return {value};
}

template <> std::vector<uint8_t> get_be_bytes<uint8_t>(uint8_t value) {
  return {value};
}

#endif
