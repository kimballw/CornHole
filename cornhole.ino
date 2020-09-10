/*
 * Corn Hole
 * For the St. George Children's Museum
 * by Kimball Willard (kimballw@gloininteractive.com)
 * 
 * Expected to be run on and Android UNO
 * Uses 4 PIR sensors
 * Uses 2 Relays
 * Uses 2 ED402-117-4D-N1 Score Boards by electronicdisplays.com controlled over serial RS-485
 *   Set to Channels 02 and 03
 */
#include <SoftwareSerial.h>

SoftwareSerial secondSerial(3, 2); // RX, TX

const int PIR1 = 4;
const int PIR2 = 5;
const int PIR3 = 6;
const int PIR4 = 7;

const int RELAY1 = 8;
const int RELAY2 = 9;

const int RESET = 10;

const int hole1Score = 15;
const int hole2Score = 10;
const int hole3Score = 5;
const int hole4Score = 5;

int score1 = 0;
int score2 = 0;

int playerTurn = 1;

void setup() {
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT);
  pinMode(PIR3, INPUT);
  pinMode(PIR4, INPUT);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  pinMode(RESET, INPUT);

  Serial.begin(9600);
  secondSerial.begin(9600);
}

void showSingleDigit(int digit, int serial) {
  switch (digit) {
    case 0:
      if (serial == 1) {
        Serial.write(0x30);
      } else {
        secondSerial.write(0x30);
      }
      break;
    case 1:
      if (serial == 1) {
        Serial.write(0x31);
      } else {
        secondSerial.write(0x31);
      }
      break;
    case 2:
      if (serial == 1) {
        Serial.write(0x32);
      } else {
        secondSerial.write(0x32);
      }
      break;
    case 3:
      if (serial == 1) {
        Serial.write(0x33);
      } else {
        secondSerial.write(0x33);
      }
      break;
    case 4:
      if (serial == 1) {
        Serial.write(0x34);
      } else {
        secondSerial.write(0x34);
      }
      break;
    case 5:
      if (serial == 1) {
        Serial.write(0x35);
      } else {
        secondSerial.write(0x35);
      }
      break;
    case 6:
      if (serial == 1) {
        Serial.write(0x36);
      } else {
        secondSerial.write(0x36);
      }
      break;
    case 7:
      if (serial == 1) {
        Serial.write(0x37);
      } else {
        secondSerial.write(0x37);
      }
      break;
    case 8:
      if (serial == 1) {
        Serial.write(0x38);
      } else {
        secondSerial.write(0x38);
      }
      break;
    case 9:
      if (serial == 1) {
        Serial.write(0x39);
      } else {
        secondSerial.write(0x39);
      }
      break;
  }
}

void showTens(int digit, int serial) {
  if (digit <= 99 && digit >= 90 && serial == 1) {
    Serial.write(0x39);
  } else if (digit <= 99 && digit >= 90 && serial == 2) {
    secondSerial.write(0x39);
  } else if (digit <= 89 && digit >= 80 && serial == 1) {
    Serial.write(0x38);
  } else if (digit <= 89 && digit >= 80 && serial == 2) {
    secondSerial.write(0x38);
  } else if (digit <= 79 && digit >= 70 && serial == 1) {
    Serial.write(0x37);
  } else if (digit <= 79 && digit >= 70 && serial == 2) {
    secondSerial.write(0x37);
  } else if (digit <= 69 && digit >= 60 && serial == 1) {
    Serial.write(0x36);
  } else if (digit <= 69 && digit >= 60 && serial == 2) {
    secondSerial.write(0x36);
  } else if (digit <= 59 && digit >= 50 && serial == 1) {
    Serial.write(0x35);
  } else if (digit <= 59 && digit >= 50 && serial == 2) {
    secondSerial.write(0x35);
  } else if (digit <= 49 && digit >= 40 && serial == 1) {
    Serial.write(0x34);
  } else if (digit <= 49 && digit >= 40 && serial == 2) {
    secondSerial.write(0x34);
  } else if (digit <= 39 && digit >= 30 && serial == 1) {
    Serial.write(0x33);
  } else if (digit <= 39 && digit >= 30 && serial == 2) {
    secondSerial.write(0x33);
  } else if (digit <= 29 && digit >= 20 && serial == 1) {
    Serial.write(0x32);
  } else if (digit <= 29 && digit >= 20 && serial == 2) {
    secondSerial.write(0x32);
  } else if (digit <= 19 && digit >= 10 && serial == 1) {
    Serial.write(0x31);
  } else if (digit <= 19 && digit >= 10 && serial == 2) {
    secondSerial.write(0x31);
  }
}

