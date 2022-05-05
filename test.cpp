#include "endians.h"
#include <criterion/criterion.h>
#include <cstdint>
#include <vector>

TestSuite(Endianness);

TestSuite(EndiannessSpecialized);

Test(EndiannessSpecialized, uint8_t_le) {
  uint8_t value = 0xFF;
  auto expected = get_le_bytes(value);
  auto actual = get_le_bytes<uint8_t>(value);
  cr_assert_arr_eq(actual.data(), expected.data(), expected.size());
}

Test(EndiannessSpecialized, uint8_t_be) {
  uint8_t value = 0xFF;
  auto expected = get_be_bytes(value);
  auto actual = get_be_bytes<uint8_t>(value);
  cr_assert_arr_eq(actual.data(), expected.data(), expected.size());
}

Test(Endianness, uint8_t_le) {
  uint8_t value = 0xFF;
  std::vector<u_int8_t> expected = {value};
  auto actual = get_le_bytes(value);
  cr_assert_arr_eq(actual.data(), expected.data(), expected.size());
}

Test(Endianness, uint8_t_be) {
  uint8_t value = 0xFF;
  std::vector<u_int8_t> expected = {value};
  auto actual = get_be_bytes(value);
  cr_assert_arr_eq(actual.data(), expected.data(), expected.size());
}

Test(Endianness, LittleEndianLongLong) {
  auto value = 0x0102030405060708ULL;
  auto bytes = get_le_bytes(value);
  cr_assert_eq(bytes.size(), 8);
  cr_assert_eq(bytes[0], 0x08);
  cr_assert_eq(bytes[1], 0x07);
  cr_assert_eq(bytes[2], 0x06);
  cr_assert_eq(bytes[3], 0x05);
  cr_assert_eq(bytes[4], 0x04);
  cr_assert_eq(bytes[5], 0x03);
  cr_assert_eq(bytes[6], 0x02);
  cr_assert_eq(bytes[7], 0x01);
}

Test(Endianness, BigEndianLongLong) {
  auto value = 0x0102030405060708ULL;
  auto bytes = get_be_bytes(value);
  cr_assert_eq(bytes.size(), 8);
  cr_assert_eq(bytes[0], 0x01);
  cr_assert_eq(bytes[1], 0x02);
  cr_assert_eq(bytes[2], 0x03);
  cr_assert_eq(bytes[3], 0x04);
  cr_assert_eq(bytes[4], 0x05);
  cr_assert_eq(bytes[5], 0x06);
  cr_assert_eq(bytes[6], 0x07);
  cr_assert_eq(bytes[7], 0x08);
}

Test(Endianness, LittleEndian) {
  auto value = 0x01020304;
  auto bytes = get_le_bytes(value);
  cr_assert_eq(bytes.size(), 4);
  cr_assert_eq(bytes[0], 0x04);
  cr_assert_eq(bytes[1], 0x03);
  cr_assert_eq(bytes[2], 0x02);
  cr_assert_eq(bytes[3], 0x01);
}

Test(Endianness, BigEndian) {
  auto value = 0x01020304;
  auto bytes = get_be_bytes(value);
  cr_assert_eq(bytes.size(), 4);
  cr_assert_eq(bytes[0], 0x01);
  cr_assert_eq(bytes[1], 0x02);
  cr_assert_eq(bytes[2], 0x03);
  cr_assert_eq(bytes[3], 0x04);
}
