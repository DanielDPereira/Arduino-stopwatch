#include <Arduino.h> 
#include <TM1637Display.h> 

#define CLK 2 
#define DIO 3 
#define TEST_DELAY 2000 

TM1637Display display(CLK, DIO); 

unsigned long tempoInicial = 0; 
unsigned long tempoAtual = 0; 
unsigned long tempoDecorrido = 0; 
unsigned long tempoDecorridoM = 0; 
int minutos = 0;
int segundos = 0;

void setup() {
  display.setBrightness(0x0f); 
  Serial.begin(9600);
  tempoInicial = millis(); // Inicializa o tempo inicial
}

void loop() {
  tempoAtual = millis(); // Obtém o tempo atual em milissegundos
  tempoDecorrido = (tempoAtual - tempoInicial) / 1000; // Calcula o tempo decorrido em segundos
  minutos = tempoDecorrido / 60;
  segundos = tempoDecorrido - minutos*60;
  

  display.showNumberDecEx(minutos*100 + segundos, 0b11100000, true); // Exibe o tempo decorrido no display

  Serial.println(minutos); // Exibe o tempo decorrido no monitor serial
}
