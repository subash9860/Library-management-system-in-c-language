/*
	Defining Password function which is call from main function
	
	* main.c------only compile main.c file
	# notes: makes sure all file attached in this folder to run full function of this project.
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
#include<stdlib.h>
#include<conio.h>
#include<string.h>


#include "mainmenu.c"

void Password(); //declaration of function

void Password(void) // function defination
{
	system("cls");
	char user[10]={"admin"};
	char s[10];
	char password[10]={"subash"};
	char ch,pass[10];
	int i=0;
	printf("\n\n\n\t----------- Login  Interface  -----------\n");
	printf("\n\n\n\tEnter User Name:\t");
	gets(s);
	printf("\n\n\tEnter Password:\t\t");
	while(ch!=13)
	{
		ch=getch();
	
		if(ch!=13 && ch!=8){
		putch('*');
		pass[i] = ch;
		i++;
		}
	}
	pass[i] = '\0';
	if(strcmp(pass,password)==0 && strcmp(s,user)==0)
	{
		printf("\n\n\n\t\tLogin Sucess.");
		printf("\n\n\n\tPress any key to countinue.....");
		getch();
		mainmenu();
	}
	else
	{
		printf("\n\n\n\t\aWarning!! Incorrect Password or User Name.");
		getch();
		Password();
	}
}
