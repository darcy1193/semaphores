
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "processes.h"

// each process
void Process (sem_t * screen, sem_t * keyboard, int index){
//   // sem_open both semaphores if necessary
	int count = 0;
 	pid_t id = getpid();
	bool quit = 0;
	printf("\nworking\n");

	do{		//loop
			//printf("\nworking\n");
// 	   count += getSemaphores(index)
//   	 prompt id + " enter < 80 characters " + id + " or q to quit: "
//   	 read keboard
//   	 echo what was typed with id before and after echo
// 		 echo id + " start " + what was typed + id + " end"
// 	   sem_post or give back both semaphores
// 	until quit end inner loop in C do ... while not q
}while(!quit);

// 	count += getSemaphores(index)
// 	 prompt "This process " + id + " had " + count + " deadlocks "
// 	 sem_post or give back both semaphores
// sem_close
// exit
}


//	function to get semaphores (screen, keyboard, index)
//   returns count of how many times recovered from deadlock
//   odd index gets screen first
//   even index gets keyboard first
int getSemaphores (sem_t *screen, sem_t *keyboard, int index){

	int count = 0;
	bool both = 0;

	struct timespec ts_timer;		//normalize
	ts_timer.tv_nsec += 100000000;
	ts_timer.tv_sec += ts_timer.tv_nsec / 1000000000;
	ts_timer.tv_nsec %= 1000000000;

	while(!both){		//loop
   	if(count%2 == 0 && count != 0){
			sem_wait(keyboard);
			sem_timedwait(keyboard, ts_timer); //sem wait with timer for second
		}
		else{
			sem_wait(screen);
			sem_timedwait(screen, ts_timer); //sem wait with timer for second
		}
		if(count == 0){
 		 	sleep(1); //only use this if no deadlocks without it should not be necessary
		}
//    	if timeout
//      		give back first, (sem_post)
//      		wait random time
// 		increment count
//    	else
//      both = 1;		//have both  true
	}		//until have both
  return count;
}		//end get semaphores function
