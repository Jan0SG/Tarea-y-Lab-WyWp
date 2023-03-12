#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t D, L;
    
    D = fork();
    
    if (D == 0) {//Son D
       
        sleep(1); 
        printf("\nFinished my execution. My PID is: %d and my father's is:  %d\n", getpid(), getppid());
        
        return 0;
        
    } else {
    
     L = fork();
        
     if (L == 0) {//Son L
            
        sleep(3); 
        printf("\nFinished my execution. My PID is: %d and my father's is:  %d\n", getpid(), getppid());
            
        return 0;
            
     } else { //Father
     
            wait(NULL); 
            printf("One of my sons finished its execution\n");
            
            wait(NULL);  
            printf("One of my sons finished its execution\n");
            
            return 0;
        }
    }
}
