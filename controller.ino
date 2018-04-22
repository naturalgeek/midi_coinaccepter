const int coinInt = 0; 
volatile float coinsValue = 0.00;
const int buttonPin = 5;     // the number of the pushbutton pin
int coinInsert = 0;

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
  Serial.print("Credit: Eur");
  Serial.println(coinsValue);    
  coinInsert = 1;
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


void enablebuttons() {

  
  //Serial.print(c);
// no button: 734-738

  while (true) {
  int c = analogRead(buttonPin);
//  Serial.print(c);
//  Serial.print(" ");
    if (c>=1022 && c<=1024){
      Serial.print("Button 1\n");
      blinkLED(ledPin1);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=1002 && c<=1004){
      Serial.print("Button 2\n");
      blinkLED(ledPin2);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=985 && c<=987){
      Serial.print("Button 3\n");
      blinkLED(ledPin3);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=969 && c<=971){
      Serial.print("Button 4\n");
      blinkLED(ledPin4);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=955 && c<=958){
      Serial.print("Button 5\n");
      blinkLED(ledPin5);
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=944 && c<=946){
      Serial.print("Button 6\n");
      blinkLED(ledPin6);
      coinsValue = coinsValue - 1;
      break;
    }
 //   if (c>=940 && c<=941){
 //     Serial.print("Button 7\n");
//      blinkLED(ledPin7);
 //     coinsValue = coinsValue - 1;
 //     break;
 //   }
 //  if (c>=942 && c<=943){
  //    Serial.print("Button 8\n");
 //     blinkLED(ledPin8);
 //     coinsValue = coinsValue - 1;
 //     break;
 //   }
    delay(100);
  }
  Serial.print("Credit: ");
  Serial.print(coinsValue);
  while (true) {
    int c = analogRead(buttonPin);
    if (c>=734 && c<=739){
      break;
    }
    delay(50);
  }
}

void loop()
{
  ledChase(40);
  if(coinsValue >= 0.9){
    Serial.print("Enable Buttons");
    enablebuttons();
  }
  delay(80);
  ledChase(40);
  if(coinsValue >= 0.9){
    Serial.print("Enable Buttons");
    enablebuttons();
  }
  delay(80);
//   ledChase(40);
//  if(coinsValue >= 0.9){
//    Serial.print("Enable Buttons");
//    enablebuttons();
//  }
  ledFlash(3, 50);
  if(coinsValue >= 0.9){
    Serial.print("Enable Buttons");
    enablebuttons();
  }
  delay(80);

}
