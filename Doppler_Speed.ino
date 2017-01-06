const int LedPin = 13
const int LdrPin = A0
const int DopPin =
int value = 0
int threshold = 2500

#define light = 1
#define dark = 0

int situation = light

void setup() {
  // Defining Start Config:
  pinMode (LedPin, OUTPUT)
  pinMode (LdrPin, INPUT)
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead (LdrPin)
  Serial.print(value)
  Serial.println()

  if (situation == light && value < threshold) {
    digitalWrite (DopPin, HIGH) //Here comes the Doppler
    situation = dark //Measurments start here
  }
  else if (situation == dark && value > threshold){
    digitalWrite (DopPin, LOW)
    
  }
}
