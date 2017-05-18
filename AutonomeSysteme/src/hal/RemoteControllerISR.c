/*

Remote Controller ISR

TO-DO: 
  - Timer overflow erkennen und behandeln
  -

*/
#include <time.h>
#include <stdio.h>
#include <wiringPi.h>

// timespec.tv_nsec Zurgriff auf Nanosekunden
struct timespec startTime[4];
long deltaTime[4];
int isrTriggered = 0 ;


void risingEdgeInterruptChannel1 (void) {
  clock_gettime (CLOCK_REALTIME, &startTime[0]);
}

void risingEdgeInterruptChannel2 (void) {
  clock_gettime (CLOCK_REALTIME, &startTime[1]) ;
  deltaTime[0] = startTime[1].tv_nsec - startTime[0].tv_nsec;
}

void risingEdgeInterruptChannel3 (void) {
  clock_gettime (CLOCK_REALTIME, &startTime[2]) ;
  deltaTime[1] = startTime[2].tv_nsec - startTime[1].tv_nsec;
}

void risingEdgeInterruptChannel4 (void) {
  clock_gettime (CLOCK_REALTIME, &startTime[3]) ;
  deltaTime[2] = startTime[3].tv_nsec - startTime[2].tv_nsec;
}

void fallingEdgeInterruptChannel4 (void) {
  struct timespec endTimeChannel4;
  clock_gettime (CLOCK_REALTIME, &endTimeChannel4);
  deltaTime[3] = (endTimeChannel4.tv_nsec - startTime[3].tv_nsec) ;
  isrTriggered = 1 ;
}

void ISRThread(void) {
  // Setup interrupts
  wiringPiSetup () ;  
  wiringPiISR (0, INT_EDGE_RISING, &risingEdgeInterruptChannel1) ;
  wiringPiISR (1, INT_EDGE_RISING, &risingEdgeInterruptChannel2) ;
  wiringPiISR (2, INT_EDGE_RISING, &risingEdgeInterruptChannel3) ;
  wiringPiISR (3, INT_EDGE_RISING, &risingEdgeInterruptChannel4) ;
  wiringPiISR (4, INT_EDGE_FALLING, &fallingEdgeInterruptChannel4) ;
  
  for(;;) {
    if(isrTriggered == 1) {
      isrTriggered = 0 ;
      printf ("Channel 1: %ld\t Channel 2: %ld \t Channel 3: %ld\t Channel 4: %ld\n", 
	deltaTime[0] / 10000 - 100, deltaTime[1] / 10000 - 100, deltaTime[2] / 10000 - 100 , deltaTime[3] / 10000 - 100 ) ; 
    }
  } 
}
