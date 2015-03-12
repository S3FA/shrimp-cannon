#include <Button.h>
#include <Tlc5940.h>

#define TLC_ON 4095
#define TLC_OFF 0
#define GAP_TIME 60

Button button = Button(14, BUTTON_PULLUP_INTERNAL, true, 1000);
boolean fired;

void setup() {
  Tlc.init();
  Tlc.clear();
  Tlc.update();
  fired = false;
}

void loop() {
  if(button.isPressed() && !fired) {
    fired = true;
    for(int i = 0; i < 5; i++) {
      fireAndWait(i, GAP_TIME);  
    }
  }

  if(fired) {
    fireOFF(500);
    if(!button.isPressed()) {
      fired = false;
    } 
  }
}

void fireAndWait(int channel, int delayMs) {
  Tlc.set(channel,TLC_ON);
  Tlc.update();
  delay(delayMs);  
}

void fireOFF(int delayMs) {
  delay(delayMs);
  Tlc.clear();
  Tlc.update();
}
