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

// Função auxiliar para enviar o comando ao PCF8574
// para que o arduino execute essa função é preciso fazelo entendero que estamos querendo dizer

void enviarParaPCF(byte estado) {
  Wire.beginTransmission(PCF_ADDR); // 1. Inicia conversa com o CI
  //chamamos o CI que queremos conversar
  Wire.write(estado);              // 2. Envia a combinação de LEDs
  //mandamos para tal porta um sinal de byte, o fazebdo sair de nivel logico 0
  Wire.endTransmission();          // 3. Encerra a conversa
}

void setup() {
  Wire.begin(); // Inicializa o barramento I2C
  enviarParaPCF(TUDO_DESLIGADO); // Garante que tudo comece apagado
  // todo o sistema começara sem sinal nenhum em byte
}

void loop() {
  // 1. Estado VERDE E VERMELHO
  enviarParaPCF(LED_VERDE);
  enviarParaPCF(LED_VERMELHO2);
  delay(5000); // Fica verde e vermelho por 5 segundos

  // 2. Estado AMARELO
  enviarParaPCF(LED_AMARELO);
  enviarParaPCF(LED_VERMELHO2);

  delay(2000); // Fica amarelo por 2 segundos

  // 3. Estado VERMELHO
  enviarParaPCF(LED_VERMELHO);
  enviarParaPCF(LED_VERDE2);

  delay(5000); // Fica vermelho por 5 segundos
  
   // 4. Estado AMARELO
  enviarParaPCF(LED_AMARELO2);
  enviarParaPCF(LED_VERMELHO);

  delay(2000); // Fica amarelo por 2 segundos

}