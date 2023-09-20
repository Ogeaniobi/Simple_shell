#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
	pid_t process_id;
	pid_t parentprocess_id;

	process_id = getpid();
	parentprocess_id = getppid();

	printf("My pid is %u\n", process_id);
	printf("My ppid is %u\n", parentprocess_id);

	return(0);
}	

