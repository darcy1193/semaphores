
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "processes.h"

// mother process called 'main'
//
// sem_open both semaphores
//
// fork 9 processes
// Each process passed index of loop so 1,2,3, or 4
// Below is real C to show just how easy this is, please do not overthink
int main(int argc, char * argv[]) {
	sem_t * sems=NULL, * semk=NULL;
	//sems = sem_open(......O_EXCL O_CREAT
	sems = sem_open("/screensem", O_EXCL);
	semk = sem_open("/keyboardsem", O_EXCL);
	int pids[9]; int pid;
	int i = 0;
	do {
		if( (pid = fork()) == 0){
		Process(sems, semk, i);
		}
		else {
			pids[i] = pid;
			i++;
		}
	} while( i < 9 && pid > 0);
	if(i >= 9) { // stop forking around
		//after all die, use single call or loop based on ids saved above
		//sem_unlink both
	}
	return 0;
}		//End Mother process
