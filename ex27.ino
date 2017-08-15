/*
Link para o circuito: 
https://www.tinkercad.com/things/kFB3vXENkBm-epic-jarv-bombul-3

27) Projete um hardware e um software utilizando Arduino que apresente uma contagem
em ordem crescente de 0 a 99 em dois displays de 7 segmentos, incrementando a
contagem a cada 0,5 segundo.
*/

int g1 = 13;
int f1 = 12;
int e1 = 11;
int d1 = 10;
int c1 = 9;
int b1 = 8;
int a1 = 7;
int g2 = 6;
int f2 = 5;
int e2 = 4;
int d2 = 3;
int c2 = 2;
int b2 = 1;
int a2 = 0;

int firstDisplay = 7; // Primeiro display termina no pino 7
int secondDisplay = 0; // Segundo display termina no pino 0

int values[10][7] = {
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0}, 
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0}  
};

void displayNumber(int number, int display){
  for(int i = 0; i < 7; i++){
  	digitalWrite(i+display, values[number][i]);
  }
}

void setup() {
  pinMode(a1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(f1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(f2, OUTPUT);
  pinMode(g2, OUTPUT);
}

void loop() {
  for(int i = 0; i < 10; i++){
    displayNumber(i,firstDisplay);
      for(int j = 0; j < 10; j++){
        displayNumber(j,secondDisplay);
        delay(500);
      }
  }  
}
