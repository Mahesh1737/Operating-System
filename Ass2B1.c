#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include<sys/wait.h>
#include<unistd.h>

void make_toks(char *s, char *tok[])
{
     int i=0;
     char *p;

     p = strtok(s," ");
     while (p!=NULL)
     {
          tok[i++]=p;
          p=strtok(NULL," ");
     }

     tok[i]=NULL;
}

void list(char *dn, char op)
{
     DIR *dp;
     struct dirent *entry;
     int dc=0,fc=0;

     dp = opendir(".");
     if (dp==NULL)
     {
        printf("Dir %s not found.\n",dn);
        return;
     }

     switch (op)
    {
            case 'f':
                     while (entry=readdir(dp))
                     {
                           if (entry->d_type==DT_REG)
                              printf("%s\n",entry->d_name);
                      }
                      break;
            case 'n':
                     while (entry=readdir(dp))
                     {
                            if (entry->d_type==DT_DIR) dc++;
                            if(entry->d_type==DT_REG) fc++;
                     }
 
                     printf("%d Dir(s)\t%d File(s)\n",dc,fc);
                     break;
           case 'i':
                     while (entry=readdir(dp))
                     {
                           if ( entry->d_type==DT_REG)
                              printf("%s\t%d\n",entry->d_name,entry->d_fileno);
                     }
     }

     closedir(dp);
}

void main()
{
     char buff[80],*args[10];
     int pid;

     while (1)
    {
           printf("myshell$");
           fflush(stdin);
           fgets(buff,80,stdin);cc 
           buff[strlen(buff)-1]='\0';
           make_toks(buff,args);
          if (strcmp(args[0],"list")==0)
             list(args[2],args[1][0]);
          else
          {
             pid = fork();
             if (pid>0)
                 wait(NULL);
             else
             {
                if (execvp(args[0],args)==-1)
                   printf("Bad command.\n");
             }
          } 
    }
}

/*

Output :

ty28@pc61:~/TY28/OS/ASSIGNMENT_02$ cc setBQ1.c
ty28@pc61:~/TY28/OS/ASSIGNMENT_02$ ./a.out
myshell$list f
fn.txt
setBQ1.c
a.out
setAQ1.c
myshell$list n
4 Dir(s)	4 File(s)
myshell$list i
fn.txt	57805430
setBQ1.c	57806001
a.out	57805545
setAQ1.c	57806015
myshell$




*/
