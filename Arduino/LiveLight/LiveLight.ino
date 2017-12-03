#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
// display config
const uint32_t cAudioPin    = 4; // marked D2 on nodemcu 
const uint32_t cPixelsPin   = 5; // marekd D1 on nodemcu 
const uint32_t cPixelsCount = 7;
Adafruit_NeoPixel pixels = 
  Adafruit_NeoPixel(cPixelsCount, cPixelsPin, NEO_GRB + NEO_KHZ800);

// network info
struct NetworkInfo {
  const char* ssid;
  const char* password;
};

const uint32_t cMaxConnectAttempts = 10;
const uint32_t cNetworksCount = 1;
const NetworkInfo Networks[cNetworksCount] = 
{
  { "plgeek", "<removed>"}
};

const uint32_t cFastPollIntervalInSeconds = 5;
const uint32_t cSlowPollIntervalInSeconds = 60;
const char* host = "<hostanme>";
const char* path = "<url>";
const uint32_t hostPort = 80;

// simple 8 color pallet
const uint32_t cColorsCount = 8;   
const uint32_t cPrimaryColorsCount = 6;         
const uint8_t cL = 32;
const uint8_t cM = 128;
const uint8_t cH = 255;
const uint32_t cBlack      = pixels.Color(  0,  0,  0);
const uint32_t cBlue       = pixels.Color(  0,  0, cM);
const uint32_t cGreen      = pixels.Color(  0, cM,  0);
const uint32_t cRed        = pixels.Color( cM,  0,  0); 
const uint32_t cMagenta    = pixels.Color( cM,  0, cM); 
const uint32_t cOrange     = pixels.Color( cM, cL,  0);
const uint32_t cYellow     = pixels.Color(cH, cH, cL);
const uint32_t cWhite      = pixels.Color(cH, cH, cH);
const uint32_t MaxOps      = 64;

const uint32_t cColors[cColorsCount] = {
cBlack, cRed, cOrange, cYellow, cGreen, cBlue, cMagenta, cWhite
};

const uint32_t cPrimaryColors[6] = {
 cRed, cOrange, cYellow, cGreen, cBlue, cMagenta
};

void SetAllToColor(uint32_t c)
{
    for(int i = 0; i < cPixelsCount; i++)
    {
      pixels.setPixelColor(i, c);
    }
    pixels.show();
}

void BlinkAll(uint32_t c1,uint32_t c2, uint32_t ms)
{
    uint32_t wait = ms / 2;
    SetAllToColor(c1);
    delay(wait);
    SetAllToColor(c2);
    delay(wait);
}
// test pattern
void RotatePrimaryColors(int n,int delayMs)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < cPixelsCount; j++)
    {
      pixels.setPixelColor(j % cPixelsCount, cPrimaryColors[(i+j) % 6]);
    }
    pixels.show();
    delay(delayMs);
  }
}

// set up pixles and do a 5 second test pattern.
// 5 second test pattern
void TestPattern()
{
  // 3 seconds
  for(int i = 0; i < 6; i++)
  {
    SetAllToColor(cPrimaryColors[i]);
    delay(500);
  }
  // one second
  SetAllToColor(cBlack);
}


#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
void SimpleTone(uint32_t hz, uint32_t durationMs, uint32_t waitMs)
{
  uint32_t usec = 200000/hz;
  uint32_t endTicks = millis() + durationMs;
  while(millis() < endTicks)
  {
    digitalWrite(cAudioPin, HIGH);
    delayMicroseconds(usec);
    digitalWrite(cAudioPin, LOW);
    delayMicroseconds(usec);
  }
  delay(waitMs);
}


void PlayUpScale(void)
{
  uint32_t ms = 250;
  uint32_t d = 10;
  SimpleTone(NOTE_A3,ms,d);
  SimpleTone(NOTE_AS3,ms,d);
  SimpleTone(NOTE_B3,ms,d);
  SimpleTone(NOTE_C4,ms,d);
  SimpleTone(NOTE_CS4,ms,d);
  SimpleTone(NOTE_D4,ms,d);
  SimpleTone(NOTE_DS4,ms,d);
  SimpleTone(NOTE_E4,ms,d);
  SimpleTone(NOTE_F4,ms,d); 
  SimpleTone(NOTE_FS4,ms,d); 
  SimpleTone(NOTE_G4,ms,d); 
}

void PlayDownScale(void)
{
  uint32_t ms = 250;
  uint32_t d = 10;
  SimpleTone(NOTE_G4,ms,d); 
  SimpleTone(NOTE_FS4,ms,d); 
  SimpleTone(NOTE_F4,ms,d); 
  SimpleTone(NOTE_E4,ms,d);
  SimpleTone(NOTE_DS4,ms,d);
  SimpleTone(NOTE_D4,ms,d);
  SimpleTone(NOTE_CS4,ms,d);
  SimpleTone(NOTE_C4,ms,d);
  SimpleTone(NOTE_B3,ms,d);
  SimpleTone(NOTE_AS3,ms,d);
  SimpleTone(NOTE_A3,ms,d);
}

void SignalError(int code)
{
  for(int i = 0; i < 5; i++)
  {
    RotatePrimaryColors(10,100);
    for(int j = 0; j < 10; j++)
    {
     pixels.clear();
     pixels.show();
     delay(100);
     for(int k = 0; k <= code; k++)
     {
       pixels.setPixelColor(k, cRed);
     }
     pixels.show();
     delay(100);
    }
  }
}

