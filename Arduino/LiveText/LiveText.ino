#include <Adafruit_NeoPixel.h>
const uint32_t cPixelsPin   = 5; // mareked D1 on nodemcu 
const uint32_t cPixelsCount = 64;
Adafruit_NeoPixel pixels = 
  Adafruit_NeoPixel(cPixelsCount, cPixelsPin, NEO_GRB + NEO_KHZ800);

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

const uint32_t cPink       = pixels.Color(cM, cL, cL);

const uint32_t cColors[cColorsCount] = {
cBlack, cRed, cOrange, cYellow, cGreen, cBlue, cMagenta, cWhite
};

const uint32_t cPrimaryColors[6] = {
 cRed, cOrange, cYellow, cGreen, cBlue, cMagenta
};

const uint32_t cDWd = 16;
const uint32_t cDHt = 4;
const uint8_t  cDL2P[cDWd][cDHt] = 
{
 // 16x4
 { 0x00, 0x07, 0x08, 0x0F},
 { 0x01, 0x06, 0x09, 0x0E},
 { 0x02, 0x05, 0x0A, 0x0D},
 { 0x03, 0x04, 0x0B, 0x0C},
 { 0x10, 0x17, 0x18, 0x1F},
 { 0x11, 0x16, 0x19, 0x1E},
 { 0x12, 0x15, 0x1A, 0x1D},
 { 0x13, 0x14, 0x1B, 0x1C},
 { 0x20, 0x27, 0x28, 0x2F},
 { 0x21, 0x26, 0x29, 0x2E},
 { 0x22, 0x25, 0x2A, 0x2D},
 { 0x23, 0x24, 0x2B, 0x2C},
 { 0x30, 0x37, 0x38, 0x3F},
 { 0x31, 0x36, 0x39, 0x3E},
 { 0x32, 0x35, 0x3A, 0x3D},
 { 0x33, 0x34, 0x3B, 0x3C},
};

