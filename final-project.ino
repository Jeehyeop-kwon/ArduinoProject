/*
        Project : 4x4x4 LED Cube
        Name : Jeehyuep Kwon
        Date : Dec 5 / 2018

  Columns - Pin number======================
    [1,1] = 0
    [1,2] = 1
    [1,3] = 2
    [1,4] = 3
    [2,1] = 4
    [2,2] = 5
    [2,3] = 6
    [2,4] = 7
    [3,1] = 8
    [3,2] = 9
    [3,3] = 10
    [3,4] = 11
    [4,1] = 12
    [4,2] = 13
    [4,3] = A5
    [4,4] = A4
  
  layer - Pin number =======================
  First layer  = A0
  Second layer = A1
  Third layer  = A2
  Fourth layer = A3
*/

//-------------------------Variables-------------------------
//initializing and declaring led columns
int column[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A5, A4};
//initializing and declaring led layers
int layer[4] = {A0, A1, A2, A3};

int time = 250;

//-------------------------setup---------------------------
void setup() {

  //setting rows to ouput
  for (int i = 0; i < 16; i++) {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for (int i = 0; i < 4; i++) {
    pinMode(layer[i], OUTPUT);
  }
  //seeding random for random pattern
  randomSeed(analogRead(10));
}


//----------------------------Loop----------------------------
//------------------------------------------------------------
void loop() {

  turnEverythingOff();
  layerUpAndDown();
  flicker();
  layerUpAndDown2();
  columnLineUp();
  spiralUpAndDown();
  rain();
  columnRun();
  squareMovement();
  squareMovement();
  rainReverse();
  dispersion();

  delay(1000);
}

//----------------------------Function----------------------------
//----------------------------------------------------------------
//turn all off====================================================
void turnEverythingOff() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(column[i], 1);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], 0);
  }
}

//turn all on====================================================
void turnEverythingOn() {

  for (int i = 0; i < 16; i++) {
    digitalWrite(column[i], 0);
  }
  //turning on layers
  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], 1);
  }
}

//turn columns off====================================================
void turnColumnsOff() {

  for (int i = 0; i < 16; i++) {
    digitalWrite(column[i], 1);
  }
}

//layer Up and Down====================================================
void layerUpAndDown() {

  for (int count = 0; count < 3; count++) {
    turnEverythingOn();

    for (int i = 4; i != 0; i--) {
      digitalWrite(layer[i - 1], 0);
      delay(200);
    }

    for (int i = 4; i != 0; i--) {
      digitalWrite(layer[i - 1], 1);
      delay(200);
    }
    for (int i = 0; i < 4; i++) {
      digitalWrite(layer[i], 0);
      delay(200);
    }

    for (int i = 0; i < 4; i++) {
      digitalWrite(layer[i], 1);
      delay(200);
    }
  }
}
//layerUpAndDown2====================================================
void layerUpAndDown2() {

  for (int count = 0; count < 3; count++) {

    //vertical movement
    for (int i = 4; i != 0; i--) {
      digitalWrite(layer[i - 1], 1);
      for (int i = 0; i < 16; i++) {
        digitalWrite(column[i], 0);
      }
      delay(50);
      digitalWrite(layer[i - 1], 0);

      for (int i = 0; i < 16; i++) {
        digitalWrite(column[i], 1);
      }
      delay(50);
    }

    //reverse
    for (int i = 0; i < 4; i++) {
      digitalWrite(layer[i], 1);
      for (int i = 0; i < 16; i++) {
        digitalWrite(column[i], 0);
      }
      delay(50);
      digitalWrite(layer[i], 0);

      for (int i = 0; i < 16; i++) {
        digitalWrite(column[i], 1);
      }
      delay(50);
    }
  }


  for (int count = 0; count < 3; count++) {
    //side column move to side(first wall)
    for (int i = 0; i < 4; i++) {
      digitalWrite(layer[i], 1);
      digitalWrite(column[i], 0);
    }
    delay(150);
    for (int i = 0; i < 4; i++) {
      digitalWrite(column[i], 1);
    }

    //side column move to side(second wall)
    for (int i = 4; i < 8; i++) {
      digitalWrite(column[i], 0);
    }
    delay(150);
    for (int i = 4; i < 8; i++) {
      digitalWrite(column[i], 1);
    }

    //side column move to side(third wall)

    for (int i = 8; i < 12; i++) {
      digitalWrite(column[i], 0);
    }
    delay(150);
    for (int i = 8; i < 12; i++) {
      digitalWrite(column[i], 1);
    }
    //side column move to side(fourth wall)

    for (int i = 12; i < 16; i++) {
      digitalWrite(column[i], 0);
    }
    delay(150);
    for (int i = 12; i < 16; i++) {
      digitalWrite(column[i], 1);
    }
    //reverse
    for (int i = 16; i != 12; i--) {

      digitalWrite(column[i - 1], 0);
    }
    delay(150);
    for (int i = 16; i != 12; i--) {
      digitalWrite(column[i - 1], 1);
    }

    //side column move to side(second wall)
    for (int i = 12; i != 8; i--) {
      digitalWrite(column[i - 1], 0);
    }
    delay(150);
    for (int i = 12; i != 8; i--) {
      digitalWrite(column[i - 1], 1);
    }

    //side column move to side(third wall)

    for (int i = 8; i != 4; i--) {
      digitalWrite(column[i -1], 0);
    }
    delay(150);
    for (int i = 8; i != 4; i--) {
      digitalWrite(column[i - 1], 1);
    }
    //side column move to side(fourth wall)

    for (int i = 4; i != 0 ; i--) {
      digitalWrite(column[i - 1], 0);
    }
    delay(150);
    for (int i = 4; i != 0 ; i--) {
      digitalWrite(column[i - 1], 1);
    }
  }
  turnEverythingOff();
}

