int verme1 = 13;
int verme2 = 5;
int amar1 = 12;
int amar2 = 6;
int verd1 = 11;
int verd2 = 7;

//criacao das variaveis
void setup()

{
//classificando as saídas
pinMode(verme1,OUTPUT);
pinMode(amar1,OUTPUT);
pinMode(verd1,OUTPUT);
pinMode(verme2,OUTPUT);
pinMode(amar2,OUTPUT);
pinMode(verd2,OUTPUT);

}

void loop()
{
digitalWrite(verme1,HIGH);//vermelho1 ligado
digitalWrite(amar1,LOW); //amarelo1 desligado
digitalWrite(verd1,LOW);//verde1 desligado

digitalWrite(verd2,HIGH);//verde2 ligado
digitalWrite(amar2,LOW);// amarelo2 desligado
digitalWrite(verme2,LOW);//verde2 desligado

delay(5000);

digitalWrite(verd2,LOW);//verde2 desliga
digitalWrite(amar2,HIGH);//amarelo2 Ligado

delay(2000);

digitalWrite(amar2,LOW);//amarelo2 desligado
digitalWrite(verme2,HIGH);//vermelho2 ligado
digitalWrite(verme1,LOW);//vermelho1 desligado
digitalWrite(verd1,HIGH);//verde1 ligado
delay(5000);

digitalWrite(verme2,HIGH);//vermelho2 ligado
digitalWrite(amar2,LOW); //amarelo2 desligado
digitalWrite(verd2,LOW);//verde2 desligado

digitalWrite(verd1,HIGH);//verde1 ligado
digitalWrite(amar1,LOW);// amarelo1 desligado
digitalWrite(verme1,LOW);//verde1 desligado

delay(5000);

digitalWrite(verd1,LOW);//verde1 desliga
digitalWrite(amar1,HIGH);//amarelo1 Ligado

delay(2000);

digitalWrite(amar1,LOW);//amarelo1 desligado
digitalWrite(verme1,HIGH);//vermelho1 ligado
digitalWrite(verme2,LOW);//vermelho2 desligado
digitalWrite(verd2,HIGH);//verde2 ligado
delay(5000);

}