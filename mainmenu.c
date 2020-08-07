/*
	Defining main menu  function which is call from password
	
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


#include "addbooks.c"
#include "deletebooks.c"
#include "searchbooks.c"
#include "issuebooks.c"
#include "viewbooks.c"
#include "editbooks.c"

void mainmenu(void);

void mainmenu()
{
	system("cls");
	int i;
	printf("\n\n\t--------------------------------- MAIN MENU ------------------------------------------");
	printf("\n\n\t\t  1. Add Books   \n");
	printf("\n\n\t\t  2. Delete books\n");
	printf("\n\n\t\t  3. Search Books\n");
	printf("\n\n\t\t  4. Issue Books\n");
	printf("\n\n\t\t  5. View Book list\n");
	printf("\n\n\t\t  6. Edit Book's Record\n");
	printf("\n\n\t\t  7. Close Application\n");
	printf("\n\t\t\t\t\t");
	printf("\n\t\t  Enter your choice:\t");
	switch(getch())
	{
		case '1':
		addbooks();
		break;
		case '2':
		deletebooks();
		break;
		case '3':
		searchbooks();
		break;
		case '4':
		issuebooks();
		break;
		case '5':
		viewbooks();
		break;
		case '6':
		editbooks();
		break;
		case '7':
		{
			system("cls");
			printf("\n\n\t\tThank you");
			printf("\n\n\t\tFor Using ");
			printf("\n\n\t\tLibrary Management System\n");
			printf("\n\n\t\t******************************************");
			printf("\n\n\t\t******************************************");
			printf("\n\n\t\t******************************************");
			printf("\n\n\t\t******************************************\n");
			Sleep(30);
			exit(0);
		}
		default:
		{
			printf("\aWrong Entry!!Please re-entered correct option\n");
			if(getch())
			mainmenu();
		}

	}
}
