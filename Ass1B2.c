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
    {
       sleep(10);
       ChildProcess(pid);
    }
    else
    if (pid>0)
    {
        sleep(3);
        ParentProcess(pid);
    }    
    else
    printf("\n Unsuccessful execution process not created  \n");
}
 
void ChildProcess(int pid)
{
     printf("\nI am child process..");
     printf("\nI am child process Id: %d",getpid());
     printf("\nMy parent process Id: %d\n",getppid());
}

void ParentProcess(int pid)
{
     printf("I am parent process");
     printf("\nI am Parent process Id: %d\n",getpid());
     printf("\nMy Child process Id: %d\n",pid);
}                


/*

Output :

ty28@pc61:~/TY28/OS/ASSIGNMENT_01$ cc ass1b2.c
ty28@pc61:~/TY28/OS/ASSIGNMENT_01$ ./a.out
I am parent process
I am Parent process Id: 18345

My Child process Id: 18346


*/
