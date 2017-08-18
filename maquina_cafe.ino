/*
Algoritmo do sketch - Máquina de café
Luiz Fernando da Silva - 17-08-2017

Link para o circuito:
https://www.tinkercad.com/things/h8oObaOgkFM-smooth-rottis-elzing
*/

int b1 = 2; //Café puro sem açucar
int b2 = 3; // Café puro com açúcar
int b3 = 4; //Café com leite sem açucar
int b4 = 5; //Café com leite com açucar
int b5 = 6; //Chocolate sem açúcar
int b6 = 7; //Chocolate com açucar
int b7 = 8; //Capuccino sem açúcar
int b8 = 9; //Capuccino com açúcar
int sc = 10; //Sensor de copo
int statusLed = 11; //Led indicador do estado da cafeteira: Apagado enquanto prepara, aceso quando está aguardando copo
int vr1 = A5; //Reservatório café solúvel
int vr2 = A4; //Reservatório leite em pó
int vr3 = A3; //Reservatório chocolate
int vr4 = A2; //Reservatório açúcar
int vr5 = A1; //Reservatório água quente

bool estaPressionado = false;
bool receitaFinalizada = false;

void inicializaBotoes();
void inicializaReservatorios();
void aguardaCopo();
void monitora(int botao);
void pisca(int led);
void monitora(int botao);
void mistura(int r1, int r2, int r3, int r4, int r5, int t1, int t2, int t3, int t4, int t5);

void setup() {
  inicializaBotoes();
  inicializaReservatorios();
}

void loop() {
  digitalWrite(statusLed, HIGH);
  aguardaCopo();
}

void inicializaBotoes() {
  for (int i = 2; i < 12; i++) pinMode(i, INPUT_PULLUP);
}

//Saídas em ordem crescente de tempo
void mistura(int r1, int r2, int r3, int r4, int r5, int t1, int t2, int t3, int t4, int t5) {

  if (t1 > 0) digitalWrite(r1, HIGH);
  if (t2 > 0) digitalWrite(r2, HIGH);
  if (t3 > 0) digitalWrite(r3, HIGH);
  if (t4 > 0) digitalWrite(r4, HIGH);
  if (t5 > 0) digitalWrite(r5, HIGH);

  if (t1 > 0) {
    delay(t1);
    digitalWrite(r1, LOW);
  }
  if (t2 > 0) {
    delay(t2);
    digitalWrite(r2, LOW);
  }
  if (t3 > 0) {
    delay(t3);
    digitalWrite(r3, LOW);
  }
  if (t4 > 0) {
    delay(t4);
    digitalWrite(r4, LOW);
  }
  if (t5 > 0) {
    delay(t5);
    digitalWrite(r5, LOW);
  }
  receitaFinalizada = true;
}

void aguardaCopo() {
  if (digitalRead(sc) == LOW) {
    receitaFinalizada = false;
    while (receitaFinalizada == false) {
      monitora(b1);
      monitora(b2);
      monitora(b3);
      monitora(b4);
      monitora(b5);
      monitora(b6);
      monitora(b7);
      monitora(b8);
    }
    delay(200);
  }
}

void inicializaReservatorios() {
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
}

void monitora(int botao) {
  if (digitalRead(botao) == LOW) {
    estaPressionado = true;
    while (estaPressionado) {
      digitalWrite(statusLed, LOW);
      if (botao == b1) mistura(vr1, vr5, 0, 0, 0, 3000, 2000, 0, 0, 0);
      if (botao == b2) mistura(vr1, vr4, vr5, 0, 0, 3000, 1000, 1000, 0, 0);
      if (botao == b3) mistura(vr1, vr2, vr5, 0, 0, 2000, 1000, 7000, 0, 0);
      if (botao == b4) mistura(vr1, vr2, vr4, vr5, 0, 2000, 1000, 1000, 3000, 0);
      if (botao == b5) mistura(vr2, vr3, vr5, 0, 0, 2000, 1000, 4000, 0, 0);
      if (botao == b6) mistura(vr2, vr3, vr4, vr5, 0, 2000, 1000, 1000, 3000, 0);
      if (botao == b7) mistura(vr1, vr2, vr3, vr5, 0, 2000, 2000, 1000, 3000, 0);
      if (botao == b8) mistura(vr1, vr2, vr3, vr4, vr5, 2000, 2000, 1000, 1000, 3000);
      break;
    }
    estaPressionado = false;
  }
  delay(200);
}
