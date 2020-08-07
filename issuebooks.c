/*	viewbooks is  function of this progarm that issue books for lend.
	
	
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
#include<time.h>
#include<errno.h>


void issuebooks(void);
void returnfunc(void);
void issuerecord();
int checkquantity();

FILE *fp,*fs;
int s,RETURNTIME;
char findbook;


int checkquantity()  //check whether the book are in library or not
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.quantity<=0)
	return 1;  //returns 1 if book is not exits
	return 0; //return 0 if it exits
}

void returnfunc(void)
{
	{
		printf("\n\n\tPress ENTER to return to main menu\t");
	}
	a:
	if(getch()==13) //allow only use of enter
	mainmenu();
	else
	goto a;
}

void issuerecord()  //display issued book's information
{
	system("cls");
	printf("\n\tThe Book has taken by Mr. %s\t",a.stname);
	printf("\n\tIssued Date:%d-%d-%d\t",a.issued.dd,a.issued.mm,a.issued.yy);
	printf("\n\tReturning Date:%d-%d-%d\t",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}

void issuebooks(void)  //function that issue books from library
{

	int t;
	system("cls");
	printf("\n\n\n\t********************************ISSUE SECTION**************************");
	printf("\n\n\t 1. Issue a Book");
	printf("\n\n\t 2. View Issued Book");
	printf("\n\n\t 3. Search Issued Book");
	printf("\n\n\t 4. Remove Issued Book");
	printf("\n\n\tEnter a Choice:\t");
	switch(getch())
	{
		case '1':  //issue book
		{
			system("cls");
			int c=0;
			time_t timer;
			struct tm* tm_info;
			char day[3];
			char month[3];
			char year[5];
			time(&timer);
			tm_info=localtime(&timer);
		
			strftime(day,3,"%d",tm_info);
			strftime(month,3,"%m",tm_info);
			strftime(year,5,"%y",tm_info);
			
			char another='y';
			while(another=='y')
			{
				system("cls");
				printf("\n\n\t***Issue Book section***");
				printf("\n\n\tEnter the Book Id:\t");
				scanf("%d",&t);
				fp=fopen("DataBase.dat","rb+");
				fs=fopen("Issue.dat","ab+");
				if(checkid(t)==0) //issues those which are present in library
				{
					printf("\n\n\tThe book record is available.");
					printf("\n\tThere are %d unissued books in library. ",a.quantity);
					if(checkquantity()==0) // cheching numbers of books
					{
						printf("\n\tThe name of book is %s.",a.name);
						printf("\n\n\tEnter student name:\t");
						scanf("%s",a.stname);
						printf("\n\tDay\'s wanna lend book:\t");
						scanf("%d",&RETURNTIME);
						printf("\n\n\tThe BOOK of ID %d is issued.",a.id);
						
						a.issued.dd = atoi(day);
						a.issued.mm = atoi(month);
						a.issued.yy = atoi(year);
	
						printf("\n\n\tIssued date:\t%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
						a.duedate.dd= a.issued.dd + RETURNTIME;   //for return date
						a.duedate.mm=a.issued.mm;
						a.duedate.yy=a.issued.yy;
						if(a.duedate.dd>30)
						{
							a.duedate.mm+=a.duedate.dd/30;
							a.duedate.dd=a.duedate.dd%30;
						}
						if(a.duedate.mm>12)
						{
							a.duedate.yy+=a.duedate.mm/12;
							a.duedate.mm=a.duedate.mm%12;					
						}
						printf("\n\tTo be return:\t%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
						a.quantity=a.quantity -1;
						fseek(fp,ftell(fp)-sizeof(a),0);
						fwrite(&a,sizeof(a),1,fp);
						fclose(fp);
						fseek(fs,sizeof(a),SEEK_END);
						fwrite(&a,sizeof(a),1,fs);
						fclose(fs);
					}
					else
					printf("\n\tSorry! out of stock.");
					c=1;
				}
				if(c==0)
				{
					printf("\n\n\tNo record found");
				}
				printf("\n\n\tIssue any more(Y/N):");
				fflush(stdin);
				another=getche();
				fclose(fp);
			}
			break;
		}
		case '2':  //show issued book list
		{
			system("cls");
			printf("\n\n\t*******************Issued book list************************\n");
			printf("\n\tSTUDENT NAME \tCATEGORY \tID \tBOOK NAME \tISSUED DATE \tRETURN DATE\n\n");
			fs=fopen("Issue.dat","rb");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				printf("\t%s\t\t",a.stname);
				printf("%s \t",a.cat);
				printf("%d \t",a.id);
				printf("%s \t",a.name);
				printf("%d-%d-%d\t\t",a.issued.dd,a.issued.mm,a.issued.yy );
				printf("%d-%d-%d\n",a.duedate.dd,a.duedate.mm,a.duedate.yy);
			}				
			fclose(fs);
			returnfunc();
		}
		break;
		case '3':   //search issued books by id  
		{
			system("cls");
			printf("\n\n\tEnter Book ID:");
			int p,c=0;
			char another='y';
			while(another=='y')
			{

				scanf("%d",&p);
				fs=fopen("Issue.dat","rb");
				while(fread(&a,sizeof(a),1,fs)==1)
				{
					if(a.id==p)
					{
						issuerecord();
						printf("\n\n\tPress any key.......");
						getch();
						issuerecord();
						c=1;
					}
			
				}
				fflush(stdin);
				fclose(fs);
				if(c==0)
				{
					printf("\n\n\tNo Record Found");
				}
				printf("\n\n\tTry Another Search?(Y/N)");
				another=getch();
			}
		}
		break;
		case '4':  //remove issued books from list
		{
			system("cls");
			int b;
			FILE *fg;  //declaration of temporary file for delete
			char another='y';
			while(another=='y')
			{
				printf("\n\n\tEnter book id to remove:");
				scanf("%d",&b);
				fs=fopen("Issue.dat","rb+");
				while(fread(&a,sizeof(a),1,fs)==1)
				{
					if(a.id==b)
					{
						issuerecord();
						findbook='t';
					}
					if(findbook=='t')
					{
						printf("\n\n\tDo You Want to Remove it?(Y/N)");
						if(getch()=='y')
						{
							fg=fopen("record.dat","wb+");
							rewind(fs);
							while(fread(&a,sizeof(a),1,fs)==1)
							{
								if(a.id!=b)
								{
									fseek(fs,0,SEEK_CUR);
									fwrite(&a,sizeof(a),1,fg);
								}
							}
							fclose(fs);
							fclose(fg);
							remove("Issue.dat");
							rename("record.dat","Issue.dat");
							printf("\n\n\tThe issued book is removed from list");
			
						}
			
					}
					if(findbook!='t')
					{
						printf("\n\n\tNo Record Found");
					}
				}
				printf("\n\n\tDelete any more?(Y/N)");
				another=getch();
			}
		}
		default:
		printf("\n\n\t\aWrong Entry!!");
		getch();
		issuebooks();
		break;
	}
	returnfunc();
}
