
// const: define valores que não devem ser alterados.
const int verme1 = 13;
const int verme2 = 5;

const int amar1 = 12;
const int amar2 = 6;

const int verd1 = 11;
const int verd2 = 7;

void setup()
{
    // Configura os pinos como saídas.
    pinMode(verme1, OUTPUT);
    pinMode(amar1, OUTPUT);
    pinMode(verd1, OUTPUT);

    pinMode(verme2, OUTPUT);
    pinMode(amar2, OUTPUT);
    pinMode(verd2, OUTPUT);

    // Inicializa todos os LEDs desligados.
    digitalWrite(verme1, LOW);
    digitalWrite(amar1, LOW);
    digitalWrite(verd1, LOW);

    digitalWrite(verme2, LOW);
    digitalWrite(amar2, LOW);
    digitalWrite(verd2, LOW);
}



// 3. SEMÁFORO 2 VERDE E SEMÁFORO 1 VERMELHO

void semafaroVerde2Vermelho1()
{
    // Semáforo 1: vermelho ligado.
    digitalWrite(verme1, HIGH);
    digitalWrite(amar1, LOW);
    digitalWrite(verd1, LOW);

    // Semáforo 2: verde ligado.
    digitalWrite(verme2, LOW);
    digitalWrite(amar2, LOW);
    digitalWrite(verd2, HIGH);

    delay(5000);
}



// 4. SEMÁFORO 2 AMARELO


void semafaroAmarelo2()
{
    // Semáforo 2: verde desligado e amarelo ligado.
    digitalWrite(verd2, LOW);
    digitalWrite(amar2, HIGH);

    delay(2000);
}



// 5. AMBOS OS SEMÁFOROS VERMELHOS

void ambosVermelhos()
{
    // Semáforo 1: vermelho ligado.
    digitalWrite(verme1, HIGH);
    digitalWrite(amar1, LOW);
    digitalWrite(verd1, LOW);

    // Semáforo 2: vermelho ligado.
    digitalWrite(verme2, HIGH);
    digitalWrite(amar2, LOW);
    digitalWrite(verd2, LOW);

    delay(1000);
}



// 6. SEMÁFORO 2 VERMELHO E SEMÁFORO 1 VERDE

void semafaroVermelho2Verde1()
{
    // Semáforo 2: vermelho ligado.
    digitalWrite(verme2, HIGH);
    digitalWrite(amar2, LOW);
    digitalWrite(verd2, LOW);

    // Semáforo 1: verde ligado.
    digitalWrite(verme1, LOW);
    digitalWrite(amar1, LOW);
    digitalWrite(verd1, HIGH);

    delay(5000);
}



// 7. SEMÁFORO 1 AMARELO

void semafaroAmarelo1()
{
    // Semáforo 1: verde desligado e amarelo ligado.
    digitalWrite(verd1, LOW);
    digitalWrite(amar1, HIGH);

    delay(2000);
}



// 8. CICLO PRINCIPAL


void loop()
{
    // Primeira via liberada.
    semafaroVerde2Vermelho1();

    // Preparação para fechar a primeira via.
    semafaroAmarelo2();

    // Intervalo de segurança didático.
    ambosVermelhos();

    // Segunda via liberada.
    semafaroVermelho2Verde1();

    // Preparação para fechar a segunda via.
    semafaroAmarelo1();

    // Intervalo de segurança didático.
    ambosVermelhos();
}