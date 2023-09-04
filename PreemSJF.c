#include <stdio.h>
#include <stdlib.h>

void main()
{
     int i, n;
     printf("Enter the number processes : ");
     scanf("%d",&n);
     
     int at[n], bt[n], rt[n],t[n], ct, smallest, remain=0, time, temp[n];
     float sum_wt=0, sum_tat=0;
     for (i=0;i<n;i++)
     {
         printf("\nEnter the arrival Time for %d process : ",i+1);
         scanf("%d",&at[i]);
         t[i] = at[i];
     }
     
     for (i=0;i<n;i++)
     {
         printf("\nEnter the Burst Time for %d process : ",i+1);
         scanf("%d",&bt[i]);
         rt[i] = bt[i];
         temp[i] = bt[i];
     }
     
     printf("\npro\tat\tbt\ttat\twt ");
     for (time=0 ; remain != n ;time++)
     {
         for (i=0;i<n;i++)
         {
             if (at[i] <= time && rt[i])
                smallest = i;
         }
         rt[smallest]--;
         if (rt[smallest]==0)
         {
            remain++;
            ct = time+1;
            printf("\np[%d]\t%d\t%d\t%d\t%d ",smallest+1,at[smallest], bt[smallest], ct-at[smallest], ct-bt[smallest]-at[smallest]);
            sum_tat+=(ct-at[smallest]);
            sum_wt+=(ct-bt[smallest]-at[smallest]);
         }
     }
     
     sum_wt/=n;
     sum_tat/=n;
     printf("\nAverage Waiting Time  is : %f\n",sum_wt);
     printf("Average turn around Time  is: %f\n",sum_tat);
                 
}

/*
Output : 

ty28@pc48:~/TY28/OS/ASSIGNMENT_03/Set_B$ cc PreemSJF.c
ty28@pc48:~/TY28/OS/ASSIGNMENT_03/Set_B$ ./a.out
Enter the number processes : 4

Enter the arrival Time for 1 process : 0

Enter the arrival Time for 2 process : 1

Enter the arrival Time for 3 process : 2 

Enter the arrival Time for 4 process : 3

Enter the Burst Time for 1 process : 3

Enter the Burst Time for 2 process : 1

Enter the Burst Time for 3 process : 1

Enter the Burst Time for 4 process : 2

pro	at	bt	tat	wt 
p[2]	1	1	1	0 
p[3]	2	1	1	0 
p[4]	3	2	2	0 
p[1]	0	3	7	4 
Average Waiting Time  is : 1.000000
Average turn around Time  is: 2.750000

*/