void showHundreds(int digit, int serial) {
  if (digit <= 999 && digit >= 900 && serial == 1) {
    Serial.write(0x39);
  } else if (digit <= 999 && digit >= 900 && serial == 2) {
    secondSerial.write(0x39);
  } else if (digit <= 899 && digit >= 800 && serial == 1) {
    Serial.write(0x38);
  } else if (digit <= 899 && digit >= 800 && serial == 2) {
    secondSerial.write(0x38);
  } else if (digit <= 799 && digit >= 700 && serial == 1) {
    Serial.write(0x37);
  } else if (digit <= 799 && digit >= 700 && serial == 2) {
    secondSerial.write(0x37);
  } else if (digit <= 699 && digit >= 600 && serial == 1) {
    Serial.write(0x36);
  } else if (digit <= 699 && digit >= 600 && serial == 2) {
    secondSerial.write(0x36);
  } else if (digit <= 599 && digit >= 500 && serial == 1) {
    Serial.write(0x35);
  } else if (digit <= 599 && digit >= 500 && serial == 2) {
    secondSerial.write(0x35);
  } else if (digit <= 499 && digit >= 400 && serial == 1) {
    Serial.write(0x34);
  } else if (digit <= 499 && digit >= 400 && serial == 2) {
    secondSerial.write(0x34);
  } else if (digit <= 399 && digit >= 300 && serial == 1) {
    Serial.write(0x33);
  } else if (digit <= 399 && digit >= 300 && serial == 2) {
    secondSerial.write(0x33);
  } else if (digit <= 299 && digit >= 200 && serial == 1) {
    Serial.write(0x32);
  } else if (digit <= 299 && digit >= 200 && serial == 2) {
    secondSerial.write(0x32);
  } else if (digit <= 199 && digit >= 100 && serial == 1) {
    Serial.write(0x31);
  } else if (digit <= 199 && digit >= 100 && serial == 2) {
    secondSerial.write(0x31);
  }
}

void showThousands(int digit, int serial) {
  if (digit <= 9999 && digit >= 9000 && serial == 1) {
    Serial.write(0x39);
  } else if(digit <= 9999 && digit >= 9000 && serial == 2) {
    secondSerial.write(0x39);
  } else if(digit <= 8999 && digit >= 8000 && serial == 1) {
    Serial.write(0x38);
  } else if(digit <= 8999 && digit >= 8000 && serial == 2) {
    secondSerial.write(0x38);
  } else if(digit <= 7999 && digit >= 7000 && serial == 1) {
    Serial.write(0x37);
  } else if(digit <= 7999 && digit >= 7000 && serial == 2) {
    secondSerial.write(0x37);
  } else if(digit <= 6999 && digit >= 6000 && serial == 1) {
    Serial.write(0x36);
  } else if(digit <= 6999 && digit >= 6000 && serial == 2) {
    secondSerial.write(0x36);
  } else if(digit <= 5999 && digit >= 5000 && serial == 1) {
    Serial.write(0x35);
  } else if(digit <= 5999 && digit >= 5000 && serial == 2) {
    secondSerial.write(0x35);
  } else if(digit <= 4999 && digit >= 4000 && serial == 1) {
    Serial.write(0x34);
  } else if(digit <= 4999 && digit >= 4000 && serial == 2) {
    secondSerial.write(0x34);
  } else if(digit <= 3999 && digit >= 3000 && serial == 1) {
    Serial.write(0x33);
  } else if(digit <= 3999 && digit >= 3000 && serial == 2) {
    secondSerial.write(0x33);
  } else if(digit <= 2999 && digit >= 2000 && serial == 1) {
    Serial.write(0x32);
  } else if(digit <= 2999 && digit >= 2000 && serial == 2) {
    secondSerial.write(0x32);
  } else if(digit <= 1999 && digit >= 1000 && serial == 1) {
    Serial.write(0x31);
  } else if(digit <= 1999 && digit >= 1000 && serial == 2) {
    secondSerial.write(0x31);
  }
}

