//#include é uma diretiva do pré-processador C++.(uma biblioteca que permite a comunicação com o barramento I2C)
#include <Wire.h>

#define PCF_ADDR 0x20 

// Mapeamento dos pinos do Semáforo no PCF8574, uma especié de nomeação dos pinos
// os bytes representão quais portas serão ativadas
const byte TUDO_DESLIGADO = 0b00000000;
const byte LED_VERMELHO = 0b00000001; // P0
const byte LED_AMARELO  = 0b00000010; // P1
const byte LED_VERDE    = 0b00000100; // P2
const byte LED_VERMELHO2 = 0b00001000; // P4
const byte LED_AMARELO2  = 0b00100000; // P5
const byte LED_VERDE2    = 0b00100000; // P6