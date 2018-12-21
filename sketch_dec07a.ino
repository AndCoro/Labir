//LCD
#include <LiquidCrystal.h>
#define V0_PIN 9
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//Joystick
#define JOY_X A0
#define JOY_Y A1

//matrix
#include "LedControl.h"
LedControl lc = LedControl(12, 11, 10, 1);

bool Smile[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

bool Sad[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 1}
};

bool Three[8][8] = {
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0}
};

bool Two[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

bool One[8][8] = {
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};

bool mEasy[8][8] = {
  {1, 1, 1, 0, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 1, 1, 1},
  {1, 1, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 0, 1}
};

bool mMed[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 1, 1, 1, 0, 1},
  {0, 1, 0, 0, 0, 1, 0, 0},
  {0, 1, 1, 0, 1, 0, 1, 1},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 1, 0, 1, 1, 1, 1, 0},
  {0, 1, 0, 1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 1, 1, 0}
};

bool mDif[8][8] = {
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 1, 0, 0, 1, 1, 1, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {1, 0, 0, 1, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0},
  {1, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 1, 0, 0, 0}
};
//Joystick
int valX = 0, valY = 0;
int posX = 0, posY = 0, prevX = 0, prevY = 0;
unsigned long ultimulUpdate = 0;

//button
const int buttonPin = 8;
int buttonState = 0;

//level and difficult
int level = 0;
int timer = 0;
int win = 0;
int lose = 0;

// constant easy level
int colE = 3;
int rowE = 0;
const int trueEpntC = 6;
const int trueEpntR = 7;

//constant medium level
int colM = 7;
int rowM = 2;
int restartC = colM;
int restartR = rowM;
const int trueMpntR = 3;
const int trueMpntC = 5;
const int falseMpntR = 3;
const int falseMpntC = 3;

//costant difficult level
int rowD = 0;
int colD = 4;
int restartC1 = colD;
int restartR1 = rowD;
const int trueDpntR = 4;
const int trueDpntC = 4;
const int falseDpntR = 7;
const int falseDpntC = 3;
const int falseDpntR1 = 4;
const int falseDpntC1 = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  lc.shutdown(0, false); 
  lc.setIntensity(0, 2); 
  lc.clearDisplay(0);
  pinMode(JOY_X, INPUT);
  pinMode(JOY_Y, INPUT);
  pinMode(V0_PIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  analogWrite(V0_PIN, 90);
  if (level == 0) {
    lcd.setCursor(1, 0);
    lcd.print("hello Bro!");
    lcd.setCursor(2, 1);
    lcd.print("I'm Labir");
    delay(2000);
    lcd.clear();
  }
}

void loop()
{// -------------level START------------------
  while (level == 0) {
    buttonState=0;
    lcd.setCursor(1, 0);
    lcd.print("Do you want to ");
    lcd.setCursor(0, 1);
    lcd.print("play the game?");
    delay(2000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Yes = bottom");
    lcd.setCursor(1, 1);
    lcd.print("No = Joystick");
    buttonState = digitalRead(buttonPin);
    valX = analogRead(JOY_X);
    valY = analogRead(JOY_Y);
    if (buttonState == HIGH) {
      level = 1;
      lcd.clear();
      break;
    }
    if (valX < 400 || valX > 600 || valY < 400 || valY > 600) {
      lcd.clear();
      level = 8;
      break;
    }
  delay(2000);
  }
// -------------level 1------------------
  while (level == 1) {
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, Three[row][col]);
      }
    }
    delay(600);
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, Two[row][col]);
      }
    }
    delay(400);
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, One[row][col]);
      }
    }
    delay(400);
    level = 2;
    timer = 17;
    break;
  }