int ConnectToNetworks()
{
  for(int i = 0; i < cMaxConnectAttempts; i++)
  {  
    for(int j = 0; j < cNetworksCount; j++)
    {
        if(TryConnect(Networks[j], 2000) == WL_CONNECTED)
        {
          return 1;  
        }
    }
  }
  return 0;
}

int TryConnect(const struct NetworkInfo& info, int32 timeoutMs)
{
  WiFi.mode(WIFI_STA);
  if(info.password == NULL)
  {
    WiFi.begin(info.ssid);
  } else {
    WiFi.begin(info.ssid,info.password);
  }
  
   Serial.print("Connecting to ");
   Serial.println(info.ssid);
   uint32_t endTicks = millis() + 1000 * 15;
   // retry up to 30 seconds.
   while (WiFi.status() != WL_CONNECTED && millis() < endTicks) {
    Serial.print(".");
    RotatePrimaryColors(20,100);
  }
  Serial.println();
  
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("With MAC: ");;
    uint8_t mac[WL_MAC_ADDR_LENGTH];
    WiFi.macAddress(mac);
    for(int i = 0; i < WL_MAC_ADDR_LENGTH; i++)
    {
      if(mac[i] < 16)
      {
        // print leading zeros
        Serial.print("0");
      }
      Serial.print(mac[i], HEX);
    }
    Serial.println("");
  }
  return WiFi.status();
}

void EnsureConnected()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    return;
  }
  TestPattern();
  if(ConnectToNetworks())
  {
    PlayUpScale();
    SetAllToColor(cBlue);
  } else {
    PlayDownScale();
    SignalError(0);
  }
}

 enum Op {
  OpSetC,
  OpWait,
  OpDone,
  OpLoop
};
#define CHECKPC(pc) if(pc >= MaxOps) { return false; }
int TryGetCommands(uint32_t ops[])
{
  for(int i = 0; i < MaxOps;i++)
  {
    ops[i] = OpDone;
  }

  WiFiClient client;

  Serial.println("Attempting to connect to host");
  if(!client.connect(host, hostPort))
  {
    Serial.println("Connection to host failed.");
    SignalError(2);
    return false;
  }
  String request = String("GET ") + path + " HTTP/1.1\r\n" +
                   "Host: " + host + "\r\n" + 
                    "Connection: close\r\n\r\n";
  Serial.println("Connected sending http request.");
  client.print(request);
  // read output.
  int body = false;
  int pc = 0;
  int lineNum = 0;
  int maxWait = 300;
  // spin-wait waiting for reponse for at most 30 seconds
  while(!client.available())
  {
    if(maxWait-- < 0)
    {
      return 0;
    }
    Serial.print(".");
    delay(100);
  }
  Serial.println("Reading reponse.");
  // assume everything is \r\n
  while(client.available()){
    String line = client.readStringUntil('\r');
    // throw away \n
    client.read();
    if(!body && line.length() == 0)
    {
      body = true;
      continue;
    } 
    if(!body)
    {
      Serial.print("> ");
      Serial.println(line);
      continue;
    } 
    lineNum++;
    Serial.println(line);
    if(line.startsWith("#"))
    {
        // comment
        // nop
        continue;
    }
    if(line.startsWith("setc "))
    {
        line.remove(0,5);
        ops[pc++] = OpSetC;
        CHECKPC(pc);
        ops[pc++] = line.toInt();
        CHECKPC(pc);
        continue;
    }
    if(line.startsWith("wait "))
    {
        line.remove(0,5);
        ops[pc++] = OpWait;
        CHECKPC(pc);
        ops[pc++] = line.toInt();
        CHECKPC(pc);
        continue;
    }
    if(line.startsWith("loop "))
    {
        line.remove(0,5);
        ops[pc++] = OpLoop;
        CHECKPC(pc);
        ops[pc++] = line.toInt();
        CHECKPC(pc);
        continue;
    }
    if(line.startsWith("done"))
    {
      ops[pc++] = OpDone;
      CHECKPC(pc);
      continue;
    }
    Serial.print("Syntax Error Line:");
    Serial.println(lineNum);
  }
  return 1;
}

void RunCommands(uint32_t ops[])
{
  int pc = 0;
  int i = 0;
  uint32_t v = 0;
  uint64_t endTicks = 0;
  for(;;)
  {
    switch(ops[pc])
    {
      case OpSetC:
       v = ops[pc+1];
       pc+=2;
       SetAllToColor(cColors[v % cColorsCount]);
       break;
      case OpWait:
       v = ops[pc+1];
       pc+=2;
       delay(v * 1000);
       break;
      case OpLoop:
       if(endTicks == 0)
       {
         v = ops[pc+1];
         endTicks = millis() + v * 1000;
       } 
       else if(millis() > endTicks)
       {
         return;
       }
       pc = 0;
       break;
      case OpDone:
       return;
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(cAudioPin,OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  uint32_t ops[64];
  EnsureConnected();
  if(!TryGetCommands(ops))
  {
    SignalError(3);
    delay(cFastPollIntervalInSeconds * 1000);
    return;
  }
  uint64_t minWait = millis() + (1000 * 10);
  RunCommands(ops);
  while(millis() < minWait)
  {
    delay(1000);
  }
}
