#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int num_fork = 0;
int main()
{
    pid_t pid ;
    
    for (int i = 0; i < 4; i++) {
        pid = fork();
        if(pid == 0)
            printf("\n NEW CHILD: i = %d, pid = %d, Process ID = %d, Parent Process ID = %d \n", i, pid, getpid(), getpid());
            
        if(pid > 0) {
            printf("\n PARENT: i = %d, pid = %d, Process ID = %d, Parent Process ID = %d \n", i, pid, getpid(), getpid());
            num_fork++;
        }
    }
  
    return 0;
}
