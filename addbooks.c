/*
	addbooks function helps to add books in library.
	
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
#include<time.h>


#include "structure.c"


void addbooks(void);
int getdata(void);  // provide info of book which are in structure
int checkid(int);

char catagories[][15]={"Bsc.CSIT","BIT","BCA","BSC","BBA","BBS"};
FILE *fp;
int s;


int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
}

int getdata()
{
	system("cls"); // clear screen
	int t;
	printf("\n\n\n\tEnter the Information Below\n");
	printf("\n\n\tCourse:\t\t%s",catagories[s-1]);
	printf("\n\n\tBook ID:\t");
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		printf("\n\aThe book id already exists\a");
		getch();
		mainmenu();
		return 0;
	}
	a.id=t;
	printf("\n\tBook Name:\t");
	scanf("%s",a.name);
	printf("\n\tAuthor:\t\t");
	scanf("%s",a.Author);
	printf("\n\tQuantity:\t");
	scanf("%d",&a.quantity);
	printf("\n\tPrice:\t\t");
	scanf("%f",&a.Price);
	printf("\n\tRack No:\t");
	scanf("%d",&a.rackno);
	return 1;
}


void addbooks()
{
	system("cls");
	printf("\n\n\n\t-----------------------SELECT COURSE CATALOG-------------------------------------");
	printf("\n\n\t 1. Bsc.CSIT");
	printf("\n\n\t 2. BIT");
	printf("\n\n\t 3. BCA");
	printf("\n\n\t 4. BSC");
	printf("\n\n\t 5. BBA");
	printf("\n\n\t 6. BBS");
	printf("\n\n\t 7. Back to main menu");
	printf("\n\n\tEnter your choice:\t");
	scanf("%d",&s);
	if(s==7)
	mainmenu();
	system("cls");
	fp=fopen("DataBase.dat","ab+");
	if(getdata()==1)
	{
		a.cat=catagories[s-1];
		fseek(fp,0,SEEK_END);
		fwrite(&a,sizeof(a),1,fp);
		fclose(fp);
		printf("\n\n\tThe record is sucessfully saved\n");
		printf("\n\n\tSave any more?(Y / N):\t");
		if(getch()=='n')
		mainmenu();
		else
		system("cls");
		addbooks();
	}
}


