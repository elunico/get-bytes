#ifndef ENDIANS_H
#define ENDIANS_H

#include <array>
#include <cstdint>
#include <iostream>

template <typename Integral, std::size_t count = sizeof(Integral)>
constexpr std::array<uint8_t, count> get_le_bytes(Integral value) {
  std::array<uint8_t, count> result{};
  for (auto i = 0; i < sizeof(value); ++i) {
    result[i] = static_cast<uint8_t>(value & 0xFF);
    value >>= 8;
  }
  return result;
}

template <typename Integral, std::size_t count = sizeof(Integral)>
constexpr std::array<uint8_t, count> get_be_bytes(Integral value) {
  auto result = get_le_bytes(value);
  std::reverse(result.begin(), result.end());
  return result;
}

template <>
constexpr std::array<uint8_t, 1> get_le_bytes<uint8_t, 1>(uint8_t value) {
  return {value};
}

template <>
constexpr std::array<uint8_t, 1> get_be_bytes<uint8_t, 1>(uint8_t value) {
  return {value};
}

#endif
