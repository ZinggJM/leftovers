// Umlauts : check Umlauts encoding

#include <Adafruit_GFX.h>

const char umlauts[] = "ÄÖÜäéöü";

const int base = HEX;

class CheckPrintClass : public Print
{
    size_t write(uint8_t v)
    {
      Serial.print(v, base); Serial.print(" ");
    }
} CheckPrint;

class CheckGfxClass : public Adafruit_GFX
{
  public:
    CheckGfxClass() : Adafruit_GFX(100, 100) {};
    void drawPixel(int16_t x, int16_t y, uint16_t color) {};
    size_t write(uint8_t v)
    {
      Serial.print(v, base); Serial.print(" ");
    }
} CheckGfx;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Hello Umlauts!");
  Serial.print("sizeof(umlauts) is "); Serial.println(sizeof(umlauts));
  for (int i = 0; i < sizeof(umlauts) - 1; i++)
  {
    Serial.write(umlauts[i]); Serial.print(" : ");
    Serial.print(uint16_t(umlauts[i]), base); Serial.print(" ");
    CheckPrint.print(umlauts[i]);
    CheckGfx.print(umlauts[i]);
    Serial.println();
  }
  CheckPrint.print(umlauts); Serial.println();
  CheckGfx.print(umlauts); Serial.println();
}

void loop()
{
}
