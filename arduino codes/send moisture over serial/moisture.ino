#include <TM1637Display.h>

#define MOIS1_D 8
#define MOIS1_A A0
#define DISP1_CLK 4
#define DISP1_DIO 3
#define RLAY1 12

#define DELAY 500

TM1637Display display1(DISP1_CLK, DISP1_DIO);

int analog;
int digital;

void setup() {
  delay(1000);
  
  pinMode(MOIS1_D, INPUT);
  pinMode(RLAY1, OUTPUT);

  display1.setBrightness(1);
}

void loop() {
  delay(DELAY);

  analog = analogRead(MOIS1_A);
  digital = digitalRead(MOIS1_D); // 1 means wet, 0 means dry 
    
  display1.showNumberDec(analog, true);

  if (digital == 0) {
    digitalWrite(RLAY1, HIGH);
    delay(3000);
    digitalWrite(RLAY1, LOW);
    delay(5000);
    } else {digitalWrite(RLAY1, LOW);};
}