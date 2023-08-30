#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void ChildProcess(int);
void ParentProcess(int);

int main()
{
    pid_t pid;
    pid=fork();
    if (pid==0)
       ChildProcess(pid);
    else if(pid > 0)
       ParentProcess(pid);
    return 0;
}

void ChildProcess(int pid)
{
     printf("\nI am Child Process..\n");
     printf("I am Parent Process ID : %d \n",getpid());
     printf("I am Child Process ID : %d \n\n",getppid());
}

void ParentProcess(int pid)
{
     printf("I am Parent process..\n");
     printf("I am Parent Process ID : %d \n",getpid());
     printf("I am Child Process ID : %d \n\n",pid);
}
    
