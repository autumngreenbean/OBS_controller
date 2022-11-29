#include "Mouse.h"
#include "Keyboard.h"
#include <MouseTo.h>
const byte toggle= 2; 
const byte select= 3;
const byte val3= 4;
const byte val2= 5;
const byte val1= 6;
bool switched;
bool decrease;
int currentFilter;
int currentVal;
int offset1;
int offset2Index;
int offset3Index;
int num = -1; //for testing
double offset2[7] = {-1.00,0.00,1.00,2.00,3.00,4.00,5.00};
double offset3[6] = {-180.0,-90,-45,0,45,90};

void setup() {
//assign pins
  pinMode(toggle, INPUT_PULLUP);
  pinMode(select, INPUT_PULLUP);
  pinMode(val1, INPUT_PULLUP);
  pinMode(val2, INPUT_PULLUP);
  pinMode(val3, INPUT_PULLUP);
   while (!Serial) {
    ; 
  }
  offset2Index,offset3Index = 0;
  offset1 = -4;
  switched = false;
  decrease = false;
  begin();
}

void begin() {
  Keyboard.begin();
  Mouse.begin();
//Open OBS
  Keyboard.press(KEY_LEFT_GUI); 
  Keyboard.press('r');         
  delay(100);                  
  Keyboard.releaseAll();       
  delay(1000);                  
  Keyboard.print("cmd");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(3000); 
  Keyboard.print("cd C:\\Program Files\\obs-studio\\bin\\64bit\\");
  delay(1000);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print("start obs64.exe");
  delay(1000);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(5000);

//Select Scene
  MouseTo.setTarget(50, 545);
  while (MouseTo.move()== false) {}
  delay(100);
    //Navigate to filters
      delay(100);
      Mouse.click(MOUSE_RIGHT);
      delay(100);
      Mouse.move(50,-73); 
      delay(500);
      Mouse.click();
      delay(500);
     
//Nav to filter 3 (Recursion)
    Keyboard.press(KEY_DOWN_ARROW);
    delay(200);   
    Keyboard.releaseAll();
    Keyboard.press(KEY_DOWN_ARROW);
    delay(200);   
    Keyboard.releaseAll();
    currentFilter = 3;
  //Go to val1 of filter 3
  MouseTo.setTarget(900, 445);
  while (MouseTo.move()== false) {}
  delay(100);
  Mouse.click();
  currentVal = 1;
}

void value2() {
  if (currentFilter== 3) recursion(2);
  if (currentFilter== 4) drunkShad(2);
  if (currentFilter== 5) colorCorrect(2);
  currentVal = 2;
} 

void value3() {
  if (currentFilter== 3) recursion(3);
  if (currentFilter== 4) drunkShad(3);
  if (currentFilter== 5) colorCorrect(3);
  currentVal= 3;
}

void value1(bool reset) {
//reset current navigation to value 1
  if (reset== true) {
    if (currentFilter== 3) { //Recursion
      MouseTo.setTarget(900, 445);
      while (MouseTo.move()== false) {}
      delay(100);
      Mouse.click();
  }
    if (currentFilter== 4) { //Drunk Shader
      MouseTo.setTarget(900, 374); 
      while (MouseTo.move()== false) {}
      delay(100);
      Mouse.click();      
    }
    if (currentFilter== 5) { //Color Correction
      MouseTo.setTarget(1050, 470); 
      while (MouseTo.move()== false) {}
      delay(100);
      Mouse.click();
      Keyboard.press(KEY_RIGHT_CTRL);
      Keyboard.press('a');
      Keyboard.releaseAll();
      switched= false;
    }
  }
//value1 pressed
  if (reset== false)  {
    if(currentFilter== 3) recursion(1);
    if (currentFilter== 4) drunkShad(1);
    if (currentFilter== 5) colorCorrect(1);
  }
  currentVal = 1;
}

