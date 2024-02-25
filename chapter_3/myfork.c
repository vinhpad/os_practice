#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int value = 5;
int main(){
    printf("\n Before fork()");
    pid_t pid;
    pid = fork();
    printf("\n ProcessID = %d", getpid());
    

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "\n Fork Failed");
        return 1;
    } else 
        if (pid == 0) { /* child process */
          
            printf("\n Parent of ProcessID %d", getppid());
            value += 15;
            printf("\n CHILD: value = %d \n",value);
            /* LINE A */
            return 0;
        } else 
            if (pid > 0) { /* parent process */
                wait(NULL);
            
                printf("\n PARENT: Parent of ProcessID %d", getppid());
                printf("\n PARENT: value = %d ",value);
                printf("\n PARENT: end process %d \n", getpid());
                return 0;
            }

    
    return 0;
}
