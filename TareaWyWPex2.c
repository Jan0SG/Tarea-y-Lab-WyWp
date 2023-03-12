#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	pid_t A, B, M;
	
	int status;

	A = fork();
	
	//First Son: A
	if( A == 0 )
	{
		sleep(10);
		printf("Son A, my pid is: %d\n", getpid());
		
		return(10);
	}
	
	B = fork();
	
	//First Son: B
	if( B == 0 )
	{
		printf("Son B, my pid is: %d\n", getpid());
		
		return(0);
	}
	
	M = fork();
	
	//First Son: M
	if( M == 0 )
	{
		sleep(3);
		printf("Son M, my pid is: %d\n", getpid());
		
		return(3);
	}
	
	// Father
	if( A > 0 )
	{
	waitpid(M, &status, 0);
	printf("\nMy son  M finished with the following state: %d.\n", WEXITSTATUS(status));
	waitpid(A, &status, 0);
	printf("\nMy son  A finished with the following state: %d.\n", WEXITSTATUS(status));
	waitpid(B, &status, 0);
	printf("\nMy son  B finished with the following state: %d.\n", WEXITSTATUS(status));
	}
	return 0;

}
