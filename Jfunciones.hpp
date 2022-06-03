

#include "Arduino.h"
#include "string.h"

#define tglBit(reg,bit)		reg ^=  (1<<bit)
#define highBit(reg,bit)	reg |= 	(1<<bit)
#define lowBit(reg,bit)		reg &= 	~(1<<bit)
#define testBit(reg,bit)	(reg &(1<<bit))

void limpiarCadena(char*, int);
void limpiarBuffer(Stream*);
void setTimer1WGM(uint8_t );