// -------------level 2------------------
  while (level == 2) {
    buttonState = 0;
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, mEasy[row][col]);
      }
    }
    lc.setLed(0, trueEpntR, trueEpntC, true);
    delay(50);
    lc.setLed(0, trueEpntR, trueEpntC, false);
    delay(50);
    lc.setLed(0, rowE, colE, true);
    delay(150);
    lc.setLed(0, rowE, colE, false);
    delay(150);
    int intervalRecalculare = 60;
    if ((millis() - ultimulUpdate) >= intervalRecalculare) {
      ultimulUpdate = millis();
      prevY = colE;
      prevX = rowE;
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      lcd.setCursor(1, 0);
      lcd.print("Moves:");
      lcd.setCursor(1, 1);
      lcd.print(timer);
      if (valX < 400 && rowE > 0 && mEasy[rowE - 1][colE] == 0) {
        prevX = rowE;
        rowE--;
        timer--;
      } else if (valX > 600 && rowE < 7 && mEasy[rowE + 1][colE] == 0) {
        prevX = rowE;
        rowE++;
        timer--;
      }
      if (valY < 400 && colE > 0 && mEasy[rowE][colE + 1] == 0 ) {
        prevY = colE;
        colE++;
        timer--;
      } else if (valY > 600 && colE < 7 && mEasy[rowE][colE - 1] == 0 ) {
        prevY = colE;
        colE--;
        timer--;
      }
    }
    if (rowE == trueEpntR && colE == trueEpntC ) {
      lcd.setCursor(1, 0);
      lcd.print("You Win");
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      delay(400);
      for (int row = 0; row < 8; row++)
      {
        for (int col = 0; col < 8; col++)
        {
          lc.setLed(0, rowE, colE, false);
          lc.setLed(0, row, col, Smile[row][col]);
        }
      }
      delay(700);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, true);
          delay(100);
        }
      }
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
          delay(100);
        }
      }
      delay(2000);
      lcd.clear();
      win = 1;
    }
    while (win == 1) {
      lcd.setCursor(1, 0);
      lcd.print("Next Level?");
      lcd.setCursor(0, 1);
      lcd.print("yes=bot No=joy");
      delay(2000);
      buttonState = digitalRead(buttonPin);
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      if (buttonState == HIGH) {
        level = 3;
        win = 0;
        lcd.clear();
        break;
      }
      if (valX < 400 || valX > 600 || valY < 400 || valY > 600) {
        lcd.clear();
        win = 0;
        level = 7;
        break;
      }
      delay(3000);
    }
    if (timer == 0) {
      lcd.setCursor(1, 0);
      lcd.print("YOU LOSE");
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      for (int row = 0; row < 8; row++)
      {
        for (int col = 0; col < 8; col++)
        {
          lc.setLed(0, row, col, Sad[row][col]);
        }
      }
      delay(800);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      lose = 1;
    }
    while (lose == 1) {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("try again?");
      lcd.setCursor(0, 1);
      lcd.print("yes=bot No=joy");
      delay(2000);
      buttonState = digitalRead(buttonPin);
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      if (buttonState == HIGH) {
        level = 1;
        lose = 0;
        lcd.clear();
        break;
      }
      if (valX < 400 || valX > 600 || valY < 400 || valY > 600) {
        lcd.clear();
        lose = 0;
        level = 8;
        break;
      }
    }
  }
// -------------level 3------------------
  while (level == 3) {
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, Three[row][col]);
      }
    }
    delay(600);
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, Two[row][col]);
      }
    }
    delay(400);
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, One[row][col]);
      }
    }
    delay(400);
    lcd.setCursor(1, 0);
    lcd.print("only one point");
    lcd.setCursor(1, 1);
    lcd.print("is the exit");
    delay(2000);
    lcd.clear();
    timer = 31;
    level = 4;
    break;
  }
