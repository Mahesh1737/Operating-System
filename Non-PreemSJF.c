#include <stdio.h>
#include <stdlib.h>

void main()
{
     int i,n;
     float avwt=0, avtat=0;
     printf("Enter the Number of process :");
     scanf("%d",&n);
     
     int p[n], at[n], bt[n], wt[n], tat[n], ct[n], t[n];
     printf("Enter Processes : ");
     for (i=0;i<n;i++)
         scanf("%d",&p[i]);

     printf("Enter the Arrival time : ");
     for (i=0;i<n;i++)
     {
     
         scanf("%d",&at[i]);
         t[i] = at[i];
     }
     
  
     printf("Enter the Burst time : ");
     for (i=0;i<n;i++)
     {
         scanf("%d",&bt[i]);
     }
     
     printf("\n Before Sorting : \n");
     //printf("\npro\tat\tbt : \n);
     //for (i=0;i<n;i++)
     //{
       //  printf("\n%d\t%d\t%d \n",&
     
     printf("\npro\tat\tbt: \n");
     for (i=0;i<n;i++)
     {
                   printf("\np[%d]\t%d\t%d\n",p[i],at[i],bt[i]);
     
          
     }
     
     int temp, j;
    
     for (i=0;i<n;i++) 
         for (j=0; j<n-1-i; j++)
         {
             if ((bt[j] >bt[j+1]) && (at[j] > at[j+1]))
             {
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                
                
                
             }
         }
     int start[10];
     start[0] = 0;
     
     for (i=1;i<n;i++)
     {
         start[i] = start[i-1]+bt[i-1];
     }
     for (i=0;i<n;i++)
     {
         wt[i] = start[i]-t[i];
         avwt+=wt[i];
     }
     avwt/= n;
     
     for (i=0;i<n;i++)
     {
         tat[i] = wt[i]+bt[i];
         ct[i] = tat[i] + t[i];
         avtat+=tat[i];
     }     
     avtat/= n;
     printf("\n Before Sorting : \n");
     //gant chart
     
     printf("\n\n________________________________________________________\n");
     printf("\n\t\t  ****Gant Chart****   :\n\n");
     for (i=0;i<n;i++)
     {
         printf("      %d <p[%d]> %d ",start[i], p[i], ct[i]);
     }
     printf("\n\n________________________________________________________\n");
     
     printf("\npro\tat\tbt\twt\ttat : \n");
     for (i=0;i<n;i++)
     {
                   printf("\np[%d]\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
     
          
     }
     printf("\nAverage Waiting Time  is : %f\n",avwt);
     printf("Average turn around Time  is: %f\n",avtat);
}


/*

Output :

ty28@pc48:~/TY28/OS/ASSIGNMENT_03/Set_B$ cc Non-PreemSJF.c
ty28@pc48:~/TY28/OS/ASSIGNMENT_03/Set_B$ ./a.out
Enter the Number of process :4
Enter Processes : 1 2 3 4
Enter the Arrival time : 0 3 2 1
Enter the Burst time : 3 4 2 1

 Before Sorting : 

pro	at	bt: 

p[1]	0	3

p[2]	3	4

p[3]	2	2

p[4]	1	1

 Before Sorting : 


________________________________________________________

		  ****Gant Chart****   :

      0 <p[1]> 3       3 <p[4]> 4       4 <p[3]> 6       6 <p[2]> 10 

________________________________________________________

pro	at	bt	wt	tat : 

p[1]	0	3	0	3

p[4]	1	1	0	1

p[3]	2	2	2	4

p[2]	3	4	5	9

Average Waiting Time  is : 1.750000
Average turn around Time  is: 4.250000


*/

