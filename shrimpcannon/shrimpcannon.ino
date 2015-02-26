#include <Button.h>
#include <Tlc5940.h>

#define TLC_ON 4095
#define TLC_OFF 0

Button button = Button(14, BUTTON_PULLUP_INTERNAL, true, 1000);

void setup() {
  Tlc.init();
  Tlc.clear();
  Tlc.update();
}

void loop() {
  if(button.isPressed() ) {
    fireAndWait(0, 200);
    fireAndWait(1, 200);
    fireAndWait(2, 200);
    fireAndWait(3, 200);
    fireAndWait(4, 200);
    fireAndWait(5, 200);
    fireAndWait(6, 200);
  }
  
}

void fireAndWait(int channel, int delayMs) {
    Tlc.set(channel,TLC_ON);
    Tlc.update();
    delay(delayMs);  
}
