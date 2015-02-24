#include <Button.h>
#include <Tlc5940.h>

#define TLC_ON 4095
#define TLC_OFF 0

#define SHRIMP 0
Button button = Button(14, BUTTON_PULLUP_INTERNAL, true, 1000);

void setup() {
  Tlc.init();
  Tlc.clear();
  Tlc.update();
}

void loop() {
  if(button.isPressed() ) {
    Tlc.set(SHRIMP,TLC_ON);
    Tlc.update();
    delay(300);
    Tlc.set(1,TLC_ON);
    Tlc.update();
    delay(300);
    Tlc.set(2,TLC_ON);
    Tlc.update();
  }
  
}
