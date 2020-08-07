/*
	structure
	
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

struct Date
{
	int mm;
	int dd;
	int yy;
};

struct books
{
	int id;
	char stname[20];
	char name[20];
	char Author[20];
	int quantity;
	float Price;
	int count;
	int rackno;
	char *cat;
	struct Date issued;
	struct Date duedate;
};
struct books a;
