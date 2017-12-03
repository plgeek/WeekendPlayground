#include <Adafruit_NeoPixel.h>
#ifdef NETWORK
#include <ESP8266WiFi.h>
#endif
strm.WriteLine("uint32_t c[]");const uint32_t colorCount = 240
uint32_t skyColors[colorCount] = {
 0x2F354B, 
 0x2F374C, 
 0x2E364B, 
 0x2E364B, 
 0x2F354D, 
 0x2F354D, 
 0x2F354B, 
 0x2F354B, 
 0x2E364B, 
 0x30364C, 
 0x30364E, 
 0x31364A, 
 0x31364C, 
 0x31364C, 
 0x30354B, 
 0x323449, 
 0x33354A, 
 0x32344B, 
 0x34344C, 
 0x323449, 
 0x33354A, 
 0x35364B, 
 0x36344A, 
 0x34354A, 
 0x37354A, 
 0x39364B, 
 0x3C374D, 
 0x3A374C, 
 0x3D354A, 
 0x41354B, 
 0x43364A, 
 0x473448, 
 0x51334B, 
 0x5D3349, 
 0x623345, 
 0x6C3342, 
 0x72343F, 
 0x7B353D, 
 0x853639, 
 0x923838, 
 0xA73B31, 
 0xB63E2E, 
 0xBE412D, 
 0xC64526, 
 0xD1472A, 
 0xD74C25, 
 0xE14F20, 
 0xE75323, 
 0xED5820, 
 0xF25C21, 
 0xF75F20, 
 0xFD6420, 
 0xFF6721, 
 0xFF6C23, 
 0xFF6E25, 
 0xFF7128, 
 0xFF752A, 
 0xFF802A, 
 0xFF822E, 
 0xFF862D, 
 0xFF8C34, 
 0xFF9036, 
 0xFF943A, 
 0xFF983F, 
 0xFF9D43, 
 0xFF9E4B, 
 0xFFA252, 
 0xFFA659, 
 0xFFA85E, 
 0xFFAB68, 
 0xFFAF6B, 
 0xFFB270, 
 0xFDB676, 
 0xFCB67B, 
 0xF7B882, 
 0xF6BA86, 
 0xF5BD8E, 
 0xF3C095, 
 0xEFC299, 
 0xEBC39F, 
 0xE9C4A7, 
 0xE7C8AC, 
 0xE0CAB3, 
 0xE2CBB9, 
 0xDDCDBD, 
 0xDBCFC1, 
 0xD7CEC5, 
 0xD5D0CC, 
 0xD5D1D2, 
 0xD2D1D6, 
 0xCDD4DA, 
 0xCAD4DD, 
 0xC8D4E4, 
 0xC5D5E4, 
 0xC5D1E9, 
 0xBED4EC, 
 0xBBD2F1, 
 0xB9D1F3, 
 0xB4D2F4, 
 0xB0D2F8, 
 0xB1D0FE, 
 0xADCFFC, 
 0xAACEFF, 
 0xA9CCFF, 
 0xA3CCFF, 
 0xA3CBFF, 
 0x9FCCFF, 
 0x9ECBFF, 
 0x9BC9FF, 
 0x97C8FF, 
 0x96C7FF, 
 0x92C7FF, 
 0x8FC5FF, 
 0x8FC3FF, 
 0x8CC4FF, 
 0x8AC2FF, 
 0x8AC3FF, 
 0x88BFFF, 
 0x89BFFF, 
 0x85BFFF, 
 0x85BCFF, 
 0x83BCFF, 
 0x85BAFF, 
 0x7FBAFF, 
 0x7DB9FF, 
 0x7FB6FF, 
 0x7CB5FF, 
 0x77B5FF, 
 0x75B6FF, 
 0x75B3FF, 
 0x74B2FF, 
 0x73B4FF, 
 0x72B1FF, 
 0x6EB1FF, 
 0x6EAEFF, 
 0x6EAEFF, 
 0x6DADFF, 
 0x6AACFF, 
 0x69ABFF, 
 0x6AAAFF, 
 0x6AAAFF, 
 0x68A7FF, 
 0x68A7FF, 
 0x64A6FF, 
 0x64A5FF, 
 0x65A3FF, 
 0x62A3FF, 
 0x63A1FF, 
 0x62A0FF, 
 0x619FFF, 
 0x609EFF, 
 0x609EFF, 
 0x5D9DFF, 
 0x5F9DFF, 
 0x5E9CFF, 
 0x5D9BFF, 
 0x5A9AFF, 
 0x5B99FF, 
 0x5A97FF, 
 0x5A97FF, 
 0x5895FF, 
 0x5895FF, 
 0x5794FF, 
 0x5693FF, 
 0x5294FF, 
 0x5593FF, 
 0x5292FF, 
 0x538EFF, 
 0x538EFF, 
 0x538EFF, 
 0x518CFF, 
 0x508BFF, 
 0x4F8BFF, 
 0x4F8AFF, 
 0x4B8AFF, 
 0x4E89FF, 
 0x4C89FF, 
 0x4989FF, 
 0x4A87FF, 
 0x4A87FF, 
 0x4986FF, 
 0x4885FF, 
 0x4785FF, 
 0x4884FF, 
 0x4783FF, 
 0x4682FE, 
 0x4682FE, 
 0x4482FB, 
 0x4480FA, 
 0x477FFA, 
 0x447EFB, 
 0x437FFB, 
 0x447EF9, 
 0x427CF7, 
 0x427CF7, 
 0x417BF6, 
 0x427AF3, 
 0x427AF3, 
 0x3F7AF2, 
 0x3E79EF, 
 0x3E79EF, 
 0x437EF4, 
 0x4883F9, 
 0x4D88FE, 
 0x528DFF, 
 0x5792FF, 
 0x5C97FF, 
 0x619CFF, 
 0x66A1FF, 
 0x6BA6FF, 
 0x70ABFF, 
 0x75B0FF, 
 0x7AB5FF, 
 0x7FBAFF, 
 0x84BFFF, 
 0x89C4FF, 
 0x8EC9FF, 
 0x93CEFF, 
 0x98D3FF, 
 0x9DD8FF, 
 0xA2DDFF, 
 0xA7E2FF, 
 0xACE7FF, 
 0xB1ECFF, 
 0xB6F1FF, 
 0xBBF6FF, 
 0xC0FBFF, 
 0xC5FFFF, 
 0xCAFFFF, 
 0xCFFFFF, 
 0xD4FFFF, 
 0xD9FFFF, 
 0xDEFFFF, 
 0xE3FFFF, 
 0xE8FFFF, 
 0xEDFFFF, 
 0xF2FFFF, 
 0xF7FFFF, 
 0xFCFFFF, 
 0xFFFFFF, 
};

