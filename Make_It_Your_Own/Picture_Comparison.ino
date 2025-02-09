int led = 13; // led that we will toggle
char inChar;  // character we will use for messages from the RPi

int button = 2;
int button2 = 3;
int buttonState;
int buttonState2;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // read the character we recieve on the serial port from the RPi
  if(Serial.available()) {
    inChar = (char)Serial.read();
  }

  // if we get a 'H', turn the LED on, else turn it off
  if(inChar == 'H'){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

  // Button event checker - if pressed, send message to RPi
  int newState = digitalRead(button);
  if (buttonState != newState) {
    buttonState = newState;
    if(buttonState == HIGH){
      Serial.println("1st Picture"); //note println put a /r/n at the end of a line
    }
  }

  int newState2 = digitalRead(button2);
  if (buttonState2 != newState2) {
    buttonState2 = newState2;
    if(buttonState2 == HIGH){
      Serial.println("2nd Picture"); //note println put a /r/n at the end of a line
    }
  }
}