void clearScreen(int serial) {
  if (serial == 1) {
    Serial.write(0x20);
    Serial.write(0x20);
    Serial.write(0x20);
    Serial.write(0x20);
  } else {
    secondSerial.write(0x20);
    secondSerial.write(0x20);
    secondSerial.write(0x20);
    secondSerial.write(0x20);
  }
}

void numberToHex(int digit, int serial) {
  if (digit > 9999) {
    // Number is to high for display
    if (serial == 1) {
      Serial.write(0x39);
      Serial.write(0x39);
      Serial.write(0x39);
      Serial.write(0x39);
    } else {
      secondSerial.write(0x39);
      secondSerial.write(0x39);
      secondSerial.write(0x39);
      secondSerial.write(0x39);
    }
  } else if (digit > 999) {
    //Serial.println("Thousands");
    Serial.println(digit);
    showThousands(digit, serial);
    int hundreds = digit;
    while (hundreds > 999) {
      hundreds = hundreds - 1000;
    }
    Serial.println(hundreds);
    showHundreds(hundreds, serial);
    int tens = hundreds;
    while (tens > 99) {
      tens = tens - 10;
    }
    Serial.println(tens);
    showTens(tens, serial);
    int single = tens;
    while (single > 9) {
      single = single - 10;
    }
    Serial.println(single);
    showSingleDigit(single, serial);
  } else if (digit > 99) {
    //Serial.println("Hundreds");
    if (serial == 1 ) {
      Serial.write(0x20);
    } else {
      secondSerial.write(0x20);
    }
    Serial.println(digit);
    showHundreds(digit, serial);
    int tens = digit;
    while (tens > 99) {
      tens = tens - 10;
    }
    Serial.println(tens);
    showTens(tens, serial);
    int single = tens;
    while (single > 9) {
      single = single - 10;
    }
    Serial.println(single);
    showSingleDigit(single, serial);
  } else if (digit > 9) {
    //Serial.println("Tens");
    if (serial == 1) {
      Serial.write(0x20);
      Serial.write(0x20);
    } else {
      secondSerial.write(0x20);
      secondSerial.write(0x20);
    }
    Serial.println(digit);
    showTens(digit, serial);
    int single = digit;
    while (single > 9) {
      single = single - 10;
    }
    Serial.println(single);
    showSingleDigit(single, serial);
  } else {
    //Serial.println("Single");
    if (serial == 1) {
      Serial.write(0x20);
      Serial.write(0x20);
      Serial.write(0x20);
    } else {
      secondSerial.write(0x20);
      secondSerial.write(0x20);
      secondSerial.write(0x20);
    }
    Serial.println(digit);
    showSingleDigit(digit, serial);
  }
}

void writeLCDHeader(int serial) {
  if (serial == 1) {
    Serial.write(0x02); // Start of text (ctrl-B)
    Serial.write(0x30); // Tens digit of channel
    Serial.write(0x31); // Singles digit of channel (together, 01)
  } else {
    secondSerial.write(0x02); // Start of text (ctrl-B)
    secondSerial.write(0x30); // Tens digit of channel
    secondSerial.write(0x32); // Singles digit of channel (together, 02)
  }
}

