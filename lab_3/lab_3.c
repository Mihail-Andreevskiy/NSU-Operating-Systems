#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
	uid_t uid = getuid();
	uid_t euid = geteuid();

	printf("uid = %d\neuid = %d\n", uid, euid);

	FILE *file = fopen("text.txt", "r");
	if (file == NULL){
		perror("Error occured while opening a file");
	}


	seteuid(getuid());
	printf("\nuid = %d\neuid = %d\n", uid, euid);


}
