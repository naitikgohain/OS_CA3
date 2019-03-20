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
