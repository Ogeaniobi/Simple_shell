#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

void shell() {
	char buffer [BUFFER_SIZE];

	while(1) {
	
	printf("oge_calls\n");

	if(fgets(buffer,BUFFER_SIZE,stdin)== NULL) {
	printf("writing_my_simple_shell,bye");
	break;
	}

	buffer[strcspn(buffer,"\n")] = "\o";
	pid_t = fork();
	if (pid < 0) {
		fprintf(stderr,"fork failed\n");
		continue;
	} else if (pid == 0) {
	     
	     execlp(buffer, buffer, NULL);
	     fprintf(stderr, "Command '%s' not found\n", buffer);
     	     exit(EXIT_FAILURE);
	} else {
   	    
	     int status;
 	     waitpid(pid, &status, 0);
	}

   }

}

int main() {
	shell();
	return(0);
}
