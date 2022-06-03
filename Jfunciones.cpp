#include "Jfunciones.hpp"
void limpiarBuffer(Stream *puerto){
  while(puerto->available()>0) puerto->read();
}
void limpiarCadena(char* limpiar, int largo){ 
  for(int i = 0; i<largo;i++){
    Serial.println(limpiar[i]);
    limpiar[i]='\0';
  }
}

void setOC1A(uint8_t nibble){
  if (nibble > 3) nibble = 0;
  TCCR1A |= (((nibble&2)>>1)<<COM1A1) | ((nibble&1)<<COM1A0) ;
}
void setOC1B(uint8_t nibble){
  if (nibble > 3) nibble = 0;
  TCCR1A |= (((nibble&2)>>1)<<COM1B1) | ((nibble&1)<<COM1B0) ;
}
void setTimer1PRE(uint8_t nibble){
  if (nibble > 7) nibble = 0;
  TCCR1B |= (((nibble&2)>>1)<<CS12) | (((nibble&4)>>2)<<CS11) | (nibble&1<<CS10);
}
void setTimer1WGM(uint8_t nibble){
  if (nibble > 15) nibble = 0;
  TCCR1B |= (((nibble&8)>>3)<<WGM13) | (((nibble&4)>>2)<<WGM12);
  TCCR1A |= (((nibble&2)>>1)<<WGM11) | ((nibble&1)<<WGM10);
}
