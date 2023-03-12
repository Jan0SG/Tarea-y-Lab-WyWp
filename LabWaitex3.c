#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t A, B, C, D;
    int status;

    //D
    D = fork();
    if (D == 0) {
    
        printf("Process of D, PID: %d, PPID: %d\n", getpid(), getppid());
        
        execl("/bin/ls", "ls", NULL);
        exit(0);
        
    } else {
    
        wait(&status);
        printf("\n");       
    }

    //A
    A = fork();
    if (A == 0) {
    
        printf("Process of A, PID: %d, PPID: %d\n", getpid(), getppid());
        execl("/bin/rm", "rm", "-r", "new_folder", NULL);
        exit(0);
        
    } else {
    
        wait(&status);
        printf("\n");
    }

    //C
    C = fork();
    if (C == 0) {
    
        printf("Process of C, PID: %d, PPID: %d\n", getpid(), getppid());
        execl("/bin/ls", "ls", NULL);
        exit(0);
        
    } else {
    
        wait(&status);
        printf("\n");
    }

    //M
    if (A > 0 && C > 0) {
        printf("Im M and my PID is: %d\n", getpid());
        
        B = fork();
        if (B == 0) { //B
        
            printf("Process of B, PID: %d, PPID: %d\n", getpid(), getppid());
            
            execl("/bin/mkdir", "mkdir", "new_folder", NULL);
            exit(0);
            
        } else {
        
            wait(&status);
            execl("/bin/ls", "ls", NULL);
        }
    }
    return 0;
}
