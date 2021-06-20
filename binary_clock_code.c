#include <MyRealTimeClock.h>

int d11 = A5;
int d12 = A1;
int d21 = A4;
int d22 = A0;
int d23 = 7;
int d24 = 10;
int d31 = A3;
int d32 = 5;
int d33 = 8;
int d41 = A2;
int d42 = 6;
int d43 = 9;
int d44 = 11;


MyRealTimeClock myRTC(2, 3, 4);


void setup() {
  Serial.begin(9600);
  myRTC.setDS1302Time(50, 57, 18, 4 , 12, 06, 2021);
  pinMode(d11, OUTPUT);
  pinMode(d12, OUTPUT);
  pinMode(d21, OUTPUT);
  pinMode(d22, OUTPUT);
  pinMode(d23, OUTPUT);
  pinMode(d24, OUTPUT);
  pinMode(d31, OUTPUT);
  pinMode(d32, OUTPUT);
  pinMode(d33, OUTPUT);
  pinMode(d41, OUTPUT);
  pinMode(d42, OUTPUT);
  pinMode(d43, OUTPUT);
  pinMode(d44, OUTPUT);
}

int mytime[4][4] = {0};
void show_time(int minutes, int hours){
  int c = (minutes / 10);
  int d = (minutes % 10);
  int a = (hours / 10);
  int b = (hours % 10);
  for(int i = 0;i < 2;i++){
    mytime[0][i] = a % 2;
    Serial.print(mytime[0][i]);
    a /= 2;
  }
  Serial.println();
  for(int i = 0;i < 4;i++){
    mytime[1][i] = b % 2;
    Serial.print(mytime[1][i]);
    b /= 2;
  }
  Serial.println();
  for(int i = 0;i < 3;i++){
    mytime[2][i] = c % 2;
    Serial.print(mytime[2][i]);
    c /= 2;
  }
  Serial.println();
  for(int i = 0;i < 4;i++){
    mytime[3][i] = d % 2;
    Serial.print(mytime[3][i]);
    d /= 2;
  }
  Serial.println();
  
}

void hide_time(){
  for(int i = 0;i < 4;i++){
    for(int j = 0;j < 4;j++){
      mytime[i][j] = 0;
    }
  }
}

/*
[][]
[][][][]
[][][]
[][][][]
*/
void check_print();

void loop() {
  myRTC.updateTime();
  show_time(myRTC.minutes, myRTC.hours);
  check_print();
  hide_time();
}




void check_print(){
  digitalWrite(d11, mytime[0][0]);
  digitalWrite(d12, mytime[0][1]);
  digitalWrite(d21, mytime[1][0]);
  digitalWrite(d22, mytime[1][1]);
  digitalWrite(d23, mytime[1][2]);
  digitalWrite(d24, mytime[1][3]);
  digitalWrite(d31, mytime[2][0]);
  digitalWrite(d32, mytime[2][1]);
  digitalWrite(d33, mytime[2][2]);
  digitalWrite(d41, mytime[3][0]);
  digitalWrite(d42, mytime[3][1]);
  digitalWrite(d43, mytime[3][2]);
  digitalWrite(d44, mytime[3][3]);
  delay(100);
  digitalWrite(d11, LOW);
  digitalWrite(d12, LOW);
  digitalWrite(d21, LOW);
  digitalWrite(d22, LOW);
  digitalWrite(d23, LOW);
  digitalWrite(d24, LOW);
  digitalWrite(d31, LOW);
  digitalWrite(d32, LOW);
  digitalWrite(d33, LOW);
  digitalWrite(d41, LOW);
  digitalWrite(d42, LOW);
  digitalWrite(d43, LOW);
  digitalWrite(d44, LOW);
}
