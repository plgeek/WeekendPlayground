const int FinPin = 4;
const int RinPin = 3;
const int VrefPin = 1;
const int SOutPin = 2;
const int LedPin = 0;
void setMotor(bool reverse,byte speed) {
 if(reverse) {
  digitalWrite(FinPin, LOW);
  digitalWrite(RinPin, HIGH);
 } else {  
   digitalWrite(FinPin, HIGH);
   digitalWrite(RinPin, LOW);
 }
  analogWrite(VrefPin,speed);
}

void motorsOff() {
  digitalWrite(FinPin, LOW);
  digitalWrite(RinPin, LOW);
  analogWrite(VrefPin,0);
}
uint32_t readIntensity() {
  uint32_t pulseWidth_usecs = 0;
  const int samples = 100;
  for(int i = 0; i < samples; i++) {
    pulseWidth_usecs += pulseIn(SOutPin,LOW);
  }
  uint32_t freqHz = (500000*samples)/pulseWidth_usecs;
  return freqHz;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(FinPin, OUTPUT);
  pinMode(RinPin, OUTPUT);
  pinMode(VrefPin, OUTPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(SOutPin, INPUT);
}

void flashLed(uint32_t ms) {
   digitalWrite(LedPin,HIGH);
   delay(ms/2);
   digitalWrite(LedPin,LOW);
   delay(ms/2);
}
void takeoff() {
   digitalWrite(FinPin,LOW);
   digitalWrite(RinPin,LOW);
   for(int i = 0; i < 5; i++) {
      flashLed(1000);
   }
   setMotor(false,0);
   for(int j = 0; j < 255; j++) {
       setMotor(false,j);
       delay(50);
   };
}

void land() {
   motorsOff();
   for(int i = 0; i < 10; i++) {
    flashLed(100);
   }
}
// find target intensity
uint32_t survey(uint32_t seconds) {
    uint32_t maxS = 0;
    uint32_t currS = 0;
    const uint32_t cruise = 128;
    setMotor(false,cruise);
    uint64_t stopT = millis() + (seconds * 1000);
    while(millis() < stopT) {
      currS = readIntensity();
      if(currS >= maxS) {
        maxS = currS;
      }
    }
    setMotor(true,cruise);
    stopT = millis() + (seconds * 1000);
    while(millis() < stopT) {
      currS = readIntensity();
      if(currS >= maxS) {
        maxS = currS;
      }
    }
    return maxS;
}

void findMarker(uint32_t targetS) { 
  uint32_t currS = 0;
  uint32_t diff = 0;
  bool ledStatus = true;
 while(1) {
    currS = readIntensity();
    if(currS > targetS) {
      diff = (currS - targetS);
      if(diff > 1024) {
        diff = 1024;
      }
      setMotor(false,diff / 4);
    } else if(currS < targetS)  {
       diff = (targetS - currS);
      if(diff > 1024) {
        diff = 1024;
      }
      setMotor(true,diff / 4);
    } 
    if(diff < 10) {
      return;
    }
  }
}
void loop() {
   motorsOff();  
   takeoff();
   flashLed(1000);
   uint32_t t = survey(5);
   flashLed(1000);
   findMarker(t);
   land();
}
