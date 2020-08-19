/*
 * Corn Hole
 * For the St. George Children's Museum
 * by Kimball Willard (kimballw@gloininteractive.com)
 * 
 * Expected to be run on and Android UNO
 * Uses 4 PIR sensors
 * Uses 2 Relays
 * Uses 2 ED402-117-4D-N1 Score Boards by electronicdisplays.com controlled over serial RS-485
 */

int PIR1 = 2;
int PIR2 = 3;
int PIR3 = 4;
int PIR4 = 5;

int hole1Score = 10;
int hole2Score = 20;
int hole3Score = 30;
int hole4Score = 40;

int RELAY1 = 8;
int RELAY2 = 9;

int RESET = 7;

String ADDRESS1 = "01";
String ADDRESS2 = "02";

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
}

void loop() {
  val1 = digitalRead(PIR1);
  val2 = digitalRead(PIR2);
  val3 = digitalRead(PIR3);
  val4 = digitalRead(PIR4);
  if (val1 == HIGH) {
    scoreFunction(val1, hole1Score);
  } else if (val2 == HIGH) {
    scoreFunction(val2, hole2Score);
  } else if (val3 == HIGH) {
    scoreFunction(val3, hole3Score);
  } else if (val4 == HIGH) {
    scoreFunction(val4, hole4Score);
  }

  Serial.println("Player 1 - " + score1 + ", Player 2 - " + score2);
  delay(500);
}

void scoreFunction(int val, int score) {
  if (playerTurn == 1) {
    score1 = score1 + score;
    playerTurn = 2;
  } else {
    score2 = score2 + score;
    playerTurn = 1;
  }
}
