#include <Arduino.h>

int COLUMNS[10] = {3, 4, 5, 23, 22, 13, 14, 24, 27, 17};
int ROWS[11] = {25, 28, 29, 10, 11, 12, 16, 21, 20, 19, 18};



void setup() {
  Serial.begin(115200);

  for(int COL : COLUMNS) {
    pinMode(COL, OUTPUT);
  }
  for(int ROW : ROWS) {
    pinMode(ROW, OUTPUT);
  }
}

void loop() {
  for (int COL : COLUMNS) {
    digitalWrite(COL, LOW);
    for (int ROW :ROWS) {
      for(int i; i <= 1000; i++) {
        digitalWrite(ROW, HIGH);
        delay(1);
        digitalWrite(ROW, LOW);
        delay(1);
      }
    }
  }
}