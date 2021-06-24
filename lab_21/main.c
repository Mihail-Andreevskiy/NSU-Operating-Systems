#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int interruptionCounter = 0;

void catchInterruption(int sig){
	signal(sig, SIG_IGN);
	interruptionCounter++;

	write(STDOUT_FILENO, "\a", 1);

	signal(sig, catchInterruption);
}


void catchQuit(int sig){
	printf("\ninterruptionCounter = %d\n", interruptionCounter);
	exit(0);

}



int main(){
	signal(SIGINT, catchInterruption);
	signal(SIGQUIT, catchQuit);
	
	while(1){
		pause();
		if (interruptionCounter > 100){
			break;
		}

	}

	return 0;
}
