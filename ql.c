#include <stdlib.h>
#include "HC89F0541.h"

sx8 rewards [8][8] =
  { 
   {-1, 0, 0, -1, -1, -1, -1, -1},
   {0, -1, -1, 0, -1, -1, -1, -1},
   {0, -1, -1, -1, 0, -1, -1, -1},
   {-1, 0, -1, -1, -1, 0, -1, -1},
   {-1, -1, 0, -1, -1, 0, 90, -1},
   {-1, -1, -1, 0, 0, -1, -1, 0},
   {-1, -1, -1, -1, -1, -1, -1, -1},
   {-1, -1, -1, -1, -1, 0, 100, -1}
  };

sx8 weights [8][8] = 
 {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
 };

int cuarto1 = 4;
int cuarto2 = 11;
int cuarto3 = 5;
int cuarto4 = 10;
int cuarto5 = 6;
int cuarto6 = 9;
int cuarto7 = 7;
int cuarto8 = 8;

int currentRoom = 0;
int target = 6;
int action = 0;
int num_random = 0;
int num_max = 0;
int n=0;
int index = 0;
int sound = 10;

void digitalWrite(int x, int y){
	
}

void turnOn(){
//      digitalWrite(cuarto1, HIGH);
//      digitalWrite(cuarto2, HIGH);
//      digitalWrite(cuarto3, HIGH);
//      digitalWrite(cuarto4, HIGH);
//      digitalWrite(cuarto5, HIGH);
//      digitalWrite(cuarto6, HIGH);
//      digitalWrite(cuarto7, HIGH);
//      digitalWrite(cuarto8, HIGH);
}

void turnOff(){
//      digitalWrite(cuarto1, LOW);
//      digitalWrite(cuarto2, LOW);
//      digitalWrite(cuarto3, LOW);
//      digitalWrite(cuarto4, LOW);
//      digitalWrite(cuarto5, LOW);
//      digitalWrite(cuarto6, LOW);
//      digitalWrite(cuarto7, LOW);
//      digitalWrite(cuarto8, LOW);
}
void room(int n){
//  switch(n){
//    case 0:
//      turnOff();
//      digitalWrite(cuarto1, HIGH);
//      break;
//    case 1:
//      turnOff();
//      digitalWrite(cuarto2, HIGH);
//      break;
//    case 2:
//      turnOff();
//      digitalWrite(cuarto3, HIGH);
//      break;
//    case 3:
//      turnOff();
//      digitalWrite(cuarto4, HIGH);
//      break;
//     case 4:
//      turnOff();
//      digitalWrite(cuarto5, HIGH);
//      break;
//     case 5:
//      turnOff();
//      digitalWrite(cuarto6, HIGH);
//      break;
//     case 6:
//      turnOff();
//      digitalWrite(cuarto7, HIGH);
//      break;
//     case 7:
//      turnOff();
//      digitalWrite(cuarto8, HIGH);
//      break;
//  }
}
//void setup() {
//  pinMode(cuarto1,OUTPUT);
//  pinMode(cuarto2,OUTPUT);
//  pinMode(cuarto3,OUTPUT);
//  pinMode(cuarto4,OUTPUT);
//  pinMode(cuarto5,OUTPUT);
//  pinMode(cuarto6,OUTPUT);
//  pinMode(cuarto7,OUTPUT);
//  pinMode(cuarto8,OUTPUT);
//  pinMode(sound,OUTPUT);
//}

void delay(int t){
}

void main() {
  int i;
  while(n < 60){ 
    while(currentRoom != target){ 
        room(currentRoom);
        num_random = rand()%7;
        while(rewards[currentRoom][num_random] < 0){
          num_random = rand()%7;
        }
        action = num_random;
        num_max = weights[action][0]; 
        for(i=1; i<8; i++){ 
          if(weights[action][i] > num_max){
             num_max = weights[action][i];
          }
        }
        weights[currentRoom][action] = rewards[currentRoom][action] + 0.8 * num_max;
        currentRoom = action;
        delay(400);
    }
    room(target);
    delay(400);
    n++;
    currentRoom=0;
//    for(i =0; i<2; i++){
//       turnOff();
////       digitalWrite(sound,LOW);
//       delay(500);
//       turnOn();
////       digitalWrite(sound,HIGH);
//       delay(500);
//    }
////    digitalWrite(sound,LOW);
  }

//  for(i =0; i<4; i++){
//     turnOff();
////     digitalWrite(sound,LOW);
//     delay(1000);
//     turnOn();
////     digitalWrite(sound,HIGH);
//     delay(1000);
//  }
////  digitalWrite(sound,LOW);


  currentRoom = 0;
  while(currentRoom != target){
     room(currentRoom);
     num_max = weights[currentRoom][0]; 
     index = 0;
     for(i=1; i<8; i++){ 
        if(weights[currentRoom][i] > num_max){
             num_max = weights[currentRoom][i];
             index = i;
        }
     }
     currentRoom = index;
     delay(1000);   
  }
  room(target);
  delay(10000);
}
