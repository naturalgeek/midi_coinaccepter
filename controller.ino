const int coinInt = 0; 
volatile float coinsValue = 0.00;
const int buttonPin = 5;     // the number of the pushbutton pin
int coinInsert = 0;
int debug = 0;
int fakecoins = 0; // amount of fake coins to insert

const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;
const int ledPin4 = 12;
const int ledPin5 = 13;
const int ledPin6 = 6;
const int ledPin7 = 7;
const int ledPin8 = 8;

void coinInserted() 
{
  coinsValue = coinsValue + 0.50;  
  if (debug == 1) { Serial.print("Credit: Eur");};
  if (debug == 1) { Serial.println(coinsValue);};    
  if (debug == 1) { Serial.println("\r\n");};    
  coinInsert = 1;
}

void sendMidiNote(int pitch) {
  if (debug == 1) { Serial.write("MIDI BEGIN\r\n");};
  Serial.write(144);
  Serial.write(pitch);
  Serial.write(100);
  delay(300);
  Serial.write(144);
  Serial.write(pitch);
  Serial.write(0);
  delay(200);
  if (debug == 1) { Serial.write("MIDI END\r\n");};
}

void blinkLED( int pin ) {
  int count = 0;
  while (count <= 3){
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
    count = count + 1; 
  }
}

void ledFlash( int maxcount, int speed ) {
  int count = 0;
  while (count <= maxcount){
    digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin3, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin4, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin5, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin6, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin7, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin8, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(speed * 2.5);                       // wait for a second
    digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin2, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin3, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin4, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin5, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin6, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin7, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin8, LOW);    // turn the LED off by making the voltage LOW
    delay(speed);
    count = count + 1; 
  }
}

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  Serial.begin(9600);
  pinMode(A5, INPUT_PULLUP);
  attachInterrupt(coinInt, coinInserted, RISING);
  int c = analogRead(buttonPin);
  if (c>=1018 && c<=1024){
    debug = 1;
    if (debug == 1) { Serial.write("DEBUGGING ENABLED\r\n");};
    ledFlash(2, 300);
  }
  if (c>=1000 && c<=1008){
    fakecoins = 1;
    debug = 1;
    if (debug == 1) { Serial.write("DEBUGGING ENABLED\r\n");};
    if (debug == 1) { Serial.write("FAKECOIN ENABLED\r\n");};
    ledFlash(2, 300);
  }
}


void ledChase(int chasespeed) {
  int count = 0;
  while (count <= 0){
    digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin2, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    digitalWrite(ledPin3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin3, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    digitalWrite(ledPin4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin4, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    digitalWrite(ledPin5, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin5, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    digitalWrite(ledPin6, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin6, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    digitalWrite(ledPin7, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin7, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    digitalWrite(ledPin8, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(chasespeed * 2);                       // wait for a second
    digitalWrite(ledPin8, LOW);    // turn the LED off by making the voltage LOW
    delay(chasespeed);
    count = count + 1; 
  }
}

void enableAllLeds() {
    digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin3, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin4, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin5, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin6, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin7, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin8, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void disableAllLeds() {
    digitalWrite(ledPin1, LOW);   // turn the LED on (LOW is the voltage level)
    digitalWrite(ledPin2, LOW);   // turn the LED on (LOW is the voltage level)
    digitalWrite(ledPin3, LOW);   // turn the LED on (LOW is the voltage level)
    digitalWrite(ledPin4, LOW);   // turn the LED on (LOW is the voltage level)
    digitalWrite(ledPin5, LOW);   // turn the LED on (LOW is the voltage level)
    digitalWrite(ledPin6, LOW);   // turn the LED on (LOW is the voltage level)
    digitalWrite(ledPin7, LOW);   // turn the LED on (LOW is the voltage level)
    digitalWrite(ledPin8, LOW);   // turn the LED on (LOW is the voltage level)
}


void enablebuttons() {
// no button: 734-738
  enableAllLeds();
  while (true) {
  int c = analogRead(buttonPin);
  if (debug == 1) { Serial.print("ADC Button Value: ");};
  if (debug == 1) { Serial.print(c);};
  if (debug == 1) { Serial.print("\r\n");};
    if (c>=1018 && c<=1024){
      if (debug == 1) {Serial.print("Button 1 Pressedr\r\n");};
      disableAllLeds();
      blinkLED(ledPin1);
      sendMidiNote(50);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=995 && c<=1014){
      if (debug == 1) {Serial.print("Button 2 Pressed\r\n");};
      disableAllLeds();
      blinkLED(ledPin2);
      sendMidiNote(51);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=950 && c<=994){
      if (debug == 1) {Serial.print("Button 3 Pressed\r\n");};
      disableAllLeds();
      blinkLED(ledPin3);
      sendMidiNote(52);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=890 && c<=910){
      if (debug == 1) {Serial.print("Button 4 Pressed\r\n");};
      disableAllLeds();
      blinkLED(ledPin4);
      sendMidiNote(53);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=750 && c<=780){
      if (debug == 1) {Serial.print("Button 5 Pressedr\r\n");};
      disableAllLeds();
      blinkLED(ledPin5);
      sendMidiNote(54);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=600 && c<=640){
      if (debug == 1) {Serial.print("Button 6 Pressed\r\n");};
      disableAllLeds();
      blinkLED(ledPin6);
      sendMidiNote(55);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=440 && c<=520){
      if (debug == 1) {Serial.print("Button 2 Pressed\r\n");};
      disableAllLeds();
      blinkLED(ledPin7);
      sendMidiNote(56);
      coinsValue = coinsValue - 1;
      break;
    }
 //  if (c>=942 && c<=943){
 //     if (debug == 1) {Serial.print("Button 2 Pressed\r\n");};
 //     Serial.print("Button 8\r\n");
 //     disableAllLeds();
 //     blinkLED(ledPin8);
 //     sendMidiNote(57);
 //     coinsValue = coinsValue - 1;
 //     break;
 //   }
    delay(100);
  }
 if (debug == 1) { Serial.print("Credit: ");};
 if (debug == 1) { Serial.print(coinsValue);};
  if (coinsValue >= 1) {
    while (true) {
     int c = analogRead(buttonPin);
     if (c>=734 && c<=739){
       break;
     }
    }
    int c = 735;
    delay(50);
  }
}

void loop()
{
  ledChase(40);
  if(coinsValue >= 1.0){
    if (debug == 1) { Serial.print("Enable Buttons");};
    enablebuttons();
  }
  delay(80);
  ledChase(40);
  if(coinsValue >= 1.0){
    if (debug == 1) {Serial.print("Enable Buttons");};
    enablebuttons();
  }
  delay(80);

  // insert Fake Coins at the end of the catching effect
  if (fakecoins >= 1) {
    coinsValue = coinsValue + fakecoins;
  }

  ledFlash(2, 50);
  if(coinsValue >= 1.0){
    if (debug == 1) {Serial.print("Enable Buttons");};
    enablebuttons();
  }
  delay(80);

}
