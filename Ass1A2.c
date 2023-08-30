#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
    int pid, retnice;
    printf("press DEL to stop process\n");
    pid=fork();
    for(;;)
    {
       if (pid==0)
       { 
          retnice=nice(-5);
          printf("Child gets higher CPU priority %d \n",retnice);
          sleep(1);
       }
       else if(pid>0)
       {
          retnice=nice(4);
          printf("Parent gets higher CPU priority %d \n",retnice);
          sleep();
       }
       else
          printf("Unsuccessful execution preocess not created \n");
    }
}