// -------------level 4------------------
  while (level == 4) {
    buttonState = 0;
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, mMed[row][col]);
      }
    }
    lc.setLed(0, trueMpntR, trueMpntC, true);
    lc.setLed(0, falseMpntR, falseMpntC, true);
    delay(50);
    lc.setLed(0, trueMpntR, trueMpntC, false);
    lc.setLed(0, falseMpntR, falseMpntC, false);
    delay(50);
    lc.setLed(0, rowM, colM, true);
    delay(150);
    lc.setLed(0, rowM, colM, false);
    delay(150);
    int intervalRecalculare1 = 60;
    if ((millis() - ultimulUpdate) >= intervalRecalculare1) {
      ultimulUpdate = millis();
      prevY = colM;
      prevX = rowM;
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Moves:");
      lcd.setCursor(1, 1);
      lcd.print(timer);
      if (valX < 400 && rowM > 0 && mMed[rowM - 1][colM] == 0) {
        prevX = rowM;
        rowM--;
        timer--;
      } else if (valX > 600 && rowM < 7 && mMed[rowM + 1][colM] == 0) {
        prevX = rowM;
        rowM++;
        timer--;
      }
      if (valY < 400 && colM > 0 && mMed[rowM][colM - 1] == 0 ) {
        prevY = colM;
        colM--;
        timer--;
      } else if (valY > 600 && colM < 7 && mMed[rowM][colM + 1] == 0 ) {
        prevY = colM;
        colM++;
        timer--;
      }
    }
    if (rowM == falseMpntR && colM == falseMpntC) {
      rowM = restartR;
      colM = restartC;
    }
    if (rowM == trueMpntR && colM == trueMpntC ) {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("You Win");
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      delay(400);
      for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
          lc.setLed(0, rowM, colM, false);
          lc.setLed(0, row, col, Smile[row][col]);
        }
      }
      delay(700);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, true);
          delay(100);
        }
      }
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
          delay(100);
        }
      }
      win = 1;
    }
    while (win == 1) {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Next Level?");
      lcd.setCursor(0, 1);
      lcd.print("yes=bot No=joy");
      buttonState = digitalRead(buttonPin);
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      if (buttonState == HIGH) {
        level = 5;
        win = 0;
        lcd.clear();
        break;
      }
      if (valX < 400 || valX > 600 || valY < 400 || valY > 600) {
        lcd.clear();
        win = 0;
        level = 8;
        break;
      }
      delay(2000);
    }
    if (timer == 0) {
      lcd.setCursor(1, 0);
      lcd.print("YOU LOSE");
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      for (int row = 0; row < 8; row++)
      {
        for (int col = 0; col < 8; col++)
        {
          lc.setLed(0, row, col, Sad[row][col]);
        }
      }
      delay(800);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      lcd.clear();
      lose = 1;
    }
    while (lose == 1) {
      lcd.setCursor(3, 0);
      lcd.print("try again?");
      lcd.setCursor(0, 1);
      lcd.print("yes=bot No=joy");
      buttonState = digitalRead(buttonPin);
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      if (buttonState == HIGH) {
        level = 3;
        lose = 0;
        lcd.clear();
        break;
      }
      if (valX < 400 || valX > 600 || valY < 400 || valY > 600) {
        lcd.clear();
        lose = 0;
        level = 8;
        break;
      }
      delay(2000);
    }
  }
// -------------level 5------------------
  while (level == 5) {
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, Three[row][col]);
      }
    }
    delay(600);
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, Two[row][col]);
      }
    }
    delay(400);
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, One[row][col]);
      }
    }
    lcd.setCursor(1, 0);
    lcd.print("only one point");
    lcd.setCursor(1, 1);
    lcd.print("is the exit");
    delay(3000);
    lcd.clear();
    level = 6;
    timer = 30;
    break;
  }
