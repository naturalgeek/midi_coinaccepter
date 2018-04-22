const int coinInt = 0; 
volatile float coinsValue = 0.00;
const int buttonPin = 5;     // the number of the pushbutton pin
int coinInsert = 0;

void coinInserted() 
{
  coinsValue = coinsValue + 0.50;  
  Serial.print("Credit: Eur");
  Serial.println(coinsValue);    
 coinInsert = 1;
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  pinMode(A5, INPUT_PULLUP);
  attachInterrupt(coinInt, coinInserted, RISING);   
}

void blinkLED( int duration ) {
  int count = 0;
  while (count <= 10){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(duration);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(duration);
    count = count + 1; 
  }
}

void enablebuttons() {

  
 // Serial.print(c);
  while (true) {
  int c = analogRead(buttonPin);
    if (c>=919 && c<=921){
      Serial.print("Button 1\n");
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=924 && c<=926){
      Serial.print("Button 2\n");
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=927 && c<=928){
      Serial.print("Button 3\n");
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=930 && c<=932){
      Serial.print("Button 4\n");
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=934 && c<=935){
      Serial.print("Button 5\n");
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=937 && c<=938){
      Serial.print("Button 6\n");
      coinsValue = coinsValue - 1;
      break;
    }
    if (c>=940 && c<=941){
      Serial.print("Button 7\n");
      coinsValue = coinsValue - 1;
      break;
    }
   if (c>=942 && c<=943){
      Serial.print("Button 8\n");
      coinsValue = coinsValue - 1;
     break;
    }
  }
}

void loop()
{
  if(coinsValue >= 0.9){
    Serial.print("Enable Buttons");
    enablebuttons();
  }
}
