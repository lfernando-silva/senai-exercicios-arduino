//Link para o circuito: 
//https://www.tinkercad.com/things/jF5OeciTEIW-epic-jarv-bombul

int g = 13;
int f = 12;
int e = 11;
int d = 10;
int c = 9;
int b = 8;
int a = 7;

int button = 5;

bool isPressed = false;

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

void press(int button){
  if(digitalRead(button) == LOW){
    isPressed = !isPressed;
  	displayNumber(isPressed);
    while(digitalRead(button) == (LOW)){}
    delay(200);
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
  pinMode(button, INPUT_PULLUP);
  
  displayNumber(0);
}

void loop() {
	press(button);
}