//flicker====================================================
void flicker() {

  for (int time = 200; time > 0; time -= 10) {
    turnEverythingOn();
    delay(time);
    turnEverythingOff();
    delay(time);
  }
}
//column line up====================================================
void columnLineUp() {

  //layer : turn on
  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], 1);
  }
  //column 0 - 3 : turn on
  for (int i = 0; i < 4; i++) {
    digitalWrite(column[i], 0);
    delay(100);
  }

  //column 4 - 7 : turn on
  for (int i = 4; i < 8; i++) {
    digitalWrite(column[i], 0);
    delay(100);
  }

  //column 8 - 11 : turn on
  for (int i = 8; i < 12; i++) {
    digitalWrite(column[i], 0);
    delay(100);
  }
  //column 12 - 15 : turn on
  for (int i = 12; i < 16; i++) {
    digitalWrite(column[i], 0);
    delay(100);
  }

  //column 0 - 3 : turn off
  for (int i = 0; i < 4; i++) {
    digitalWrite(column[i], 1);
    delay(100);
  }

  //column 4 - 7 : turn off
  for (int i = 4; i < 8; i++) {
    digitalWrite(column[i], 1);
    delay(100);
  }

  //column 8 - 11 : turn off
  for (int i = 8; i < 12; i++) {
    digitalWrite(column[i], 1);
    delay(100);
  }
  //column 12 - 15 : turn off
  for (int i = 12; i < 16; i++) {
    digitalWrite(column[i], 1);
    delay(100);
  }
}

//spiral up and down====================================================
void spiralUpAndDown() {
  int time = 100;
  turnEverythingOff();
  //spiral first layer
  digitalWrite(layer[0], 1);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[5], 0);
  delay(time);
  digitalWrite(column[9], 0);
  delay(time);
  digitalWrite(column[10], 0);
  delay(time);
  digitalWrite(column[6], 0);
  delay(time);
  turnEverythingOff();
  //spiral second layer
  digitalWrite(layer[1], 1);
  digitalWrite(column[5], 0);
  delay(time);
  digitalWrite(column[9], 0);
  delay(time);
  digitalWrite(column[10], 0);
  delay(time);
  digitalWrite(column[6], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[3], 0);
  delay(time);
  turnEverythingOff();
  //spiral third layer
  digitalWrite(layer[2], 1);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[6], 0);
  delay(time);
  digitalWrite(column[5], 0);
  delay(time);
  digitalWrite(column[9], 0);
  delay(time);
  digitalWrite(column[10], 0);
  delay(time);

  turnEverythingOff();
  //spiral forth layer
  digitalWrite(layer[3], 1);
  digitalWrite(column[10], 0);
  delay(time);
  digitalWrite(column[6], 0);
  delay(time);
  digitalWrite(column[5], 0);
  delay(time);
  digitalWrite(column[9], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
}

