int allLeds[] = {2, 4, 6, 8, 10, 12};
int numLeds = sizeof(allLeds) / sizeof(allLeds[0]);

int ledsRed[] = {2, 4, 6};
int ledsBlue[] = {8, 10, 12};

int button = 3;
volatile int mode = 0;
volatile int lastButtonState = 1;

int delayInMileseconds = 100;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(allLeds[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), controlState, CHANGE);
}

void loop() {
  if(mode == 0){
    return;
  }

  ativado();
}

void ativado() {
  for (int i = 0; i < 3; i++) {
    int indexBlue = i;
    int indexRed = 2 - i;

    digitalWrite(ledsRed[indexRed], HIGH);
    digitalWrite(ledsBlue[indexBlue], HIGH);
    delay(delayInMileseconds);
    digitalWrite(ledsRed[indexRed], LOW);
    digitalWrite(ledsBlue[indexBlue], LOW);
  }
  for (int i = 0; i < 3; i++) {
    int indexRed = i;
    int indexBlue = 2 - i;

    digitalWrite(ledsRed[indexRed], HIGH);
    digitalWrite(ledsBlue[indexBlue], HIGH);
    delay(delayInMileseconds);
    digitalWrite(ledsRed[indexRed], LOW);
    digitalWrite(ledsBlue[indexBlue], LOW);
  }
}

void controlState(){
  int buttonState = digitalRead(button);

  if(buttonState == LOW && buttonState != lastButtonState){ 
    mode = !mode;
  }
  lastButtonState = buttonState;
}