// display config
const uint32_t cAudioPin    = 4; // marked D2 on nodemcu 
const uint32_t cPixelsPin   = 5; // marekd D1 on nodemcu 
const uint32_t cPixelsCount = 1;
Adafruit_NeoPixel pixels = 
  Adafruit_NeoPixel(cPixelsCount, cPixelsPin, NEO_RGB + NEO_KHZ800);

// network info
struct NetworkInfo {
  const char* ssid;
  const char* password;
};

const uint32_t cMaxConnectAttempts = 10;
const uint32_t cNetworksCount = 1;
const NetworkInfo Networks[cNetworksCount] = 
{
  { "plgeek", "FFDEADBEEF"}
};

const uint32_t cFastPollIntervalInSeconds = 5;
const uint32_t cSlowPollIntervalInSeconds = 60;
const char* host = "livesiteassist.blob.core.windows.net";
const char* path = "/livelight/status.txt?sv=2014-02-14&ss=2015-07-15T16%3A06%3A13Z&se=2016-07-22T07%3A00%3A00Z&sp=r&sr=b&sig=J%2Fg28Iyk%2BdFTOgWIyoe%2BAv6WNGE6iSODPAV8LAqdQ2A%3D";
const uint32_t hostPort = 80;

// simple 8 color pallet
const uint32_t cColorsCount = 8;   
const uint32_t cPrimaryColorsCount = 6;         
const uint8_t cL = 32;
const uint8_t cM = 255;
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
#ifdef NETWORK
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
#endif
void SkyPattern() {
   const int d = 250;
   pixels.setBrightness(255);
 // night to sunrise
 for(int i = 0; i < 32; i++) {
  uint8_t r = 16;
  uint8_t b = 64; 
  uint8_t g = 16;
  uint32_t c = pixels.Color(r,g,b);
  pixels.setPixelColor(0, c);
  pixels.show();
  delay(d);
 }
 // sunrise to day
 for(int i = 32; i < 64 ; i++) {
  uint8_t damp = 32 - i;
  uint8_t r = 64;
  uint8_t b = 16;
  uint8_t g = 64;
  uint32_t c = pixels.Color(r,g,b);
  pixels.setPixelColor(0, c);
  pixels.show();
  delay(d);
 }
 // day to noon
 for(int i = 128; i < 255; i++) {
  uint8_t r = i;
  uint8_t b = i;
  uint8_t g = i;
  uint32_t c = pixels.Color(r,g,b);
  pixels.setPixelColor(0, c);
  pixels.show();
  delay(d);
 }


}

void setup() {
  Serial.begin(115200);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  SkyPattern();
}