//rain====================================================
void rain() {
  turnEverythingOff();
  int time = 20;
  //count
  for (int count = 0; count < 30; count++) {
    int randomNumber = random(16);
    for (int i = 4; i != 0; i--) {
      digitalWrite(layer[i - 1], 1);
      for (int i = 4; i != 0; i--) {
        digitalWrite(column[randomNumber - 1], 0);
        delay(time);
        turnEverythingOff();
      }
    }
  }
}
//column run====================================================
void columnRun() {

  int time = 30;
  turnEverythingOff();

  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], 1);
  }
  //column side1
  for (int count = 0; count < 15; count++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(column[i], 0);
      delay(time);
      digitalWrite(column[i], 1);
      delay(time);
    }
  }

  for (int count = 0; count < 15; count++) {
    for (int i = 4; i < 8; i++) {
      digitalWrite(column[i], 0);
      delay(time);
      digitalWrite(column[i], 1);
      delay(time);
    }
  }
  for (int count = 0; count < 15; count++) {
    for (int i = 8; i < 12; i++) {
      digitalWrite(column[i], 0);
      delay(time);
      digitalWrite(column[i], 1);
      delay(time);
    }
  }
  for (int count = 0; count < 15; count++) {
    for (int i = 12; i < 16; i++) {
      digitalWrite(column[i], 0);
      delay(time);
      digitalWrite(column[i], 1);
      delay(time);
    }
  }
  delay(800);
}
//square movement====================================================
void squareMovement() {
  int time = 300;
  turnEverythingOff();

  //square increment1
  for (int i = 0; i < 2; i++) {
    digitalWrite(layer[i], 1);
    for (int i = 0; i < 16; i++) {
      if (i == 0 || i == 1 || i == 4 || i == 5) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);

  for (int i = 0; i < 3; i++) {
    digitalWrite(layer[i], 1);
    for (int i = 0; i < 16; i++) {
      if (i == 0 || i == 1 || i == 2 || i == 4 || i == 6 || i == 8 || i == 9 || i == 10) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }

  delay(time);

  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], 1);
    for (int i = 0; i < 16; i++) {
      if (i != 5 && i != 6 && i != 9 && i != 10) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);

  turnEverythingOff();

  //square decrement1
  for (int i = 3; i != 0; i--) {
    digitalWrite(layer[i - 1], 1);
    for (int i = 0; i < 16; i++) {
      if ( i == 5 || i == 6 || i == 7 || i == 9 || i == 11 || i == 13 || i == 14 || i == 15) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);
  turnEverythingOff();
  for (int i = 2; i != 0; i--) {
    digitalWrite(layer[i - 1], 1);
    for (int i = 0; i < 16; i++) {
      if (i == 10 || i == 11 || i == 14 || i == 15) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);

  turnEverythingOff();
  //square increment2
  for (int i = 0; i < 2; i++) {
    digitalWrite(layer[i], 1);
    for (int i = 0; i < 16; i++) {
      if (i == 8 || i == 9 || i == 12 || i == 13) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);

  for (int i = 0; i < 3; i++) {
    digitalWrite(layer[i], 1);
    for (int i = 0; i < 16; i++) {
      if (i == 4 || i == 5 || i == 6 || i == 8 || i == 10 || i == 12 || i == 13 || i == 14) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }

  delay(time);

  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], 1);
    for (int i = 0; i < 16; i++) {
      if (i != 5 && i != 6 && i != 9 && i != 10) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);

  turnEverythingOff();

  //square decrement2
  for (int i = 3; i != 0; i--) {
    digitalWrite(layer[i - 1], 1);
    for (int i = 0; i < 16; i++) {
      if ( i == 1 || i == 2 || i == 3 || i == 5 || i == 7 || i == 9 || i == 10 || i == 11) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);
  turnEverythingOff();
  for (int i = 2; i != 0; i--) {
    digitalWrite(layer[i - 1], 1);
    for (int i = 0; i < 16; i++) {
      if (i == 2 || i == 3 || i == 6 || i == 7) {
        digitalWrite(column[i], 0);
      } else {
        digitalWrite(column[i], 1);
      }
    }
  }
  delay(time);
}
//rain reverse====================================================
void rainReverse() {
  turnEverythingOff();
  int time = 20;
  //count
  for (int count = 0; count < 80; count++) {
    int randomNumber = random(16);
    for (int i = 0; i < 4; i++) {
      digitalWrite(layer[i], 1);
      digitalWrite(column[randomNumber], 0);
      delay(time);
      turnEverythingOff();
    }
  }
}
//dispersion====================================================
void dispersion() {
  int randomNumberColumn;
  int randomNumberLayer;
  int time = 20;
  
  turnEverythingOff();
  for (int i = 0; i < 100; i++) {
    randomNumberColumn = random(16);
    randomNumberLayer = random(4);
    digitalWrite(layer[randomNumberLayer], 1);
    digitalWrite(column[randomNumberColumn], 0);
    delay(time);
    digitalWrite(layer[randomNumberLayer], 0);
    digitalWrite(column[randomNumberColumn], 1);
    delay(time);
  }

}
