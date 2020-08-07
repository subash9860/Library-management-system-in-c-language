/*
	Author:     Subash K.C.
	Course:     Bsc.csit
	Sem: 	  1st
	Sec:	  B
	Roll:	  59
	
	Project:      library Management System
	Description:  This is the main function of this project.
	
  # notes: makes sure all file attached in this folder to run full function of this project.
  	#main.c------only compile main.c file 
  	 -password.c
	 -mainmenu.c
	 -addbooks.c
	 -searchbooks.c
	 -deletebooks.c
	 -issuebooks.c
	 -editbooks.c
	 -viewbooks.c
	 -steucture.c 
*/

#include<stdio.h>
#include<conio.h>


#include "password.c" //connect with file containg password function in same directory



int main()
{
	char a[40]="  Wel Come to Library Management System";
	char b[23]="Project By Subash k.c.";
	char c[25]="Bsc.csit 1st sem in BKMC";
	char d[19]="Sec: B    Roll: 59";
	int i;
	
	printf("\n\n\n\n\t");
	for(i=0;i<20;i++)
	{
		Sleep(20); // printing  after 50 milisec  
		printf("*");
	}
	for(i=0;i<40;i++)
	{
		Sleep(30);
		printf("%c",a[i]);
	}
	for(i=0;i<20;i++)
	{
		Sleep(20);
		printf("*");
	}
	printf("\n\n\n\t\t\t\t");
	for(i=0;i<23;i++)
	{
		Sleep(30);
		printf("%c",b[i]);
	}
	printf("\n\n\t\t\t\t");
	for(i=0;i<25;i++)
	{
		Sleep(30);
		printf("%c",c[i]);
	}
	printf("\n\n\t\t\t\t");
	for(i=0;i<19;i++)
	{
		Sleep(30);
		printf("%c",d[i]);
	}
	printf("\n\n\n\n\t\t\t\t\t\tThis software need user name and Password .\n");
	printf("\n\t\t\t\t\t\tUser Name :admin");
	printf("\n\t\t\t\t\t\tPassword  :subash\n\n");
	printf("\n\n\t\tPress any key to countinue.....");
	getch();
	Password();   // call function which is include in  #include "password.c"
}
