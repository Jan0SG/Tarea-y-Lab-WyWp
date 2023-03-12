#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t B, C, E;
    int status;
    
    B = fork();
    
    if (B == 0) { //Son B
    
        sleep(3);
        
        printf("B process finished. Return 1\n");
        return 1;
        
    } else {
        C = fork();
        
        if (C == 0) { //Son C
        
            sleep(1); 
            
            printf("C process finished. Return 2\n");
            return 2;
            
        } else {
            E = fork();
            
            if (E == 0) { //Son E
            
                printf("E process finished. Return 3\n");
                return 3;
                
            } else { //Father
                waitpid(B, &status, 0);
                printf("Return value of B: %d\n", WEXITSTATUS(status));
                
                waitpid(C, &status, 0);
                printf("Return value of C: %d\n", WEXITSTATUS(status));
                
                waitpid(E, &status, 0);
                printf("Return value of E: %d\n", WEXITSTATUS(status));
                
                return 0;
            }
        }
    }
}
