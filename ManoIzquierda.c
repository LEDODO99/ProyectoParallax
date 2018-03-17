
#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()                                    // Main function
{
  int leftBlocked=0;
  int rightBlocked=0;
  int frontBlocked=0;
  // Add startup code here.

  srand(time(NULL));
 
  while(1)
  {
    leftBlocked=checkLeft();
    if (leftBlocked==0){
      turnLeft();
    }else{
      frontBlocked=checkFront();
      if (frontBlocked==0){
      }else{
        rightBlocked=checkRight();
        if(rightBlocked==0){
          turnRight();
        }else{
          turnArround();
        }                    
      }                
    }  
    move();             
  }
  drive_speed(0,0);  
} 


void turnRight(void){
  drive_speed(26,-26);
  pause(1000);
  drive_speed(0,0);
}

void move(void){
  drive_speed(64,64);
  pause(1000);
  drive_speed(0,0);
}
void turnLeft(void){
  drive_speed(-26,26);
  pause(1000);
  drive_speed(0,0);
}

void turnArround(void){
  drive_speed(-52,52);
  pause(1000);
  drive_speed(0,0);
}  
int checkLeft(void){
  turnLeft();
  int leftBlocked=0;
  if(ping_cm(8)<=15){
    leftBlocked=1;
  }
  turnRight();
  return leftBlocked;
    
}
int checkRight(void){
  turnRight();
  int leftBlocked=0;
  if(ping_cm(8)<=15){
    leftBlocked=1;
  }
  turnLeft();
  return leftBlocked;
}
int checkFront(void){
  int frontBlocked=0;
  if(ping_cm(8)<=15){
    frontBlocked=1;
  }  
  return frontBlocked;
}  
