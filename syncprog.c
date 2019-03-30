#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>

pthread_mutex_t mlock;
void *student1();
void *student2();
void *student3();
void *teacher();
int students[3][4]={0};
int choice1;
int choice2;

int main()
{
	printf("OS Teacher Student Synchronization program\n");
	pthread_mutex_init(&mlock,NULL);
	pthread_t teacher_t;
	pthread_t student_t;
	students[1][1]=1;
	students[2][2]=2;students[3][3]=1;
	printf("Please select resource: \nPress 1 for paper\t\tPress 2 for question paper \t\t\tPress 3 for pen \n");

	while(1)
	{
		if(students[1][4]==1 && students[2][4]==1 && students[3][4]==1){break;}

		pthread_create(&teacher_t, NULL, teacher, NULL);
	    pthread_join(teacher_t,NULL);

		if((choice1==1 && choice2==2 || choice2==1 && choice1==2 ) && students[1][4]==0)
		{
		    //choices 1paper and 2questionpaper
			pthread_create(&student_t, NULL, student1, NULL);
			pthread_join(student_t,NULL);
		}
		else if((choice1==2 && choice2==3 || choice2==2 && choice1==3 ) && students[2][4]==0)
		{
		    //choices 2question paper and 3pen
			pthread_create(&student_t, NULL, student2, NULL);
			pthread_join(student_t,NULL);
		}
		else if((choice1==1 && choice2==3 || choice2==1 && choice1==3 ) && students[3][4]==0)
		{
		    //choice 1paper 3pen
			pthread_create(&student_t, NULL, student3, NULL);
			pthread_join(student_t,NULL);
		}
		else
		{
			printf("\nPlease take different choices\n");
		}
	}
	printf("\nSuccessful\n");

}

void *teacher()
{
	pthread_mutex_lock(&mlock);
	printf("\nFirst item on shared tabel :-\t");
	scanf("%d",&choice1);
	printf("Second item on shared tabel :-\t");
	scanf("%d",&choice2);
	pthread_mutex_unlock(&mlock);
}
void *student1()
{
	pthread_mutex_lock(&mlock);
	printf("\nChoices made are paper and question paper\n");
	students[1][4]=1;
	printf("\nStudent 1 has completed the assignment.\n");
	pthread_mutex_unlock(&mlock);
}
void *student2()
{
	pthread_mutex_lock(&mlock);
	printf("\nChoices made are question paper and pen\n");
	students[2][4]=1;
	printf("\nStudent 2 has Completed the assignment. \n");
	pthread_mutex_unlock(&mlock);
}
void *student3()
{
	pthread_mutex_lock(&mlock);
	printf("\nChoices made are pen and paper\n");
	students[3][4]=1;
	printf("\nStudent 3 has completed the assignment.\n");
	pthread_mutex_unlock(&mlock);
}
