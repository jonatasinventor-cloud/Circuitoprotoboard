//Exp 3 - onde será adicionada semafaro para pedestre e ciclistas, junto com mais 2 PCF8574,basicamente triplicando o número de semafaros presentes.
//#include é uma diretiva do pré-processador C++.(uma biblioteca que permite a comunicação com o barramento I2C)
#include <Wire.h>

#define PCF0_ADDR 0x20 

// Mapeamento dos pinos do Semáforo no primeiro PCF8574, uma especié de nomeação dos pinos
// os bytes representão quais portas serão ativadas
// Semáfaro 1
const byte TUDO_DESLIGADO = 0b00000000;
const byte LED_VERMELHO1 = 0b00000001; // P0
const byte LED_AMARELO1  = 0b00000010; // P1
const byte LED_VERDE1    = 0b00000100; // P2

//Semáfaro pedestre 1
const byte LED_VERMELHO_PED1    = 0b00001000; // P3
const byte LED_VERDE_PED1    = 0b00010000; // P4

//Semáfaro 2
const byte LED_VERMELHO2    = 0b00100000; // P5
const byte LED_AMARELO2  = 0b01000000; // P6
const byte LED_VERDE2 = 0b10000000; // P7

#define PCF1_ADDR 0x21

// Mapeamento dos pinos do Semáforo no segundo PCF8574, uma especié de nomeação dos pinos
// os bytes representão quais portas serão ativadas
// Semáfaro 1
const byte LED_VERMELHO3 = 0b00000001; // P0
const byte LED_AMARELO3  = 0b00000010; // P1
const byte LED_VERDE3    = 0b00000100; // P2

//Semáfaro pedestre 1
const byte LED_VERMELHO_PED2    = 0b00001000; // P3
const byte LED_VERDE_PED2    = 0b00010000; // P4

//Semáfaro 2
const byte LED_VERMELHO4    = 0b00100000; // P5
const byte LED_AMARELO4  = 0b01000000; // P6
const byte LED_VERDE4 = 0b10000000; // P7

// Função auxiliar para enviar o comando ao PCF8574
// para que o arduino execute essa função é preciso fazelo entendero que estamos querendo dizer

void enviarParaPCF(byte estado) {
  Wire.beginTransmission(PCF0_ADDR|PCF1_ADDR); // 1. Inicia conversa com o CI
  //chamamos o CI que queremos conversar
  Wire.write(~estado);              // 2. Envia a combinação de LEDs
  //mandamos para tal porta um sinal de byte(o ~ inverte o sinal), o fazebdo sair de nivel logico 0
  Wire.endTransmission();          // 3. Encerra a conversa
}
void setup() {
  Wire.begin(); // Inicializa o barramento I2C
  enviarParaPCF(TUDO_DESLIGADO); // Garante que tudo comece apagado
  // todo o sistema começara sem sinal nenhum em byte
}

void loop() {
  // 1. Estado VERDE1 E VERMELHO2 E VERDE_PED1

  enviarParaPCF(LED_VERDE1|LED_VERMELHO2|LED_VERDE_PED1);
  delay(5000); // Fica verde e vermelho por 5 segundos

  // 2. Estado AMARELO
  enviarParaPCF(LED_AMARELO1|LED_VERMELHO2|LED_VERDE_PED1);

  delay(3000); // Fica amarelo por 3 segundos

  // 3. Estado VERMELHO
  enviarParaPCF(LED_VERMELHO1|LED_VERDE2|LED_VERMELHO_PED1);

  delay(5000); // Fica vermelho por 5 segundos
  
   // 4. Estado AMARELO
  enviarParaPCF(LED_VERMELHO1|LED_AMARELO2|LED_VERMELHO_PED1);

  delay(3000); // Fica amarelo por 3 segundos

}