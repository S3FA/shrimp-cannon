#include <Button.h>
#include <Tlc5940.h>

#define TLC_ON 4095
#define TLC_OFF 0
#define BUTTON_PIN 14
#define NUM_EFFECTS 5

Button button = Button(BUTTON_PIN, BUTTON_PULLUP_INTERNAL, true, 100);

// when an effect should start
int onTimeouts[NUM_EFFECTS] = {0, 60, 120, 180, 0};
// how long an effect is on for
int onLength[NUM_EFFECTS] = {60, 60, 60, 60, 200};
int offTimeouts[NUM_EFFECTS];

void setup() {
  for (int i = 0; i < NUM_EFFECTS; i++) {
    offTimeouts[i] = onTimeouts[i] + onLength[i];
  }

  Tlc.init();
  Tlc.clear();
  Tlc.update();
  
  button.pressHandler(onPress);
}

void loop() { 
  button.process();
  Tlc.clear();
  Tlc.update();
}

void onPress(Button& b){
  doRoutine(millis());
}

// actually do the routine
void doRoutine(long startTime) {
  while (true) {
    int loopTime = millis() - startTime;
    
    for (int i = 0; i < NUM_EFFECTS; i++) {
      if (loopTime > onTimeouts[i] && loopTime < offTimeouts[i]) {
        Tlc.set(i, TLC_ON);
      } else {
        Tlc.set(i, TLC_OFF);
      }
    }
    
    Tlc.update();
    
    // leave loop if past last routine step
    if (loopTime > offTimeouts[NUM_EFFECTS - 1]) {
      break;
    }
  }
}
