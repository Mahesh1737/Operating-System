#include <stdio.h>
#include <stdlib.h>

void main()
{
     int i,n,j;
     float avwt=0, avtat=0;
     printf("Enter the Number of process :");
     scanf("%d",&n);
     
     int p[n], at[n], bt[n], wt[n], tat[n], ct[n], t[n], pr[n];
     printf("Enter Processes : ");
     for (i=0;i<n;i++)
         scanf("%d",&p[i]);

     printf("Enter the priority: ");
     for (i=0;i<n;i++)
     {
     
         scanf("%d",&pr[i]);
         //t[i] = at[i];
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
     
     printf("\npro\tpr\tbt: \n");
     for (i=0;i<n;i++)
     {
                   printf("\np[%d]\t%d\t%d\n",p[i],pr[i],bt[i]);
     
          
     }
     
     int temp;
    
     for (i=0;i<n;i++) 
         for (j=i+1; j<n; j++)
         {
             if (pr[i] > pr[j])
             {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                
                
             }
         }
      ct[0]=bt[0];
      wt[0]=0;
      tat[0]=bt[0];
           
     for (i=1;i<n;i++)
     {
         wt[i]=wt[i-1]+bt[i-1];
         tat[i] = tat[i-1]+bt[i];
         avwt+=wt[i];
         avtat+=tat[i];
     }
     avwt/=n;
     avtat/=n;
     
     printf("\npro\tpri\tbt\twt\ttat : \n");
     for (i=0;i<n;i++)
     {
                   printf("\np[%d]\t%d\t%d\t%d\t%d\n",p[i],pr[i],bt[i],wt[i],tat[i]);
     
          
     }
     printf("\nAverage Waiting Time  is : %f\n",avwt);
     printf("Average turn around Time  is: %f\n",avtat);
}


/*
Output : 

ty28@pc48:~/TY28/OS/ASSIGNMENT_03/Set_B$ cc priority.c
ty28@pc48:~/TY28/OS/ASSIGNMENT_03/Set_B$ ./a.out
Enter the Number of process :4
Enter Processes : 1 2 3 4
Enter the priority: 3 2 1 4
Enter the Burst time : 3 2 1 4 

 Before Sorting : 

pro	pr	bt: 

p[1]	3	3

p[2]	2	2

p[3]	1	1

p[4]	4	4

pro	pri	bt	wt	tat : 

p[3]	3	1	0	1

p[2]	2	2	1	3

p[1]	1	3	3	6

p[4]	4	4	6	10

Average Waiting Time  is : 2.500000
Average turn around Time  is: 4.750000


*/
