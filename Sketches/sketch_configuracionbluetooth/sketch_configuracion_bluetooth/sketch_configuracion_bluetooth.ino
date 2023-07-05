#include <SoftwareSerial.h>
SoftwareSerial miBT(10,11);


void setup() {
  Serial.begin(9600);
  Serial.println("Listo para configuración");
  miBT.begin(38400);

}

void loop() {
  if (miBT.available()){
    Serial.write(miBT.read());
  }
  if (Serial.available()){
    miBT.write(Serial.read());
  }
}