void colorCorrect(int valPressed) {
  if (valPressed== 1) {
    if (currentVal== 3) value1(true); 
    if (currentVal== 2) value1(true); 
    if (currentVal== 1) {
      if (switched== true) {
      Keyboard.press(KEY_RIGHT_CTRL);
      Keyboard.press('a');
      Keyboard.releaseAll();
      delay(100);
      } else switched= true;
      
      Keyboard.print(String(offset1));
      delay(200);
      if (offset1== 4) decrease= true;
      if (offset1== -4) decrease = false;
      if (decrease== true) offset1--;
      if (decrease== false) offset1++;
      delay(200);
      
    }
  }
 if (valPressed== 2) {
   if (currentVal== 1) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
   }
    if (currentVal== 2) { 
      if(offset2Index== 8) offset2Index= 0;
      Keyboard.print(String(offset2[offset2Index]));
      delay(200);
      offset2Index++;
    }
    if (currentVal== 3) {
      value1(true);
      delay(200);
      colorCorrect(2);
    }
  }

  if (valPressed== 3) {
    if (currentVal== 3) {
      if(offset3Index== 7) offset3Index= 0;
       Keyboard.print(String(offset3[offset3Index]));
       delay(200);
       offset3Index++;
      }
     if (currentVal== 3) {
        value1(true);
        delay(200);
        colorCorrect(2);
      }
    }
    if (currentVal== 2) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
    }
      if (currentVal== 1) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
    }
  }

void drunkShad(int valPressed) {
 if (valPressed== 1) {
    if (currentVal== 3) value1(true); 
    if (currentVal== 2) value1(true); 
    if (currentVal== 1) {
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
    }
 }
 if (valPressed== 2) {
   if (currentVal== 1) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
   }
    if (currentVal== 2) {
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentVal== 3) {
      value1(true);
      delay(200);
      drunkShad(2);
    }
  }

  if (valPressed== 3) {
    if (currentVal== 3) {
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentVal== 2) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
    }
      if (currentVal== 1) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
    }
  }
}

void recursion(int valPressed) {
  if (valPressed== 1) {
    if (currentVal== 3) value1(true); 
    if (currentVal== 2) value1(true); 
    if (currentVal== 1) {
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
    }
  }
  if (valPressed== 2) {
    if (currentVal== 1) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentVal== 2) {
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentVal== 3) {
      value1(true);
      delay(200);
      recursion(2);
    }
    
  }
  if (valPressed== 3) {
    if (currentVal== 3) {
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentVal== 2) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
    }
      if (currentVal== 1) {
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_TAB);
      delay(200);
      Keyboard.releaseAll();
    }
  }
}
void switcher() {
//default value settings each time switched

//switch filter
  //select filter panel
  MouseTo.setTarget(500, 445);
  while (MouseTo.move()== false) {}
  delay(100);
  Mouse.click();
 
   if (currentFilter== 5) { //cycle if last instance
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
      Keyboard.releaseAll();
      offset2Index= 0;
      currentFilter= 3;
    }
    else {  //next filter
      Keyboard.press(KEY_DOWN_ARROW);
      delay(200); 
      Keyboard.releaseAll();
      currentFilter++;
    }
    if (currentFilter== 4) { //Drunk Shader
      MouseTo.setTarget(1100, 370);
      while (MouseTo.move() == false) {}
      delay(50);
      Mouse.press();
      Mouse.move(0,85);
      delay(100);
      Mouse.release();
      Mouse.move(-50,-50);
      Mouse.click();
    } 
    if (currentFilter== 5) {
      offset1= -4;
    }
  delay(500);
 value1(true);  

}

void hider() {
  //hide scenes
  if (currentFilter== 3) {Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('3');}
  if (currentFilter== 4) {Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('4');}
  if (currentFilter== 5) {Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('5');}
  delay(200);
  Keyboard.releaseAll();
}
void buttoncheck() {
  
  if (digitalRead(6)== LOW) value1(false);
  if (digitalRead(5)== LOW) value2();
  if (digitalRead(4)== LOW) value3();
  if (digitalRead(3)== LOW) switcher();
  if (digitalRead(2)== LOW) hider();
  
}

void test() { //for value1() colorCorrect
  if (digitalRead(select)== LOW) {
  String myString = String(num);
  Keyboard.print(myString);
  delay(200);
  }
}

void loop() {
  buttoncheck();
  // test();
}
