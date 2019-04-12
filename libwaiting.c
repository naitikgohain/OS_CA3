#include<stdio.h>
int main()
{
	int p[20];
	int bt[20];
	int su[20];
	int wt[20];
    int turnatime[20];
    int i, k, n, temp;
	float wtavg, tatavg;
	printf("Enter the number of processes in the library queue ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("Enter the Burst Time for process  %d -- ", i);
		scanf("%d",&bt[i]);
		printf("0 for teacher process and 1 for student process -- ");
		scanf("%d", &su[i]);
	}

	return 0;
}
