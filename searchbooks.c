/*	searchbooks is  function of this progarm that display search  books .
	
	
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
#include<conio.h>
#include<stdlib.h>



void searchbooks(void);

void searchbooks()
{
	char findbook;
	FILE *fp;
	system("cls");
	int d,i;
	char b[20]="Searching........";
	printf("\n\n\n\t**************Search Books********************\n");
	printf("\n\n\n\t 1. Search By ID");
	printf("\n\n\t 2. Search By Name");
	printf("\n\n\t Enter Your Choice\t");
	fp=fopen("DataBase.dat","rb+"); //open file for reading propose
	rewind(fp);   //move pointer at the begining of file
	switch(getch())
	{
		case '1':
		{
			system("cls");
			printf("\n\n\t****Search Books By Id****");
			printf("\n\n\tEnter the book id:\t");
			scanf("%d",&d);
			printf("\n\t");
			for(i=0;i<20;i++)
			{
				Sleep(50);
				printf("%c",b[i]);
			}
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(a.id==d)
				{
					Sleep(20);
					printf("\n\tThe Book is available\n");
					printf("\n\tID:\t\t%d\n",a.id);
					printf("\n\tName:\t\t%s\n",a.name);
					printf("\n\tAuthor:\t\t%s\n",a.Author);
					printf("\n\tQantity:\t%d\n",a.quantity);
					printf("\n\tPrice:Rs\t%.2f\n",a.Price);
					printf("\n\tRack No:\t%d\n ",a.rackno);
					findbook='t';
				}
			}
			if(findbook!='t')  //checks whether conditiion enters inside loop or not
			{
				printf("\n\n\t\aNo Record Found\n");
			}
			printf("\n\n\tTry another search?(Y/N)\t");
			if(getch()=='y')
			searchbooks();
			else
			mainmenu();
			break;
		}
		case '2':
		{
			char s[15];
			system("cls");
			printf("\n\n\t****Search Books By Name****");
			printf("\n\tEnter Book Name:\t");
			scanf("%s",s);
			printf("\n\t");
			for(i=0;i<20;i++)
			{
				Sleep(50);
				printf("%c",b[i]);
			}
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
				{
					printf("\n\tThe Book is available\n");
					printf("\n\tID:\t\t%d\n",a.id);
					printf("\n\tName:\t\t%s\n",a.name);
					printf("\n\tAuthor:\t\t%s\n",a.Author);
					printf("\n\tQantity:\t%d\n",a.quantity);
					printf("\n\tPrice:Rs\t%.2f\n",a.Price);
					printf("\n\tRack No:\t%d\n ",a.rackno);
				}
				else
				printf("\n\n\t\aNo Record Found");
			}
			printf("\n\n\tTry another search?(Y/N)\t");
			if(getch()=='y')
			searchbooks();
			else
			mainmenu();
			break;
		}
		default :
		getch();
		searchbooks();
	}
	fclose(fp);
}
