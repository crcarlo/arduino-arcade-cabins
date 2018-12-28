#include <Keyboard.h>

/*
 Authors: Carlo Cervellin - Gabriele Cervellin
 Arduino version: Arduino Pro Micro
*/

// player 1
const char _1up = KEY_UP_ARROW;
const char _1right = KEY_RIGHT_ARROW;
const char _1down = KEY_DOWN_ARROW;
const char _1left = KEY_LEFT_ARROW;

/*
const char _1a = KEY_LEFT_CTRL;
const char _1b = KEY_LEFT_ALT;
const char _1c = ' ';
const char _1d = KEY_LEFT_SHIFT;
*/

const char _1a = 'a';
const char _1b = 's';
const char _1c = 'd';
const char _1d = 'f';


const char _1coin = '1';
const char _1start = '5';

// player 2
const char _2up = 'r';
const char _2right = 'g';
const char _2down = 'f';
const char _2left = 'd';

const char _2a = 'a';
const char _2b = 's';
const char _2c = 'q';
const char _2d = 'd';

const char _2coin = '2';
const char _2start = '6';

void setup() {

  //Serial.begin(9600);
  Keyboard.begin();

  //MAPPATURA PULSANTI
  pinMode(2, INPUT); //SU: freccia-su / r
  pinMode(3, INPUT); //DESTRA: freccia-dx / g
  pinMode(4, INPUT); //GIU: freccia-giu / f
  pinMode(5, INPUT); //SINISTRA: freccia-sx / d

  pinMode(6, INPUT); //P1: ctrl-sx / a
  pinMode(7, INPUT); //P2: alt-sx / s
  pinMode(8, INPUT); //P3: space / q
  pinMode(9, INPUT); //P4: shift-sx / w

  pinMode(10, INPUT); //COIN: 1 / 2
  pinMode(16, INPUT); //START: 5 / 6

  pinMode(15, INPUT);  //SW1: Selezione player 1 / 2
  pinMode(14, INPUT);  //SW2: Selezione turbo P1 on / off

}

void loop() {
  
  //Da implementare controllo SW2: ALTO=P1-TURBO-OFF BASSO=P1-TURBO-ON (serve hardware per testare)

  //SW1: ALTO=PLAYER1 BASSO=PLAYER2
  boolean player1;
  player1=true;
  //if (digitalRead(8) == HIGH) player1=true;
  //else player1=false;
  
  //--------//
  //PLAYER 1//
  //--------//
  if (player1) {
    checkKey(2, _1up);
    checkKey(3, _1right);
    checkKey(4, _1down);
    checkKey(5, _1left);
    checkKey(6, _1a);
    checkKey(7, _1b);
    checkKey(8, _1c);
    checkKey(9, _1d);
    checkKey(10,_1coin);
    checkKey(16,_1start);
  }
  //--------//
  //PLAYER 2//
  //--------//
  else {
    checkKey(2, _2up);
    checkKey(3, _2right);
    checkKey(4, _2down);
    checkKey(5, _2left);
    checkKey(6, _2a);
    checkKey(7, _2b);
    checkKey(8, _2c);
    checkKey(9, _2d);
    checkKey(10,_2coin);
    checkKey(16,_2start);
  }
  
}

void checkKey(int pin, char key) {
  int statoPulsante=LOW;
  statoPulsante = digitalRead(pin);
  if (statoPulsante == HIGH) {
    Keyboard.press(key);
  }
  else {
    Keyboard.release(key);
  }
}

