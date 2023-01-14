#define ledPin 13


// Sending data, every index one by one
void writeSerial(String stringData) { // The data had been sent as String

  for (int i = 0; i < stringData.length(); i++) {
    Serial.write(stringData[i]); 
    delay(100);
  }
  Serial.write('\0');

}

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
   while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}

void turnOn(int pin){         // set HIGH the given pin
  digitalWrite(pin,HIGH);
}

void turnOff(int pin){        // set LOW the given pin
  digitalWrite(pin , LOW);
}

void blink(){
       for(int i=0; i<3; i++)
     {
      turnOn(ledPin);
      delay(300);
      turnOff(ledPin);
      delay(300);
     }
}

void loop() {

  while(Serial.available() == 0);

  //Reading the input
  String val = Serial.readStringUntil('\n');
  
  if(val == "1") {
    turnOn(ledPin); //if choice is 1 turn on the led
  }
  
  else if(val == "2") {
    turnOff(ledPin);  // if choice is 2 turn off the led
  }
  else if(val == "3") {        // if choice is 3 blink the led
    blink();
  }
  
  else if(val == "4") {        // if choice is 4 get the squared of given number
     while(Serial.available() == 0);
    double num = Serial.readStringUntil('\0').toInt();
    delay(50);
    writeSerial(String(num*num));
  }

  Serial.flush(); // Waiting until the data fully sent
}
