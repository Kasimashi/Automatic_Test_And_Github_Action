/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    crc32.c
  \brief   Software implementation for CRC-32
  \version 20211111
*/

#include "library.h"

#define CRC32_POLY 0x04C11DB7
/* The `no_size_constraints` directive will make the function run as fast as possible */
#pragma optimize=no_size_constraints
uint32_t fastCRC32(uint32_t crc, uint32_t const* data, uint32_t words) {
  const uint32_t crc32NibbleLUT[16] = {
    0x00000000,CRC32_POLY,0x09823B6E,0x0D4326D9,
    0x130476DC,0x17C56B6B,0x1A864DB2,0x1E475005,
    0x2608EDB8,0x22C9F00F,0x2F8AD6D6,0x2B4BCB61,
    0x350C9B64,0x31CD86D3,0x3C8EA00A,0x384FBDBD, };
  while(words--) {
    crc = crc ^ *data++;
    /* 8 rounds * 4-bit(nibble) = 32 bit(word) */
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
    crc = (crc << 4) ^ crc32NibbleLUT[crc >> 28];
  }
  return(crc);
}
