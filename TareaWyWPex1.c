#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>



void randomizer()
{
	int a =rand();
	int b = a % 100;
	printf("%d\n", b + 1);
}

int main()
{
	pid_t A, B, M;
	
	int status;
	srand(time(0));


	A = fork();
	
	//First Son: A
	if( A == 0 )
	{
		printf("Son A, my pid is %d\n", getpid());
		randomizer();
		return(0);
	}
	
	B = fork();
	
	//Second Son: B
	if( B == 0 )
	{
		printf("Son B, my pid is %d\n", getpid());
		randomizer();
		return(0);
	}
	
	M = fork();
	
	//Third Son: M
	if( M == 0 )
	{
		printf("Son M, my pid is %d\n", getpid());
		randomizer();
		return(0);
	}
	
	//Father
	if( A > 0 )
	{
	wait(&status);
	printf("\nMy son finished with the following state: %d.\n\n", WEXITSTATUS(status));
	
	wait(&status);
	printf("\nMy son finished with the following state: %d.\n\n", WEXITSTATUS(status));
	
	wait(&status);
	printf("\nMy son finished with the following state: %d.\n\n", WEXITSTATUS(status));
	}
	return 0;

}

