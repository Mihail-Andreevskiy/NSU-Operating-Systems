#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>



int main(){
	
	pid_t forkPid = fork();

	if (forkPid == -1){ // fork fail
		perror("couldn't fork");
		return 1;
	}

	if (forkPid == 0){ // child
		
		char* arguments[] = {"cat", "cat.txt", NULL};
		execve("/bin/cat", arguments, NULL);		
	}

	if (forkPid > 0){ // parent 
		wait(0);
		printf("\n\nparent process phrase\n\n\n");
	}
	
	else {
		perror("\nsth wrong with forkPid...\n\n");
		return 1;

	}

	return 0;
}
