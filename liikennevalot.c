/* import lause kirjastolle*/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void mySleep(int x){
#ifdef _WIN32
    Sleep(x);
#else
    usleep(x*1000);  
#endif
}

void nollaa(){
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(13, 0);

  digitalWrite(18, 0);
  digitalWrite(19, 0);

  digitalWrite(20, 0);
}

void stateTesti(){
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(13, HIGH);

  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
}

void stateRed(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void stateYellow(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
}

void stateGreen(){
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
}

void stateGreenYellow(){
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
}

void stateWalkersGreen(){
  digitalWrite(19, HIGH);
  digitalWrite(18, LOW);  
}

void stateWalkersRed(){
  digitalWrite(18, HIGH);
  digitalWrite(19, LOW);  
}

void notifierOff(){
  digitalWrite(13, LOW);
}

void notifierOn(){
  digitalWrite(13, HIGH);
}

void walkersWalk(){
  stateYellow();
  mySleep(2000);
  stateRed();
  mySleep(2000);
  stateWalkersGreen();
  mySleep(4000);
  stateWalkersRed();
  notifierOff();
}


void gameLoop(){

  stateWalkersRed();
  stateRed();
  
  int phaseTime = 2000;
  _Bool pedestriansWaiting = 0;
  _Bool carsWaiting = 1;
  _Bool carsDriving = 0;

  while(1){
    if(phaseTime == 0){
      if (carsWaiting == 1){
	phaseTime = 2000;
	stateGreenYellow();
	carsWaiting = 0;
	carsDriving = 0;
      }else if (pedestriansWaiting == 0 || carsDriving == 0){
	stateGreen();
	phaseTime = 4000;
	carsDriving = 1;
      }else if (pedestriansWaiting == 1){
	carsWaiting = 1;
	pedestriansWaiting = 0;
	carsDriving == 0;
	walkersWalk();
	phaseTime = 2000;
      }

    }
      
    if(digitalRead(20)){
      pedestriansWaiting = 1;
      notifierOn();
    }
    mySleep(1);
    phaseTime = phaseTime-1;
  }
}

void main () {
  /* alusta BCM numeroinnille */
  wiringPiSetupGpio();
  atexit(nollaa);

  /* pinnien määritys */
  pinMode(20, INPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

  stateTesti();
  gameLoop();
}
