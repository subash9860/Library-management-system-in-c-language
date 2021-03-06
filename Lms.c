#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> //time_t, struct tm*,time(&timer),localtime(&timer),strftime(day,3,"%d",tm_info) are defined
#include<errno.h> //atoi() is defined


void password(void);
int chechkpws();
void mainmenu(void);
void addbooks(void);
int checkbookid(int);
void viewbooks(void);
void searchbooks(void);
void deletebooks(void);
void editbooks(void);
void issuebooks(void);
int checkquantity();
void returnbook(void);
void member(void);
void addstudent(void);
int checkstid(int);
void viewstudent(void);
void deletestudent(void);


FILE *fb,*ft,*fs,*fst,*fi,*fit;

int main()
{
	char a[40]="  Welcome to Library Management System";
	char b[23]="Project By Subash k.c.";
	char c[25]="Bsc.csit 1st sem in BKMC";
	char d[19]="Sec: B    Roll: 59";
	int i;
	printf("\n\n\n\n\t");
	for(i=0;i<20;i++)
	{
		Sleep(20); // printing  after 20 milisec  
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
	printf("\n\t\t\t\t\t\tContact admin office.");
	printf("\n\n\t\tPress any key to countinue.....");
	getch();
	password();   // call function 
}

int chechkpws() //chicking correct or not and showing password in star
{
	char password[10]={"subash"};
	char ch,pass[10];
	int i=0;
	printf("\n\n\tEnter Password:\t\t");
	while(ch!=13) // in ascii value 13 is cr(carriage return) as enter
	{
		ch=getch();
		if(ch!=13 && ch!=8) // 8=bs(backspace), 
		{
			putch('*');
			pass[i] = ch;
			i++;
		}
	}
	pass[i] = '\0'; //last character will be null character
	if(strcmp(pass,password)==0 )
	return 0; // if correct return 0;
	return 1; // if worng return 1;
}

void password(void) // function defination
{
	char user[15]={"subashadmin"};
	char s[10];
	int i=0,attempt=3;
	while(attempt>0)
	{
		system("cls");
		printf("\n\n\n\t----------- Login  Interface  -----------\n");
		printf("\n\n\n\tEnter User Name:\t");
		gets(s);
		if(chechkpws()==0  && strcmp(s,user)==0)
		{
			printf("\n\n\n\t\tLogin Sucess.");
			printf("\n\n\n\tPress any key to countinue.....");
			getch();
			mainmenu();
		}
		else
		{
			printf("\n\n\n\t\aWarning!! Incorrect Password or User Name.");
			attempt--;
			if(attempt>0)
			{
				printf("\n\n\tRemaining attempt:\t%d",attempt);
				getch();
			}
			else
			{
				printf("\n\n\tSorry! Try next again.");
				getch();
			}
		}
	}
}

void mainmenu()
{
	system("cls");
	printf("\n\n\t--------------------------------- MAIN MENU ------------------------------------------");
	printf("\n\n\t\t  1. Add Books   \n");
	printf("\n\n\t\t  2. view books\n");
	printf("\n\n\t\t  3. Search Books\n");
	printf("\n\n\t\t  4. delete Books\n");
	printf("\n\n\t\t  5. edit Book list\n");
	printf("\n\n\t\t  6. issue Book's Record\n");
	printf("\n\n\t\t  7. return book\n");
	printf("\n\n\t\t  8. Membership\n");
	printf("\n\n\t\t  9. Close Application\n");
	printf("\n\t\t\t\t\t");
	printf("\n\t\t  Enter your choice:\t");
	switch(getch())
	{
		case '1':
			addbooks();
			break;
		case '2':
			viewbooks();
			break;
		case '3':
			searchbooks();
			break;
		case '4':
			deletebooks();
			break;
		case '5':
			editbooks();
			break;
		case '6':
			issuebooks();
			break;
		case '7':
			returnbook();
			break;
		case '8':
			member();
			break;
		case '9':
			{
				system("cls");
				printf("\n\n\t\tThank you");
				printf("\n\n\t\tFor Using ");
				printf("\n\n\t\tLibrary Management System\n");
				printf("\n\n\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
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

struct Date
{
	int mm;
	int dd;
	int yy;
};
struct
{
	int id;
	char name[20];
	char Author[20];
	int quantity;
	float Price;
	char course[20];
}book;

struct
{
	int stid;
	char stname[20];
	int stroll;
	char stsec[5];
	char stprogram[20];
	char staddress[20];
	char stphone[10];
}student;

struct 
{
	int bookid;
	char bookname[20];
	int studentid;
	char studentname[20];
	struct Date issued;
	struct Date duedate;
}issue;

int checkbookid(int t)  //check whether the book is exist in library or not
{
	rewind(fb);		
	while(fread(&book,sizeof(book),1,fb)==1) 
	if(book.id==t)
	return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
}

void addbooks()
{
	system("cls"); // clear screen
	int t;
	fb=fopen("book.dat","ab+");
	printf("\n\n\n\tEnter the Information Below\n");
	printf("\n\tBook ID No.:\t");
	scanf("%d",&t);
	if(checkbookid(t) == 0)
	{
		printf("\n\t\aThe book id already exists\a");
		getch();
		mainmenu();
	}
	book.id=t;
	printf("\n\n\tCourse:\t\t");
	scanf("%s",book.course);
	printf("\n\tBook Name:\t");
	scanf("%s",book.name);
	printf("\n\tAuthor:\t\t");
	scanf("%s",book.Author);
	printf("\n\tNo. of books:\t");
	scanf("%d",&book.quantity);
	printf("\n\tPrice:\t\t");
	scanf("%f",&book.Price);
	fseek(fb,0,SEEK_END); //    ********
	fwrite(&book,sizeof(book),1,fb);//********
	fclose(fb);
	
	printf("\n\n\tThe record is sucessfully saved\n");
	printf("\n\n\tSave any more?(Y / N):\t");
	if(getch()=='n')
	mainmenu();
	else
	addbooks();
}

void viewbooks(void)  //show the list of book persists in library
{
	int i=0;
	system("cls");
	printf("\n\n\t********************Book List**********************************");
	printf("\n\n\tCATEGORY        ID    BOOK NAME       AUTHOR	       QTY      PRICE\n\n");
	fb=fopen("book.dat","rb");
	while(fread(&book,sizeof(book),1,fb)==1)
	{
		printf("\t%s\t\t",book.course);
		printf("%d\t",book.id);
		printf("%s\t\t",book.name);
		printf("%s\t\t",book.Author);
		printf("%d\t",book.quantity);
		printf("%.2f\t",book.Price);	
		printf("\n\n");
		i=i+book.quantity;
	}
	printf("\n\tTotal Books =%d\n",i);
	fclose(fb);
	printf("\n\n\tPress Enter to go back");
	if(getch())
	mainmenu();
}

void searchbooks()
{
	int d,i,f=0;
	char b[20]="Searching........";
	system("cls");
	printf("\n\n\n\t**************Search Books Section********************\n");
	printf("\n\n\t 1. Search By ID");
	printf("\n\n\t 2. Search By Name");
	printf("\n\n\t 3. Go Back");
	printf("\n\n\t Enter Your Choice\t");
	fb=fopen("book.dat","rb+"); //open file for reading propose
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
			while(fread(&book,sizeof(book),1,fb)==1)
			{
				if(book.id==d)
				{
					Sleep(20);
					printf("\n\tThe Book is available\n");
					printf("\n\tID:\t\t%d\n",book.id);
					printf("\n\tName:\t\t%s\n",book.name);
					printf("\n\tAuthor:\t\t%s\n",book.Author);
					printf("\n\tQantity:\t%d\n",book.quantity);
					printf("\n\tPrice:Rs\t%.2f\n",book.Price);
					f=1;
				}
			}
			if(f==0)  //checks whether conditiion enters inside loop or not
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
			printf("\n\n\t****Search Books By Name****\n");
			printf("\n\tEnter Book Name:\t");
			scanf("%s",s);
			printf("\n\t");
			for(i=0;i<20;i++)
			{
				Sleep(50);
				printf("%c",b[i]);
			}
			while(fread(&book,sizeof(book),1,fb)==1)
			{
				if(strcmp(book.name,(s))==0) //checks whether student.name is equal to s or not
				{
					printf("\n\tThe Book is available\n");
					printf("\n\tID:\t\t%d\n",book.id);
					printf("\n\tName:\t\t%s\n",book.name);
					printf("\n\tAuthor:\t\t%s\n",book.Author);
					printf("\n\tQantity:\t%d\n",book.quantity);
					printf("\n\tPrice:Rs\t%.2f\n",book.Price);
					f=1;
				}
			}
			if(f==0)  //checks whether conditiion enters inside loop or not
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
		case '3':
			mainmenu();
		default :
		getch();
		searchbooks();
	}
	fclose(fb);
}

void deletebooks()    //function that delete items from file fb
{
	int d,f;
	char another='y';
	while(another=='y')  //infinite loop
	{
		system("cls");
		printf("\n\n\t**** Delete Books ****\n");
		printf("\n\tEnter the Book ID to  delete:\t");
		scanf("%d",&d);
		fb=fopen("book.dat","rb+");
		rewind(fb);
		while(fread(&book,sizeof(book),1,fb)==1)
		{
			if(book.id==d)
			{
				printf("\n\tThe book record is available");
				printf("\n\tBook name is %s",book.name);
				f=1;
			}
		}
		if(f!=1)
		{
			printf("\n\tNo record is found modify the search");
			if(getch())
			mainmenu();
		}
		if(f==1 )
		{
			printf("\n\tDo you want to delete it?(Y/N):");
			if(getch()=='y')
			{
				ft=fopen("test.dat","wb+");  //temporary file for delete
				rewind(fb);
				while(fread(&book,sizeof(book),1,fb)==1)
				{
					if(book.id!=d)
					{
						fseek(ft,0,SEEK_CUR);
						fwrite(&book,sizeof(book),1,ft); //write all in tempory file except that
					}                              //we want to delete
				}
				fclose(ft);
				fclose(fb);
				remove("book.dat");
				rename("test.dat","book.dat"); //copy all item from temporary file to fp except that
				fb=fopen("book.dat","rb+");    //we want to delete
				if(f==1)
				{
					printf("\n\tThe record is sucessfully deleted");
					printf("\n\tDelete another record?(Y/N)");
				}
			}
			else
			mainmenu();
			fflush(stdin);
			another=getch();
		}
	}
	mainmenu();
}

void editbooks(void)  //edit information about book
{
	system("cls");
	int c=0,d;
	printf("\n\n\t***************  Edit Books Section  *****************");
	char another='y';
	while(another=='y')
	{
		printf("\n\n\tEnter Book Id to be edited:\t");
		scanf("%d",&d);
		fb=fopen("book.dat","rb+");
		while(fread(&book,sizeof(book),1,fb)==1)
		{
			if(checkbookid(d)==0)
			{
				printf("\n\n\tThe book is availble.");
				printf("\n\n\tEnter new name:\t\t");
				scanf("%s",book.name);
				printf("\n\tEnter new Author:\t");
				scanf("%s",book.Author);
				printf("\n\tEnter new quantity:\t");
				scanf("%d",&book.quantity);
				printf("\n\tEnter new price:\t");
				scanf("%f",&book.Price);
				printf("\n\tThe record is modified");
				fseek(fb,ftell(fb)-sizeof(book),0);//************************
				fwrite(&book,sizeof(book),1,fb);
				fclose(fb);
				c=1;
			}
			if(c==0)
			{
				printf("\n\n\t\aNo record found");
			}
		}
		printf("\n\tModify another Record?(Y/N)\t");
		fflush(stdin);
		another=getch() ;
	}
	if(getch())
	mainmenu();
}

int checkquantity()  //check whether the book are in library or not
{
	rewind(fb);
	while(fread(&book,sizeof(book),1,fb)==1)
	if(book.quantity<0)
	return 1;  //returns 1 if book is not exits
	return 0; //return 0 if it exits
}

void issuebooks(void)  //function that issue books from library
{
	int t,std;
	system("cls");
	printf("\n\n\n\t********************************ISSUE SECTION**************************");
	printf("\n\n\t 1. Issue a Book");
	printf("\n\n\t 2. View Issued Book");
	printf("\n\n\t 3. Search Issued Book");
	printf("\n\n\t 4. Go back");
	printf("\n\n\tEnter a Choice:\t");
	switch(getch())
	{
		case '1':  //issue book
		{
			system("cls");
			int c=0,RETURNTIME;
			time_t timer;//
			struct tm* tm_info;//
			char day[3];
			char month[3];
			char year[5];
			time(&timer);//
			tm_info = localtime(&timer);//
		
			strftime(day,3,"%d",tm_info);//
			strftime(month,3,"%m",tm_info);
			strftime(year,5,"%y",tm_info);
			
			char another='y';
			while(another=='y')
			{
				system("cls");
				printf("\n\n\t*********Issue Book section*****************");
				printf("\n\n\tEnter the Book Id:\t");
				scanf("%d",&t);
				fb=fopen("book.dat","rb+");
				if(checkbookid(t)==0) //issues those which are present in library
				{
					printf("\n\n\tThe book record is available.");
					printf("\n\tThere are %d unissued books in library. ",book.quantity);
					fi=fopen("Issue.dat","ab+");
					issue.bookid= book.id;
					if(checkquantity()==0) // cheching numbers of books
					{
						printf("\n\tThe name of book is %s.",book.name);
						strcpy(issue.bookname,book.name);
						printf("\n\n\tEnter student id:\t");
						scanf("%d",&std);
						fs=fopen("student.dat","rb+");
						if(checkstid(std)==0)
						{
							printf("\n\tStudent name is %s",student.stname);
							issue.studentid= student.stid;
							strcpy(issue.studentname,student.stname);
							printf("\n\n\tDay\'s wanna lend book:\t");
							scanf("%d",&RETURNTIME);
							printf("\n\n\tThe BOOK of ID %d is issued.",book.id);
						
							issue.issued.dd = atoi(day); //atoi() convert string into integer
							issue.issued.mm = atoi(month);//atoi() is defined in errno.h
							issue.issued.yy = atoi(year);
		
							printf("\n\n\tIssued date:\t%d-%d-%d",issue.issued.dd,issue.issued.mm,issue.issued.yy);
							issue.duedate.dd= issue.issued.dd + RETURNTIME;   //for return date
							issue.duedate.mm=issue.issued.mm;
							issue.duedate.yy=issue.issued.yy;
							if(issue.duedate.dd>30)
							{	
								issue.duedate.mm+=issue.duedate.dd/30;
								issue.duedate.dd=issue.duedate.dd%30;
							}	
							if(issue.duedate.mm>12)
							{
								issue.duedate.yy+=issue.duedate.mm/12;
								issue.duedate.mm=issue.duedate.mm%12;					
							}
							printf("\n\tTo be return:\t%d-%d-%d",issue.duedate.dd,issue.duedate.mm,issue.duedate.yy);
							book.quantity--;
							fseek(fb,ftell(fb)-sizeof(book),0);
							fwrite(&book,sizeof(book),1,fb);
							fclose(fb);
							fseek(fi,sizeof(issue),SEEK_END);
							fwrite(&issue,sizeof(issue),1,fi);
							fclose(fi);
						}
						else
						printf("\n\n\t no student found.");
						fclose(fs);
					}
					else
					printf("\n\tSorry! out of stock.");
					c=1;
					fclose(fi);
				}
				if(c==0)
				printf("\n\n\tNo record found");
				printf("\n\n\tIssue any more(Y/N):");
				fflush(stdin);
				another=getche();
				fclose(fb);
			}
			break;
		}


		case '2':  //show issued book list
		{
			system("cls");
			printf("\n\n\t***********************************  Issued book list   *******************************************\n");
			printf("\n\tSTUDENT-ID	STUDENT-NAME	BOOK-ID	BOOK-NAME	  ISSUED DATE	RETURN DATE\n\n");
			fi=fopen("Issue.dat","rb");
			while(fread(&issue,sizeof(issue),1,fi)==1)
			{
				printf("\t%d\t\t",issue.studentid);
				printf("%s\t\t",issue.studentname);
				printf("%d \t",issue.bookid);
				printf("%s \t\t",issue.bookname);
				printf("%d-%d-%d\t\t",issue.issued.dd,issue.issued.mm,issue.issued.yy );
				printf("%d-%d-%d\n",issue.duedate.dd,issue.duedate.mm,issue.duedate.yy);
			}				
			fclose(fi);
			printf("\n\n\tPress Enter to go back.");
			if(getch())
			issuebooks();
		}
		break;
		case '3':   //search issued books by id  
		{
			int p,c=0;
			char another='y';
			while(another=='y')
			{
				system("cls");
				printf("\n\n\t>>>>>>>>>>search issued books by id<<<<<<<<<<<<<< ");
				printf("\n\n\tEnter Book ID:");
				scanf("%d",&p);
				fi=fopen("Issue.dat","rb");
				while(fread(&issue,sizeof(issue),1,fi)==1)
				{
					if(issue.bookid==p)
					{
						printf("\n\n\n\tThe Book has taken by Mr. %s\t",issue.studentname);
						printf("\n\tIssued Date:%d-%d-%d\t",issue.issued.dd,issue.issued.mm,issue.issued.yy);
						printf("\n\tReturning Date:%d-%d-%d\t",issue.duedate.dd,issue.duedate.mm,issue.duedate.yy);
						printf("\n\n\tPress any key.......");
						getch();
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
		case '4':
			mainmenu();
		default:
		printf("\n\n\t\aPress Enter to go back.");
		getch();
		issuebooks();
		break;
	}
	if(getch())
	issuebooks();
}

void returnbook()    //function that delete items from file fs
{
	int d,f;
	char another='y';
	while(another=='y')  //infinite loop
	{
		system("cls");
		printf("\n\n\t**** Return book ****\n");
		printf("\n\tEnter the book ID to return :\t");
		scanf("%d",&d);
		fi=fopen("Issue.dat","rb+");
		rewind(fi);
		while(fread(&issue,sizeof(issue),1,fi)==1)
		{
			if(issue.bookid==d)
			{
				printf("\n\tThe book record is available");
				printf("\n\tbook name is %s",issue.bookname);
				f=1;
			}
		}
		if(f!=1)
		{
			printf("\n\tNo record is found modify the search");
			if(getch())
			mainmenu();
		}
		if(f==1 )
		{
			printf("\n\tDo you want to delete it?(Y/N):");
			if(getch()=='y')
			{
				fit=fopen("test3.dat","wb+");  //temporary file for delete
				rewind(fi);
				while(fread(&issue,sizeof(issue),1,fi)==1)
				{
					if(issue.bookid!=d)
					{
						fseek(fit,0,SEEK_CUR);
						fwrite(&issue,sizeof(issue),1,fit); //write all in tempory file except that
					}                              //we want to delete
				}
				fclose(fit);
				fclose(fi);
				remove("Issue.dat");
				rename("test3.dat","Issue.dat"); //copy all item from temporary file to fp except that
				fi=fopen("Issue.dat","rb+");    //we want to delete
				if(f==1)
				{
					printf("\n\tThe record is sucessfully deleted");
					printf("\n\tDelete another record?(Y/N)");
				}
			}
			else
			mainmenu();
			fflush(stdin);
			another=getch();
		}
	}
	mainmenu();
}
void member(void)
{
	system("cls");
	printf("\n\n\t<<<<<<<<<<<<<Membership>>>>>>>>>>>>>>>>>");
	printf("\n\n\t\t  1. Add Student   \n");
	printf("\n\n\t\t  2. Delete student\n");
	printf("\n\n\t\t  3. View Student List\n");
	printf("\n\n\t\t  4. Back to main menu\n");
	printf("\n\t\t\t\t\t");
	printf("\n\t\t  Enter your choice:\t");
	switch(getch())
	{
		case '1':
		addstudent();
		break;
		case '2':
		deletestudent();
		break;
		case '3':
		viewstudent();
		break;
		case '4':
		mainmenu();
		break;
		default:
		{
			printf("\aWrong Entry!!Please re-entered correct option\n");
			if(getch())
			member();
		}

	}
}


int checkstid(int t)  //check whether the student is exist in library or not
{
	rewind(fs);		
	while(fread(&student,sizeof(student),1,fs)==1) 
	if(student.stid==t)
	return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
}

void addstudent()
{
	system("cls"); // clear screen
	int t;
	fs=fopen("student.dat","ab+");
	printf("\n\n\n\tEnter the Information Below\n");
	printf("\n\tStudent ID No.:\t");
	scanf("%d",&t);
	if(checkstid(t) == 0)
	{
		printf("\n\t\aThe book id already exists\a");
		getch();
		member();
	}
	student.stid=t;
	printf("\n\tStudent name:\t");
	scanf("%s",student.stname);
	printf("\n\tCourse:\t\t");
	scanf("%s",student.stprogram);
	printf("\n\tRoll No:\t");
	scanf("%d",&student.stroll);
	printf("\n\tSection:\t");
	scanf("%s",student.stsec);
	printf("\n\tAddress:\t");
	scanf("%s",student.staddress);
	printf("\n\tPhone no:\t");
	scanf("%s",student.stphone);
	fseek(fs,0,SEEK_END); //    ********
	fwrite(&student,sizeof(student),1,fs);//********
	fclose(fs);
	printf("\n\n\tThe record is sucessfully saved\n");
	printf("\n\n\tSave any more?(Y / N):\t");
	if(getch()=='n')
	member();
	else
	addstudent();
}


void viewstudent(void)  //show the list of student persists in library
{
	system("cls");
	printf("\n\n\t***********************  Member List  ***********************************");
	printf("\n\n\tCATEGORY	ID	NAME	roll	section	address	phone No. \n\n");
	fs=fopen("student.dat","rb");
	while(fread(&student,sizeof(student),1,fs)==1)
	{
		printf("\t%s\t\t",student.stprogram);
		printf("%d\t",student.stid);
		printf("%s\t",student.stname);
		printf("%d\t",student.stroll);
		printf("%s\t",student.stsec);
		printf("%s\t",student.staddress);
		printf("%s\t",student.stphone);	
		printf("\n\n");
	}
	fclose(fs);
	printf("\n\tPres enter to return back");
	fflush(stdin);
	if(getch())
	member();
}

void deletestudent()    //function that delete items from file fs
{
	int d,f;
	char another='y';
	while(another=='y')  //infinite loop
	{
		system("cls");
		printf("\n\n\t**** Delete student ****\n");
		printf("\n\tEnter the student ID to  delete:\t");
		scanf("%d",&d);
		fs=fopen("student.dat","rb+");
		rewind(fs);
		while(fread(&student,sizeof(student),1,fs)==1)
		{
			if(student.stid==d)
			{
				printf("\n\tThe student record is available");
				printf("\n\tstudent name is %s",student.stname);
				f=1;
			}
		}
		if(f!=1)
		{
			printf("\n\tNo record is found modify the search");
			if(getch())
			member();
		}
		if(f==1 )
		{
			printf("\n\tDo you want to delete it?(Y/N):");
			if(getch()=='y')
			{
				fst=fopen("test2.dat","wb+");  //temporary file for delete
				rewind(fs);
				while(fread(&student,sizeof(student),1,fs)==1)
				{
					if(student.stid!=d)
					{
						fseek(fst,0,SEEK_CUR);
						fwrite(&student,sizeof(student),1,fst); //write all in tempory file except that
					}                              //we want to delete
				}
				fclose(fst);
				fclose(fs);
				remove("student.dat");
				rename("test2.dat","student.dat"); //copy all item from temporary file to fp except that
				fs=fopen("student.dat","rb+");    //we want to delete
				if(f==1)
				{
					printf("\n\tThe record is sucessfully deleted");
					printf("\n\tDelete another record?(Y/N)");
				}
			}
			else
			member();
			fflush(stdin);
			another=getch();
		}
	}
	member();
}
