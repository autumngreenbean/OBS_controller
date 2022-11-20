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

int currentVal;
int currentScene;


void setup() {
pinMode(select, INPUT_PULLUP);
editing = false; 
home = true;

currentScene = 1;

}

void buttonCheck() {
 if(digitalRead(select) == LOW) switcher();
 
  if (digitalRead(edit) == LOW) {
     if (editing) {
      Keyboard.press(KEY_ESC); 
      delay(100); 
      Keyboard.releaseAll();
      home = true; 
      editing = false;
      }
    else if (home) { editor(0); launchEdit(); }
      
  delay(1000);
    }
  
  if (digitalRead(val1) == LOW) {
      editor(1);
      valSwitch(currentVal,currentScene, 1);
  }
  if (digitalRead(val2) == LOW) {
     editor(2);
   }
  if (digitalRead(val3) == LOW) {
      editor(3);
  }
}
void launchEdit() {
//Select source 1 of current scene
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

//GO to value1 of current scene
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

void valSwitch(int value, int scene, int targetVal) {
  if (targetVal == value) {}
  else if (targetVal == 1 && value == 3) value1();
  else if (targetVal == 1 && value == 2) value1();
  else if (scene == 1) {

       if (targetVal == 2 && value == 3) { //move from 3 to 2
          value1();
          //tab tab...
      }
       if (targetVal == 5 && value == 2) { //move from 2 to 3
          //tab tab...
      }
  } 
  else if (scene == 2) {

       if (targetVal == 2 && value == 3) { //move from 3 to 2
          value1();
          //tab tab...
      }
       if (targetVal == 5 && value == 2) { //move from 2 to 3
          //tab tab...

  }
  else if (scene == 3) {

       if (targetVal == 2 && value == 3) { //move from 3 to 2
          value1();
          //tab tab...
      }
       if (targetVal == 5 && value == 2) { //move from 2 to 3
          //tab tab...
  }
  else if (scene == 4) {

       if (targetVal == 2 && value == 3) { //move from 3 to 2
          value1();
          //tab tab...
      }
       if (targetVal == 5 && value == 2) { //move from 2 to 3
          //tab tab...
  }
}

void editor(int myVal) { 
 myVal = currentVal;
      if (myVal == 1) { //8
        Keyboard.press(KEY_UP_ARROW);
        delay(1000);
        Keyboard.releaseAll();
        myVal = 0;
      }
    
  }


void switcher() {
//Default settings

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


