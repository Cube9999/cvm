#ifndef BITREADER_H
#define BITREADER_H
#include <stdint.h>

uint16_t read16(uint8_t* buff, int idx) 
{
	return (buff[idx] << 8) | (buff[idx + 1]);
}
uint32_t read32(uint8_t* buff, int idx) 
{
	return (buff[idx] << 24) | (buff[idx + 1] << 16) 
			| (buff[idx + 2] << 8) | (buff[idx + 3]);
}


#endif