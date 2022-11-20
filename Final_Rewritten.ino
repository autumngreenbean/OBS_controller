#include <Mouse.h>
#include <MouseTo.h>
#include <Keyboard.h>
const byte edit = 2; 
const byte select = 3;
const byte val1 = 4;
const byte val2 = 5;
const byte val3 = 6;
bool editing;
bool home;
bool v1;
bool v2;
bool v3;

int currentScene;


void setup() {
pinMode(select, INPUT_PULLUP);
editing = false; 
home = true;
v1 = true;
currentScene = 1;
}

void buttonCheck() {
 if(digitalRead(select) == LOW) switcher();
 
  if (digitalRead(edit) == LOW) {
     
      if (home) { editor(0); launchEdit(); }
      else if (editing) {
      Keyboard.press(KEY_ESC); 
      delay(100); 
      Keyboard.releaseAll();
      home = true; 
      editing = false;
      }

  delay(1000);
    }
  
  if (digitalRead(val1) == LOW) {
      editor(1);
      delay(200);
  }
  if (digitalRead(val2) == LOW) {
      v1 = false; 
      v2 = true; 
      v3 = false; 
      delay(200);
   }
  if (digitalRead(val3) == LOW) {
      v1 = false; 
      v2 = false; 
      v3 = true;
      delay(200);
  }
}
void launchEdit() {
//Select source 1 in current scene
    MouseTo.setTarget(350, 545);
    while (MouseTo.move() == false) {}
    delay(100);
    Mouse.click();

//Open filter 
    Mouse.move(0,-40);
    delay(100);
    Mouse.click(); //open
    delay(50);
    Mouse.click(); //open type
    editing = true; 
    home = false;

//setup value editor
value1();
}

void value1() {
//Go to val1
    if (currentScene == 1) {

    }
    if (currentScene == 2) {
      //scrollbar
      MouseTo.setTarget(1100, 370);
      while (MouseTo.move() == false) {}
      delay(50);
      Mouse.press();
      Mouse.move(0,85);
      delay(100);
      Mouse.release();
      Mouse.move(-50,-60);
      Mouse.click();
    }
    if (currentScene == 3) {
      
    }
    if (currentScene == 4) {
      
    }
}

void editor(int myVal) { 
 
   
      if (myVal == 1) { //8
        Keyboard.press(KEY_UP_ARROW);
        delay(1000);
        Keyboard.releaseAll();
        
        myVal = 0;
      }
    
  }


void switcher() {

//switch scenes
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(200);
    Keyboard.releaseAll();
    if (currentScene == 1) {
      currentScene = 2;
    }
    else if (currentScene == 2) {
      currentScene = 3;
    }
    else if (currentScene == 3) {
      currentScene = 4;
    }
    else if (currentScene == 4) {
      currentScene = 1;
    }
    
    delay(500);
}

void loop() {
  buttonCheck();
}


