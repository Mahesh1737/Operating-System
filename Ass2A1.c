/*#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
//#include<fcnt.h>
#include <string.h>

void token (char *s, char *tok[]);
void count (char op);

void main()
{
     char br[80], *ar[10];
     while (1)
     {
           printf("\n myshells ");
           fflush(stdin);
           fgets(br,80,stdin);
           token(br,ar);
           if (strcmp(ar[0],"count")==0)
              count(ar[1][0]);
           else
           {
              pid_t pid = fork();
              if (pid < 0)
                 printf("\n Error ..");
              else
                 if (pid == 0)
                 {
                    if (execvp(ar[0], ar) == -1)
                       printf("\n Bad Command ..");
                 }
              else
                 wait(NULL);
           }
     }
}
 
void token (char *s, char *tok[])
{
     int i=0;
     char *p;
     p = strtok(s, " ");
     while (p != NULL )
     {
           tok[i++]= p;
           p = strtok(NULL, " ");
     }
     tok[i]=NULL;
}

void count( char op)
{
     int cc=0, wc=0, lc=0;
     char ch;
     FILE *fp;
     fp = fopen("mahesh.txt","r");
     if (fp == NULL)
     {
        printf("\nFile not found...");
        exit(1);
     }
     while (ch=fgetc(fp) !=EOF)
     {
           cc++;
           if (ch == ' ')
              wc++;
           else
              if (ch == '\n')
              {
                 wc++;
                 lc++;
              }
     }
     fclose(fp);
     switch(op)
     {
           case 'c': 
                   printf("\nNumber of characters : %d",cc);
                   break;
           case 'w':
                   printf("\nNumber of words : %d",wc);
                   break;
           case 'l':
                   printf("\nNumber of lines : %d",lc);
     }
                   break;
}
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<sys/wait.h>

void make_toks(char *s, char *tok[])
{
 int i=0;
 char *p;

 p = strtok(s," ");
 while(p!=NULL)
 {
  tok[i++]=p;
  p=strtok(NULL," ");
 }

 tok[i]=NULL;
}

void count(char *fn, char op)
{
 int fh,cc=0,wc=0,lc=0;
 char c;

 fh = open(fn,O_RDONLY);
 if(fh==-1)
 {
  printf("File %s not found.\n",fn);
  return;
 }

 while(read(fh,&c,1)>0)
 {
  if(c==' ') wc++;
  else if(c=='\n')
  {
   wc++;
   lc++;
  }
  cc++;
 }

 close(fh);

 switch(op)
 {
 case 'c':
  printf("No.of characters:%d\n",cc);
  break;
 case 'w':
  printf("No.of words:%d\n",wc);
  break;
 case 'l':
  printf("No.of lines:%d\n",lc);
  break;
 }
}

void main()
{
 char buff[80],*args[10];
 int pid;

 while(1)
 {
  printf("myshell$");
  fflush(stdin);
  fgets(buff,80,stdin);
  buff[strlen(buff)-1]='\0';
  make_toks(buff,args);
  if(strcmp(args[0],"count")==0)
   count(args[2],args[1][0]);
  else
  {
   pid = fork();
   if(pid>0)
    wait(NULL);
   else
   {
    if(execvp(args[0],args)==-1)
     printf("Bad command.\n");
   }
  }
 }

}


/*
Output :

ty28@pc61:~/TY28/OS/ASSIGNMENT_02$ cc setAQ1.c
ty28@pc61:~/TY28/OS/ASSIGNMENT_02$ ./a.out
myshell$count l fn.txt
No.of lines:3
myshell$count w fn.txt
No.of words:6
myshell$count c fn.txt
No.of characters:32
myshell$


*/
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
                   