// -------------level 6------------------
  while (level == 6) {
    buttonState = 0;
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        lc.setLed(0, row, col, mDif[row][col]);
      }
    }
    lc.setLed(0, trueDpntR, trueDpntC, true);
    lc.setLed(0, falseDpntR, falseDpntC, true);
    lc.setLed(0, falseDpntR1, falseDpntC1, true);
    delay(50);
    lc.setLed(0, trueDpntR, trueDpntC, false);
    lc.setLed(0, falseDpntR, falseDpntC, false);
    lc.setLed(0, falseDpntR1, falseDpntC1, false);
    delay(50);
    lc.setLed(0, rowD, colD, true);
    delay(150);
    lc.setLed(0, rowD, colD, false);
    delay(150);
    int intervalRecalculare2 = 60;
    if ((millis() - ultimulUpdate) >= intervalRecalculare2) {
      ultimulUpdate = millis();
      prevY = colD;
      prevX = rowD;
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      lcd.setCursor(1, 0);
      lcd.print("Moves:");
      lcd.setCursor(1, 1);
      lcd.print(timer);
      if (valX < 400 && rowD > 0 && mDif[rowD - 1][colD] == 0) {
        prevX = rowD;
        rowD--;
        timer--;
      } else if (valX > 600 && rowD < 7 && mDif[rowD + 1][colD] == 0) {
        prevX = rowD;
        rowD++;
        timer--;
      }
      if (valY < 400 && colD > 0 && mDif[rowD][colD - 1] == 0 ) {
        prevY = colD;
        colD--;
        timer--;
      } else if (valY > 600 && colD < 7 && mDif[rowD][colD + 1] == 0 ) {
        prevY = colD;
        colD++;
        timer--;
      }
    }
    if (( rowD == falseDpntR && colD == falseDpntC) || (rowD == falseDpntR1 && colD == falseDpntC1) ) {
      rowD = restartR1;
      colD = restartC1;
    }
    if (rowD == trueDpntR && colD == trueDpntC ) {
      lcd.setCursor(1, 0);
      lcd.print("You Win");
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      delay(400);
      for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
          lc.setLed(0, rowD, colD, false);
          lc.setLed(0, row, col, Smile[row][col]);
        }
      }
      delay(700);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, true);
          delay(100);
        }
      }
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
          delay(100);
        }
      }
      delay(2000);
      level = 7;
      break;
    }
    if (timer == 0) {
      lcd.setCursor(1, 0);
      lcd.print("YOU LOSE");
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      for (int row = 0; row < 8; row++)
      {
        for (int col = 0; col < 8; col++)
        {
          lc.setLed(0, row, col, Sad[row][col]);
        }
      }
      delay(800);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          lc.setLed(0, j, i, false);
        }
      }
      lcd.clear();
      lose = 1;
    }
    while (lose == 1) {
      lcd.setCursor(3, 0);
      lcd.print("try again?");
      lcd.setCursor(0, 1);
      lcd.print("yes=bot No=joy");
      buttonState = digitalRead(buttonPin);
      valX = analogRead(JOY_X);
      valY = analogRead(JOY_Y);
      if (buttonState == HIGH) {
        level = 5;
        lose = 0;
        lcd.clear();
        break;
      }
      if (valX < 400 || valX > 600 || valY < 400 || valY > 600) {
        lcd.clear();
        lose = 0;
        level = 8;
        break;
      }
      delay(2000);
    }
  }
  // -------------level 7------------------
  while (level == 7) {
    buttonState = 0;
    lcd.setCursor(3, 0);
    lcd.print("THE END!!");
    delay(2000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("try again?");
    lcd.setCursor(0, 1);
    lcd.print("yes=bot No=joy");
    buttonState = digitalRead(buttonPin);
    valX = analogRead(JOY_X);
    valY = analogRead(JOY_Y);
    if (buttonState == HIGH) {
      level = 0;
      colE = 3;
      rowE = 0;
      colM = 7;
      rowM = 2;
      rowD = 0;
      colD = 4;
      lcd.clear();
      break;
    }
    if (valX < 400 || valX > 600 || valY < 400 || valY > 600) {
      lcd.clear();
      level = 8;
      break;
    }
    delay(2000);
  }
//-------------level END------------------
  while (level == 8) {
    lcd.setCursor(0, 1);
    lcd.print("THE END!!");
    break;
  }
}