void timerSwitch(int timer, int serial) {
  switch (timer) {
      case 0:
        if (serial == 1) {
          Serial.write(0x30);
          Serial.write(0x30);
          Serial.write(0x30);
          Serial.write(0x30);
        } else {
          secondSerial.write(0x30);
          secondSerial.write(0x30);
          secondSerial.write(0x30);
          secondSerial.write(0x30);
        }
        break;
      case 1:
        if (serial == 1) {
          Serial.write(0x31);
          Serial.write(0x31);
          Serial.write(0x31);
          Serial.write(0x31);
        } else {
          secondSerial.write(0x31);
          secondSerial.write(0x31);
          secondSerial.write(0x31);
          secondSerial.write(0x31);
        }
        break;
      case 2:
        if (serial == 1) {
          Serial.write(0x32);
          Serial.write(0x32);
          Serial.write(0x32);
          Serial.write(0x32);
        } else {
          secondSerial.write(0x32);
          secondSerial.write(0x32);
          secondSerial.write(0x32);
          secondSerial.write(0x32);
        }
        break;
      case 3:
        if (serial == 1) {
          Serial.write(0x33);
          Serial.write(0x33);
          Serial.write(0x33);
          Serial.write(0x33);
        } else {
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
        }
        break;
      case 4:
        if (serial == 1) {
          Serial.write(0x34);
          Serial.write(0x34);
          Serial.write(0x34);
          Serial.write(0x34);
        } else {
          secondSerial.write(0x34);
          secondSerial.write(0x34);
          secondSerial.write(0x34);
          secondSerial.write(0x34);
        }
        break;
      case 5:
        if (serial == 1) {
          Serial.write(0x35);
          Serial.write(0x35);
          Serial.write(0x35);
          Serial.write(0x35);
        } else {
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
        }
        break;
      case 6:
        if (serial == 1) {
          Serial.write(0x36);
          Serial.write(0x36);
          Serial.write(0x36);
          Serial.write(0x36);
        } else {
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
        }
        break;
      case 7:
        if (serial == 1) {
          Serial.write(0x37);
          Serial.write(0x37);
          Serial.write(0x37);
          Serial.write(0x37);
        } else {
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
        }
        break;
      case 8:
        if (serial == 1) {
          Serial.write(0x38);
          Serial.write(0x38);
          Serial.write(0x38);
          Serial.write(0x38);
        } else {
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
        }
        break;
      case 9:
        if (serial == 1) {
          Serial.write(0x39);
          Serial.write(0x39);
          Serial.write(0x39);
          Serial.write(0x39);
        } else {
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
          secondSerial.write(0x33);
        }
        break;
    }
}

void resetGame() {
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  int timer = 9;
  while (timer >= 0) {
    writeLCDHeader(1);
    timerSwitch(timer, 1);
    Serial.write(0x03); // End of text (ctrl-C)

    writeLCDHeader(2);
    timerSwitch(timer, 2);
    secondSerial.write(0x03); // End of text (ctrl-C)
    
    delay(500);
    timer = timer - 1;
  }
  digitalWrite(RELAY1, HIGH);
  playerTurn = 1;
  
  score1 = 0;
  writeLCDHeader(1);
  numberToHex(score1, 1);
  Serial.write(0x03); // End of text (ctrl-C)
  
  score2 = 0;
  writeLCDHeader(2);
  numberToHex(score2, 2);
  secondSerial.write(0x03); // End of text (ctrl-C)
}

void scoreFunction(int val, int score) {
  if (playerTurn == 1) {
    score1 = score1 + score;
    
    writeLCDHeader(1);
    numberToHex(score1, 1);
    Serial.write(0x03); // End of text (ctrl-C)

    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, HIGH);
    playerTurn = 2;
  } else {
    score2 = score2 + score;

    writeLCDHeader(2);
    numberToHex(score2, 2);
    secondSerial.write(0x03); // End of text (ctrl-C)
    
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, LOW);
    playerTurn = 1;
  }
}

void loop() {
  int val1 = digitalRead(PIR1);
  int val2 = digitalRead(PIR2);
  int val3 = digitalRead(PIR3);
  int val4 = digitalRead(PIR4);
  int reset = digitalRead(RESET);
  
  if (val1 == HIGH) {
    scoreFunction(val1, hole1Score);
  } else if (val2 == HIGH) {
    scoreFunction(val2, hole2Score);
  } else if (val3 == HIGH) {
    scoreFunction(val3, hole3Score);
  } else if (val4 == HIGH) {
    scoreFunction(val4, hole4Score);
  } else if (reset == HIGH) {
    resetGame();
  }

  Serial.print("Player 1 - ");
  Serial.print(score1);
  Serial.print(", Player 2 - ");
  Serial.println(score2);
  delay(500);
}
