#include <stdio.h>
#define MAXBUF 32

int main(int argc, char* argv[]) {
	char putMsg[MAXBUF], getMsg[MAXBUF];
	int pipeDes[2];
	int childPID = 0;

	if(pipe(pipeDes) == -1) {
		printf("Failed to create a pipe\n");
		return 0;
	}	

	childPID = fork();

	if(childPID == 0) {
		printf("--CHILD--\n");
		
		while(1) {
			read(pipeDes[0], getMsg, MAXBUF);
			printf("GET MSG : %s\n", getMsg);
			if(strncmp(getMsg, "quit", 4)) {
				exit(1);
			}
		}
	} else if (childPID > 0) {
		printf("--PARENT--\n");

		while(1) {
			printf("INPUT to PIPE : ");
			gets(putMsg);
			write(pipeDes[1], putMsg, MAXBUF);
			if(!strncmp(putMsg, "quit", 4)) {
				exit(1);
			}
			sleep(1);
		}
	} else {
		printf("Failed to fork a process\n");
	}

	return 0;
}