uint32_t cFont[256];
#define SL0(b0,b1,b2,b3,b4,b5) (b0 | b1<<1 | b2 <<2 | b3<<3 | b4<<4 | b5<<5) 
#define SL1(b0,b1,b2,b3,b4,b5) SL0(b0,b1,b2,b3,b4,b5)<<6 
#define SL2(b0,b1,b2,b3,b4,b5) SL0(b0,b1,b2,b3,b4,b5)<<12 
#define SL3(b0,b1,b2,b3,b4,b5) SL0(b0,b1,b2,b3,b4,b5)<<18
#define WD(sz) sz <<24
void InitFont()
{
  cFont[' '] = WD(2)
             | SL0(0,0,0,0,0,0)
             | SL1(0,0,0,0,0,0)
             | SL2(0,0,0,0,0,0)
             | SL3(0,0,0,0,0,0);
             
  cFont['1'] = WD(4)
             | SL0(1,1,0,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['2'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(0,0,1,0,0,0)
             | SL2(1,1,0,0,0,0)
             | SL3(1,1,1,0,0,0);
             
  cFont['3'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(0,1,1,0,0,0)
             | SL2(0,0,1,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['4'] = WD(4)
             | SL0(1,0,1,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,1,1,0,0,0)
             | SL3(0,0,1,0,0,0);

  cFont['5'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(1,1,0,0,0,0)
             | SL2(0,0,1,0,0,0)
             | SL3(1,1,1,0,0,0);
  
  cFont['6'] = WD(4)
             | SL0(1,0,0,0,0,0)
             | SL1(1,1,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['7'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(0,0,1,0,0,0)
             | SL2(0,0,1,0,0,0)
             | SL3(0,0,1,0,0,0);

  cFont['8'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(1,1,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['9'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,1,1,0,0,0)
             | SL3(0,0,1,0,0,0);
  
  cFont['0'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(1,1,1,0,0,0);
             
  cFont['A'] = WD(4)
             | SL0(0,1,0,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,1,1,0,0,0)
             | SL3(1,0,1,0,0,0);
    
  cFont['B'] = WD(5)
             | SL0(1,1,1,1,0,0)
             | SL1(1,1,1,0,0,0)
             | SL2(1,0,0,1,0,0)
             | SL3(1,1,1,0,0,0);
    
  cFont['C'] = WD(4)
             | SL0(0,1,1,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(0,1,1,0,0,0);
  
  cFont['D'] = WD(4)
             | SL0(1,1,0,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(1,1,0,0,0,0);
  
  cFont['E'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(1,1,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['F'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(1,1,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(1,0,0,0,0,0);

  cFont['G'] = WD(4)
             | SL0(0,1,1,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(1,1,1,0,0,0)
             | SL3(0,1,1,0,0,0);
             
  cFont['H'] = WD(4)
             | SL0(1,0,1,0,0,0)
             | SL1(1,1,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(1,0,1,0,0,0);
             
  cFont['I'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['J'] = WD(4)
             | SL0(0,0,1,0,0,0)
             | SL1(0,0,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(0,1,0,0,0,0);

  cFont['K'] = WD(4)
             | SL0(1,0,1,0,0,0)
             | SL1(1,1,0,0,0,0)
             | SL2(1,1,0,0,0,0)
             | SL3(1,0,1,0,0,0);
             
  cFont['L'] = WD(4)
             | SL0(1,0,0,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['M'] = WD(6)
             | SL0(1,0,0,0,1,0)
             | SL1(1,1,0,1,1,0)
             | SL2(1,0,1,0,1,0)
             | SL3(1,0,0,0,1,0);

  cFont['N'] = WD(5)
             | SL0(1,0,0,1,0,0)
             | SL1(1,1,0,1,0,0)
             | SL2(1,0,1,1,0,0)
             | SL3(1,0,0,1,0,0);

  cFont['O'] = WD(5)
             | SL0(0,1,1,0,0,0)
             | SL1(1,0,0,1,0,0)
             | SL2(1,0,0,1,0,0)
             | SL3(0,1,1,0,0,0);
  
  cFont['P'] = WD(5)
             | SL0(1,1,0,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,1,0,0,0,0)
             | SL3(1,0,0,0,0,0);
                       
  cFont['Q'] = WD(5)
             | SL0(0,1,1,0,0,0)
             | SL1(1,0,0,1,0,0)
             | SL2(1,0,1,1,0,0)
             | SL3(0,1,1,1,0,0);
             
  cFont['R'] = WD(4)
             | SL0(1,1,0,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,1,0,0,0,0)
             | SL3(1,0,1,0,0,0);

  cFont['S'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(0,1,1,0,0,0)
             | SL3(1,1,1,0,0,0);
             
  cFont['T'] = WD(4)
             | SL0(1,1,1,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(0,1,0,0,0,0);

  cFont['U'] = WD(4)
             | SL0(1,0,1,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['V'] = WD(4)
             | SL0(1,0,1,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(1,0,1,0,0,0)
             | SL3(0,1,0,0,0,0);
             
  cFont['W'] = WD(6)
             | SL0(1,0,0,0,1,0)
             | SL1(1,0,1,0,1,0)
             | SL2(1,1,0,1,1,0)
             | SL3(1,0,0,0,1,0);

  cFont['X'] = WD(4)
             | SL0(1,0,1,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,0,1,0,0,0);

  cFont['Y'] = WD(4)
             | SL0(1,0,1,0,0,0)
             | SL1(1,0,1,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(0,1,0,0,0,0);

  cFont['Z'] = WD(5)
             | SL0(1,1,1,1,0,0)
             | SL1(0,0,1,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,1,1,1,0,0);

  cFont['!'] = WD(2)
             | SL0(1,0,0,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(0,0,0,0,0,0)
             | SL3(1,0,0,0,0,0);

  cFont['.'] = WD(3)
             | SL0(0,0,0,0,0,0)
             | SL1(0,0,0,0,0,0)
             | SL2(1,1,0,0,0,0)
             | SL3(1,1,0,0,0,0);
             
  cFont[','] = WD(3)
             | SL0(0,0,0,0,0,0)
             | SL1(0,0,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,0,0,0,0,0);

  cFont[':'] = WD(3)
             | SL0(1,1,0,0,0,0)
             | SL1(0,0,0,0,0,0)
             | SL2(0,0,0,0,0,0)
             | SL3(1,1,0,0,0,0);
  
  cFont[';'] = WD(3)
             | SL0(1,1,0,0,0,0)
             | SL1(0,0,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,0,0,0,0,0);

  cFont['?'] = WD(5)
             | SL0(0,1,1,0,0,0)
             | SL1(1,0,0,1,0,0)
             | SL2(0,0,1,0,0,0)
             | SL3(1,1,0,0,0,0);

  cFont['{'] = WD(4)
             | SL0(0,0,1,0,0,0)
             | SL1(1,1,0,0,0,0)
             | SL2(1,1,0,0,0,0)
             | SL3(0,0,1,0,0,0);    
 
  cFont['}'] = WD(4)
             | SL0(1,0,0,0,0,0)
             | SL1(0,1,1,0,0,0)
             | SL2(0,1,1,0,0,0)
             | SL3(1,0,0,0,0,0); 
                           
  cFont['('] = WD(3)
             | SL0(0,1,0,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(0,1,0,0,0,0); 
  
  cFont[')'] = WD(3)
             | SL0(1,0,0,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,0,0,0,0,0);  

  cFont['['] = WD(3)
             | SL0(1,1,0,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(1,1,0,0,0,0); 
  
  cFont[']'] = WD(3)
             | SL0(1,1,0,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,1,0,0,0,0); 

  cFont['<'] = WD(4)
             | SL0(0,0,1,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(1,1,1,0,0,0); 
 
  cFont['>'] = WD(4)
             | SL0(1,0,0,0,0,0)
             | SL1(0,1,0,0,0,0)
             | SL2(0,0,1,0,0,0)
             | SL3(1,1,1,0,0,0);

  cFont['|'] = WD(2)
             | SL0(1,0,0,0,0,0)
             | SL1(1,0,0,0,0,0)
             | SL2(1,0,0,0,0,0)
             | SL3(1,0,0,0,0,0);

  cFont['/'] = WD(4)
             | SL0(0,0,0,1,0,0)
             | SL1(0,0,1,0,0,0)
             | SL2(0,1,0,0,0,0)
             | SL3(1,0,0,0,0,0);
             
  cFont['\\'] = WD(4)
              | SL0(1,0,0,0,0,0)
              | SL1(0,1,0,0,0,0)
              | SL2(0,0,1,0,0,0)
              | SL3(0,0,0,1,0,0);

  cFont['-']  =  WD(4)
              | SL0(0,0,0,0,0,0)
              | SL1(0,0,0,0,0,0)
              | SL2(1,1,1,0,0,0)
              | SL3(0,0,0,0,0,0);

 cFont['+']   =  WD(4)
              | SL0(0,0,0,0,0,0)
              | SL1(0,1,0,0,0,0)
              | SL2(1,1,1,0,0,0)
              | SL3(0,1,0,0,0,0);
              
 cFont['=']   = WD(4)
              | SL0(0,0,0,0,0,0)
              | SL1(1,1,1,0,0,0)
              | SL2(0,0,0,0,0,0)
              | SL3(1,1,1,0,0,0); 

 cFont['_']   = WD(4)
              | SL0(0,0,0,0,0,0)
              | SL1(0,0,0,0,0,0)
              | SL2(0,0,0,0,0,0)
              | SL3(1,1,1,1,0,0);
 
 cFont['^']   = WD(4)
              | SL0(0,1,0,0,0,0)
              | SL1(1,0,1,0,0,0)
              | SL2(0,0,0,0,0,0)
              | SL3(0,0,0,0,0,0);

 cFont['\'']  = WD(2)
              | SL0(1,0,0,0,0,0)
              | SL1(1,0,0,0,0,0)
              | SL2(0,0,0,0,0,0)
              | SL3(0,0,0,0,0,0);

cFont['\"']   = WD(4)
              | SL0(1,0,1,0,0,0)
              | SL1(1,0,1,0,0,0)
              | SL2(0,0,0,0,0,0)
              | SL3(0,0,0,0,0,0);


 cFont['@']   = WD(4)
              | SL0(0,1,1,0,0,0)
              | SL1(1,1,1,0,0,0)
              | SL2(1,0,0,0,0,0)
              | SL3(0,1,1,0,0,0);

cFont['#']   = WD(5)
              | SL0(0,1,1,0,0,0)
              | SL1(1,1,1,1,0,0)
              | SL2(1,1,1,1,0,0)
              | SL3(0,1,1,0,0,0);

 cFont['$'] = WD(4)
             | SL0(0,1,1,0,0,0)
             | SL1(1,1,0,0,0,0)
             | SL2(1,1,1,0,0,0)
             | SL3(0,1,0,0,0,0);
             
 cFont['%']   = WD(5)
              | SL0(1,0,0,1,0,0)
              | SL1(0,0,1,0,0,0)
              | SL2(0,1,0,0,0,0)
              | SL3(1,0,0,1,0,0);
              
cFont['*']   = WD(4)
              | SL0(1,0,1,0,0,0)
              | SL1(0,1,0,0,0,0)
              | SL2(1,0,1,0,0,0)
              | SL3(0,0,0,0,0,0); 

cFont['&']   = WD(5)
              | SL0(0,1,1,0,0,0)
              | SL1(1,1,1,0,0,0)
              | SL2(1,0,1,1,0,0)
              | SL3(0,1,0,1,0,0);     
                       
cFont['`']   = WD(3)
              | SL0(0,1,0,0,0,0)
              | SL1(1,0,0,0,0,0)
              | SL2(0,0,0,0,0,0)
              | SL3(0,1,0,0,0,0); 

cFont['~']   = WD(5)
              | SL0(1,1,1,0,0,0)
              | SL1(0,1,1,1,0,0)
              | SL2(0,0,0,0,0,0)
              | SL3(0,1,0,0,0,0); 

cFont['l']   = WD(5)
              | SL0(1,1,0,0,0,0)
              | SL1(0,0,1,0,0,0)
              | SL2(0,0,1,1,0,0)
              | SL3(0,1,0,0,1,0); 

 cFont['x']   = WD(4)
              | SL0(0,0,0,0,0,0)
              | SL1(1,0,1,0,0,0)
              | SL2(0,1,0,0,0,0)
              | SL3(1,0,1,0,0,0); 

}

void ShiftRight()
{
  for(int j = 0; j < cDHt; j++)
  {
    for(int i = 1 ; i < cDWd; i++)
    {
      uint32_t p0 = cDL2P[i-1][j];
      uint32_t p1 = cDL2P[i][j];
      uint32_t c = pixels.getPixelColor(p1);
      pixels.setPixelColor(p0,c);
    }
  }
}

void ShiftCharCol(uint32_t fg, uint32_t bg, uint32_t charInfo, uint8_t col)
{
  uint32_t mask = 1 << col;
  for(int j = 0; j < cDHt; j++)
  {
    uint32_t c = (charInfo & mask) ? fg : bg;
    pixels.setPixelColor(cDL2P[cDWd-1][j],c);
    mask = mask << 6;
  }
}

void ShowChar(uint32_t fg, uint32_t bg, const char c, uint32_t delayMs)
{
      uint32_t charInfo = cFont[c];
      uint32_t charCols = charInfo>>24;
      for(int col = 0; col < charCols ; col++)
      {
        ShiftRight();
        ShiftCharCol(fg, bg, charInfo, col);
        pixels.show();
        delay(delayMs);
      }  
}

void ShowMessage(uint32_t fg, uint32_t bg, const char *msg, uint32_t delayMs)
{
  for(const char *ptr = msg; *ptr != '\0'; ptr++)
  {
    ShowChar(fg, bg, *ptr, delayMs);
  }
}

void ShowMessageRainbow(uint32_t bg, const char *msg, uint32_t delayMs)
{
  uint32_t c = 0;
  for(const char *ptr = msg; *ptr != '\0'; ptr++)
  {
    uint32_t fg = cPrimaryColors[c++ % cPrimaryColorsCount];    
    ShowChar(fg, bg, *ptr, delayMs);
  }
}

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


void SlowFill(uint32_t fg, uint32_t bg)
{
   SetAllToColor(bg);
    for(int j = 0; j < cDHt ; j++) {
      for(int i = 0; i < cDWd ; i++) {
        pixels.setPixelColor(cDL2P[i][j],fg);
        delay(500);
        pixels.show();
      }
    }
}

void Demo()
{
  SetAllToColor(cBlack);
  ShowMessage(cRed, cBlack,"HELLO WORLD!",200);
  ShowMessage(cRed, cBlack,"HELLO WORLD!",100);
  ShowMessage(cRed, cBlack,"HELLO WORLD!",50);
  SetAllToColor(cBlack);
  ShowMessage(cRed, cBlack,"THIS IS MY LATEST PROJECT A 16X4 NEOPIXEL DISPLAY DRIVEN BY AN ESP8266",100);
  ShowMessage(cRed, cBlack,"HERE IS THE FULL SET OF GLYPHS IT CAN DISPLAY:",100);
  ShowMessage(cRed, cBlack, "1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ !?:;,.(){}[]|/\\+=-_^\'\"<>*",100);
  ShowMessageRainbow(cBlack, "ALSO IN COLOR:",200);
  ShowMessageRainbow(cBlack, "1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ !?:;,.(){}[]|/\\+=-_",100);
  ShowMessage(cMagenta, cBlack, "STAY TUNED FOR MORE!",100);
}

void setup() {
  Serial.begin(115200);
  InitFont();  
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  int cSpeed = 150;
  SetAllToColor(cBlack);
  ShowMessage(cRed, cBlack,"HELLO WORLD!",200);
  ShowMessage(cRed, cBlack,"HELLO WORLD!",100);
  ShowMessage(cRed, cBlack,"HELLO WORLD!",50);
  ShowMessage(cRed, cBlack,"THIS IS MY LATEST PROJECT A 16X4 NEOPIXEL DISPLAY DRIVEN BY AN ESP8266",cSpeed);
  ShowMessage(cGreen, cBlack, "GLYPHS ARE VARIABLE WIDTH! SO 'M', 'N', AND 'W' AND OTHERS LOOK NICER!",cSpeed);
  ShowMessage(cBlue, cBlack, "ALL KEYBOARD SYMBOLS ARE ENCODED!",cSpeed);
  ShowMessage(cMagenta, cBlack,"HERE ARE ALL THE GLYPHS:",cSpeed);
  ShowMessageRainbow(cBlack, "1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ !@#$%^&*()-=_+[]\\{}|;':\",./<>?",cSpeed);
  ShowMessage(cRed, cBlack, "A FEW MORE EXAMPLES",cSpeed);
  ShowMessage(cGreen, cBlack, "HTTP://WWW.EXAMPLE.COM NOBODY@NOWHERE.COM",cSpeed);
}
