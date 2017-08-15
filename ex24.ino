/*
Link para o circuito: 
https://www.tinkercad.com/things/kFB3vXENkBm-epic-jarv-bombul-2

24) Projete um hardware e um software utilizando Arduino que apresente uma contagem
em ordem crescente de 0 a 9 no display de 7 segmentos, incrementando a contagem
a cada 0,5 segundo.
*/

int g = 13;
int f = 12;
int e = 11;
int d = 10;
int c = 9;
int b = 8;
int a = 7;

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

void displayNumber(int number){
  for(int i = 0; i < 7; i++){
  	digitalWrite(i+7, values[number][i]);
  }
}

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);  
}

void loop() {
  for(int i = 0; i < 10; i++){
  	displayNumber(i);
    delay(500);
  }
}
