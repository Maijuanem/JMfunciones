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