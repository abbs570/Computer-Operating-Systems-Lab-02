#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main( int argc, char* argv[] )
{
	// variable declaration
	int pid;
	int time;
	
	// get the user specified time if give. default 5
	time = argv[1] ? atoi(argv[1]) : 5;

	// fork a process
	if ( (pid = fork()) < 0 )
	{
		perror("Error forking");
	}
	
	// parent waits for child
	else if ( pid > 0 )
	{
		wait(NULL);
		printf("\n");
	}
	
	// child prints hello once per second for time seconds
	else // ( pid1 == 0 )
	{
		int counter = 0;

		// send SIGALARM in time seconds
		alarm(time);

		// while wating for the alarm, print hello once per second
		while(1)
		{
			printf("hello %d\n", counter++);
			sleep(1);
		}
	}

	return 0;
}
