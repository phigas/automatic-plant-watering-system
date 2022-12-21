#include <TM1637Display.h>

#define MOIS1_D 4
#define MOIS1_A A0
#define DISP1_CLK 2
#define DISP1_DIO 3
#define RLAY1 13

#define DELAY 30000

int analog;
int digital;

TM1637Display display1(DISP1_CLK, DISP1_DIO);

void setup() {
  delay(1000);
  display1.setBrightness(1);
  Serial.begin(9600);
}

void loop() {
  delay(DELAY);

  analog = analogRead(MOIS1_A);
  digital = digitalRead(MOIS1_D); // 1 means wet, 0 means dry 
    
  display1.showNumberDec(analog, true);

  Serial.println(analog);
}
