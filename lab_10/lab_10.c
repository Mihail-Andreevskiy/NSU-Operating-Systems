#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <siginfo.h>


int main(int argc, char *argv[]){



	if (argc < 2){
		printf("subprogramm and its arguments are not provided\n\n");
		return 1;
	}


	pid_t forkID;
	forkID = fork();
	
	if (forkID == 0){ //child
		execve(argv[1], &argv[1], NULL);
				
		exit(13);
	}

	if (forkID > 0){	//parent
		
		siginfo_t infop;

		printf("\n\nwaiting for the child\n\n");
		int waitStatus = waitid(P_PID, forkID, &infop, WEXITED);
		
		printf("\nstopped waiting for the child\n\n");

		if (waitStatus == -1){
			perror("\nwaiting error");
		
		}
		printf("\nwaitStatus = %d\n\n", waitStatus);
		

		printf("some content of infop:\n  si_signo = %d\n  si_errno = %d\n  si_code = %d\n", 
			infop.si_signo, 
			infop.si_errno,
			infop.si_code);

		printf("child process exit code(si_status) = %d\n", infop.si_status);


/*
		int status;
		wait(&status);
		printf("child process exit code(WEXITSTATUS) = %d\n", WEXITSTATUS(status));
*/

	}

	if (forkID < 0){
		perror("\nsth wrong with fork...\n\n");
		return 1;

	}


	return 0;
}
