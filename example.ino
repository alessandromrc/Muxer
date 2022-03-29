#include "mux.h"

Muxer mux1;
Muxer mux2;

void setup()
{
  Serial.begin(9600);
  mux1.setupDigital(2, 3, 4, 5, 6);
  mux2.setupAnalog(2, 3, 4, 5, 6);
}


void loop()
{
  Serial.println(mux1.readMux(1, 9));
  mux2.writeMux(12, 245);
  mux1.writeMux(6, true);
}
