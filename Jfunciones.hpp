#include "Arduino.h"
#include "string.h"

#define tglBit(reg,bit)		        reg ^=  (1<<bit)
#define highBit(reg,bit)	        reg |= 	(1<<bit)
#define lowBit(reg,bit)		        reg &= 	~(1<<bit)
#define testBit(reg,bit)	        (reg &(1<<bit))
#define habilitarIntTimer1OVF       highBit(TIMSK1,TOIE1)
#define deshabilitarIntTimer1OVF    lowBit(TIMSK1,TOIE1) 

typedef enum{
    NO_CLOCK_SOURC,
    CLK_DIV1,
    CLK_DIV8,
    CLK_DIV64,
    CLK_DIV256,
    CLK_DIV1024,
    EXT_CLOCK_FALLING,
    EXT_CLOCK_RISING,
}clockSelectBitTimerAVR;
typedef enum{
    NORMAL,
    PWM_8_BIT,
    PWM_9_BIT,
    PWM_10_BIT,
    CTC_TOP_OCR1A,
    FAST_PWM_8_BIT,
    FAST_PWM_9_BIT,
    FAST_PWM_10_BIT,
    PWM_FFCORRECTA_TOP_ICR1,
    PWM_FFCORRECTA_TOP_OCR1A,
    PWM_FCORRECTA_TOP_ICR1,
    PWM_FCORRECTA_TOP_OCR1A,
    CTC_TOP_ICR1,
    NONE,
    FAST_PWM_TOP_ICR1,
    FAST_PWM_TOP_OCR1A,
}waveformGenerationModeAVR;
typedef enum{
    PIN_DESCONECTADO,
    PIN_TOGGLE,
    PIN_NO_INVERTIDO_PWM,
    PIN_INVERTIDO_PWM,
}configuracionPinTimerAVR;

void limpiarCadena(char*, int);
void limpiarBuffer(Stream*);
void setTimer1WGM(uint8_t );
void setTimer1PRE(uint8_t);
void setOC1A(uint8_t nibble);
void setOC1B(uint8_t nibble);
