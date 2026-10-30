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
// Semáfaro 3
const byte LED_VERMELHO3 = 0b00000001; // P0
const byte LED_AMARELO3  = 0b00000010; // P1
const byte LED_VERDE3    = 0b00000100; // P2

//Semáfaro ciclista 1
const byte LED_VERMELHO_CICLI1    = 0b00001000; // P3
const byte LED_VERDE_CICLI1    = 0b00010000; // P4

//Semáfaro 4
const byte LED_VERMELHO4    = 0b00100000; // P5
const byte LED_AMARELO4  = 0b01000000; // P6
const byte LED_VERDE4 = 0b10000000; // P7

#define PCF2_ADDR 0x22

// Mapeamento dos pinos do Semáforo no terceiro PCF8574, uma especié de nomeação dos pinos
// os bytes representão quais portas serão ativadas
// Semáfaro 5
const byte LED_VERMELHO5 = 0b00000001; // P0
const byte LED_AMARELO5  = 0b00000010; // P1
const byte LED_VERDE5    = 0b00000100; // P2

//Semáfaro pedestre 2
const byte LED_VERMELHO_PED2    = 0b00001000; // P3
const byte LED_VERDE_PED2    = 0b00010000; // P4

//Semáfaro 6
const byte LED_VERMELHO6    = 0b00100000; // P5
const byte LED_AMARELO6  = 0b01000000; // P6
const byte LED_VERDE6 = 0b10000000; // P7
// Função auxiliar para enviar o comando ao PCF8574
// para que o arduino execute essa função é preciso fazelo entender que estamos querendo dizer
// agora esssa função envia no determinado endereço o byte que precisamos

void enviarParaPCF(byte endereco, byte estado) {
  //agora que existem dois I2C, precisamos especificar qual deles queremos enviar o comando, por isso o parametro endereco
  Wire.beginTransmission(endereco); // 1. Inicia conversa com o CI
  //chamamos o respectivo CI que queremos conversar
  Wire.write(~estado);              // 2. Envia a combinação de LEDs
  //mandamos para tal porta um sinal de byte(o ~ inverte o sinal), o fazebdo sair de nivel logico 0
  Wire.endTransmission();          // 3. Encerra a conversa
}
void setup() {
  Wire.begin(); // Inicializa o barramento I2C
  enviarParaPCF(PCF0_ADDR, TUDO_DESLIGADO); // Garante que o primeiro I2C comece com todos os LEDs desligados
  enviarParaPCF(PCF1_ADDR, TUDO_DESLIGADO); // Garante que o segundo I2C comece com todos os LEDs desligados
  enviarParaPCF(PCF2_ADDR, TUDO_DESLIGADO); // Garante que o terceiro I2C comece com todos os LEDs desligados
  // todo o sistema começara sem sinal nenhum em byte
}

void loop() {
  // 1. Estado VERDE1 E VERMELHO2 E VERDE_PED1
  enviarParaPCF(PCF0_ADDR,
    LED_VERDE1|LED_VERMELHO2|LED_VERDE_PED1);
   // 1a. Estado VERDE3 E VERMELHO4 E VERDE_CICLI1
  enviarParaPCF(PCF1_ADDR,
    LED_VERDE3|LED_VERMELHO4|LED_VERDE_CICLI1);
   // 1b. Estado VERDE5 E VERMELHO6 E VERDE_PED2
  enviarParaPCF(PCF2_ADDR,
    LED_VERDE5|LED_VERMELHO6|LED_VERDE_PED2);

  delay(5000); // Fica verde e vermelho por 5 segundos

  // 2. Estado AMARELO1 aciona e VERDE1 desliga, VERMELHO2 e VERDE_PED1 permanecem acesos
  enviarParaPCF(PCF0_ADDR,
    LED_AMARELO1|LED_VERMELHO2|LED_VERDE_PED1);
   // 2a. Estado AMARELO3 aciona e VERDE3 desliga, VERMELHO4 e VERDE_CICLI1 permanecem acesos
  enviarParaPCF(PCF1_ADDR,
    LED_AMARELO3|LED_VERMELHO4|LED_VERDE_CICLI1);
   // 2b. Estado AMARELO5 aciona e VERDE5 desliga, VERMELHO6 e VERDE_PED2 permanecem acesos
  enviarParaPCF(PCF2_ADDR,
    LED_AMARELO5|LED_VERMELHO6|LED_VERDE_PED2);

  delay(3000); // Fica amarelo por 3 segundos

  // 3. Estado VERMELHO1, VERDE2 e VERMELHO_PED1 acionam e AMARELO1, VERMELHO2 e VERDE_PED1 desligam
  enviarParaPCF(PCF0_ADDR,
      LED_VERMELHO1|LED_VERDE2|LED_VERMELHO_PED1);
   // 3a. Estado VERMELHO3, VERDE4 e VERMELHO_CICLI1 acionam e AMARELO3, VERMELHO4 e VERDE_CICLI1 desligam
  enviarParaPCF(PCF1_ADDR,
      LED_VERMELHO3|LED_VERDE4|LED_VERMELHO_CICLI1);
   // 3b. Estado VERMELHO5, VERDE6 e VERMELHO_PED2 acionam e AMARELO5, VERMELHO6 e VERDE_PED2 desligam
  enviarParaPCF(PCF2_ADDR,
      LED_VERMELHO5|LED_VERDE6|LED_VERMELHO_PED2);

  delay(5000); // Fica vermelho por 5 segundos
  
   // 4. Estado AMARELO2 aciona e VERDE2 desliga, VERMELHO1 e VERMELHO_PED1 permanecem acesos
  enviarParaPCF(PCF0_ADDR,
    LED_VERMELHO1|LED_AMARELO2|LED_VERMELHO_PED1);
   // 4a. Estado AMARELO4 aciona e VERDE4 desliga, VERMELHO3 e VERMELHO_CICLI1 permanecem acesos 
  enviarParaPCF(PCF1_ADDR,
    LED_VERMELHO3|LED_AMARELO4|LED_VERMELHO_CICLI1);
   // 4b. Estado AMARELO6 aciona e VERDE6 desliga, VERMELHO5 e VERMELHO_PED2 permanecem acesos
  enviarParaPCF(PCF2_ADDR,
    LED_VERMELHO5|LED_AMARELO6|LED_VERMELHO_PED2);
  delay(3000); // Fica amarelo por 3 segundos

}