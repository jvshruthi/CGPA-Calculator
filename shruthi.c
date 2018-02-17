#include<stdio.h>
float gpa[8];
float cgpa=0;
char grade[16];
int points[16];
int sb[2]={8,8};
int temp1=0;
int i=0;
int tcp[2]={25,25},credits[16]={4,4,3,3,3,4,2,2,4,4,3,4,3,3,2,2};
int sem(int);
int cal_grade(int);
int main()
{
int current_sem,choice,tc;
int t1;
printf("-----CGPA/GPA CALCULATOR-----\n\n\n");
printf("Enter your semester:");
scanf("%d",&current_sem);
printf("For GPA - enter 1\nCGPA - enter 2\n\nType:");
scanf("%d",&choice);
if(choice==1||choice==2)
	printf("----Grade Feed-----\n\n\n");
printf("---ENTER YOUR GRADES IN CAPITAL LETTERS!---\n\n");
switch(choice)
{
	case 1:
		tc=sem(current_sem);
		gpa[current_sem-1]=tc/tcp[current_sem-1];
		break;
	case 2:
		for(i=1;i<=current_sem;i++)
		{
		tc+=sem(i);
		t1+=tcp[i-1];
		}
		cgpa=tc/t1;
		break;
	default:printf("Error in Details!! Try Again!! :( \n\n\n");
}
if(choice==1)
printf("---GPA = %f ---",gpa[current_sem-1]);
else
printf("---CGPA = %f ---",cgpa);
return 0;
}
int sem(int x)
{
	switch(x)
	{
		case 1:
		printf("---THEORY---\n");
		printf("\nHS8151-COMMUNICATION ENGLISH:");
		grade[0]=getchar();
		printf("\n-------%d%c-------\n",grade[0],grade[0]);
		printf("\nMA8151-ENGINEERING MATHEMATICS 1:");
		scanf("%c",&grade[1]);
		printf("\nPH8151-ENGINEERING PHYSICS:");
		scanf("%c",&grade[2]);
		printf("\nCY8151-ENGINEERING CHEMISTRY:");
		scanf("%c",&grade[3]);
		printf("\nGE8151-PROBLEM SOLVING AND PY PROGRAMMING:");
		scanf("%c",&grade[4]);
		printf("\nGE8152-ENGINEERING GRAPHICS:");
		scanf("%c",&grade[5]);
		printf("---PRACTICALS---\n");
		printf("\nGE8161-PROBLEM SOLVING & PY PROGRAMMING:");
		scanf("%c",&grade[6]);
		printf("\nBS8161-PHYSICS AND CHEMISTRY LAB:");
		scanf("%c",&grade[7]);
		return cal_grade(x);
		case 2:
		printf("---THEORY---\n");
		printf("\nHS8251-TECHNICAL ENGLISH:");
		scanf("%c",&grade[0]);
		printf("\nMA8251-ENGINEERING MATHEMATICS:");
		scanf("%c",&grade[1]);
		printf("\nPH8253-PHYSICS FOR ELECTRONICS ENGG:");
		scanf("%c",&grade[2]);
		printf("\nBE8252-BASIC CIVIL AND MECHANICAL ENGG:");
		scanf("%c",&grade[3]);
		printf("\nEE8251-CIRCUIT THEORY:");
		scanf("%c",&grade[4]);
		printf("\nGE8291-EVS\t\t:");
		scanf("%c",&grade[5]);
		printf("---PRACTICALS---\n");
		printf("\nENGG PRACTICES LAB:");
		scanf("%c",&grade[6]);
		printf("\nEE8261-ELECTRIC CIRCUIT LAB:");
		scanf("%c",&grade[7]);
		return cal_grade(x);
		default : printf("\nWRONG / INVALID SEM!!!\n");
		return -1;
	}
	
}
int cal_grade(int y)
{
	for(i=0;i<sb[y-1];i++)
	{
	switch(grade[i])
	{
		case 'A':
		case 'a':
		points[i]=9;
		break;
		case 'B':
		case 'b':
		points[i]=8;
		break;
		case 'C':
		case 'c':
		points[i]=7;
		break;
		case 'D':
		case 'd':
		points[i]=6;
		break;
		case 'E':
		case 'e':
		points[i]=5;
		break;
		case 'S':
		case 's':
		points[i]=10;
		break;
		default: 
		points[i]=0;
	}
	if(y==1)
		temp1+=points[i]*credits[i];
	else if(y==2)
		temp1+=points[i]*credits[8+i];
	}
	return temp1;
}
