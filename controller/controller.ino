#include "Mouse.h"
#include "Keyboard.h"
#include <MouseTo.h>
const byte toggle = 2; 
const byte select = 3;
const byte val3 = 4;
const byte val2 = 5;
const byte val1 = 6;
int currentFilter;

void setup() {
//assign pins
  pinMode(toggle, INPUT_PULLUP);
  pinMode(select, INPUT_PULLUP);
  pinMode(val1, INPUT_PULLUP);
  pinMode(val2, INPUT_PULLUP);
  pinMode(val3, INPUT_PULLUP);
   while (!Serial) {
    ;  // wait for serial port to connect. Needed for Leonardo only
  }
begin();
}

void begin() {
  Keyboard.begin();
  Mouse.begin();
//Open OBS

//Select Scene
  MouseTo.setTarget(50, 545);
  while (MouseTo.move() == false) {}
  delay(100);
    //Navigate to filters
      delay(100);
      Mouse.click(MOUSE_RIGHT);
      delay(100);
      Mouse.move(50,-73); 
      delay(500);
      Mouse.click();
      delay(500);
     
//Configure to val1
    Keyboard.press(KEY_DOWN_ARROW);
    delay(200);   
    Keyboard.releaseAll();
    Keyboard.press(KEY_DOWN_ARROW);
    delay(200);   
    Keyboard.releaseAll();
    currentFilter = 3;
}

void buttoncheck() {
//switch scenes
  if (digitalRead(3) == LOW) { 
    if (currentFilter == 5) { //go to top of filter list
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      currentFilter = 3;
    }
    else { 
      Keyboard.press(KEY_DOWN_ARROW);
      delay(200); 
      Keyboard.releaseAll();
      currentFilter++;
    }
  delay(500);
  }
  if (digitalRead(2) == LOW) {
//hide scenes
  if (currentFilter == 3) Keyboard.press('3');
  if (currentFilter == 4) Keyboard.press('4');
  if (currentFilter == 5) Keyboard.press('5');
  delay(200);
  Keyboard.releaseAll();
  }
//
  if (digitalRead)  

}

void loop() {
  buttoncheck();
}
