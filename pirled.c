/* import lause kirjastolle*/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void nollaa (){
  digitalWrite(5, 0);
  digitalWrite(20, 0);
}


void main () {
  /* alusta BCM numeroinnille */
  wiringPiSetupGpio();
  atexit(nollaa);

  /* pinnien määritys */
  pinMode(20, INPUT);
  pinMode(5, OUTPUT);

  int pollingDelay = 100;

  /* virtaa pinnille 27 */
  

  /* luetaan pinniä 4 */
  while (1){
    if(digitalRead(20))
      digitalWrite(5, HIGH);
    else
      digitalWrite(5, LOW);
#ifdef _WIN32
    Sleep(pollingDelay);
#else
    usleep(pollingDelay*1000);  /* sleep for 100 milliSeconds */
#endif
  }

//käännös -l wiringPi
}
