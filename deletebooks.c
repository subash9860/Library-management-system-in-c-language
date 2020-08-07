/*
    deletebook is  function of this progarm that delete books from library.
	
	
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



FILE *fp,*ft;
char findbook;

void deletebooks(void);

void deletebooks()    
{
	system("cls");
	int d;
	char another='y';
	while(another=='y')  
	{
		system("cls");
		printf("\n\n\tEnter the Book ID to  delete:\t");
		scanf("%d",&d);
		fp=fopen("DataBase.dat","rb+");
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(a.id==d)
			{
				printf("\n\tThe book record is available.\t");
				printf("\n\tBook name is %s\t",a.name);
				printf("\n\tBook\'s Author name is %s\t",a.Author);
				printf("\n\tRack No. is %d",a.rackno);
				findbook='t';
			}
		}
		if(findbook!='t')
		{
			printf("\n\tNo record is found modify the search.");
			if(getch())
			mainmenu();
		}
		if(findbook=='t' )
		{
			printf("\n\tDo you want to delete it?(Y/N):\t");
			if(getch()=='y')
			{
				ft=fopen("test.dat","wb+");  //temporary file for delete
				rewind(fp);
				while(fread(&a,sizeof(a),1,fp)==1)
				{
					if(a.id!=d)
					{
						fseek(ft,0,SEEK_CUR);
						fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
					}                                   // we want to delete     
				}
				fclose(ft);
				fclose(fp);
				remove("DataBase.dat");
				rename("test.dat","DataBase.dat"); //copy all item from temporary file to fp except that
				fp=fopen("DataBase.dat","rb+");    //we want to delete
				if(findbook=='t')
				{
					printf("\n\tThe record is sucessfully deleted.");
					printf("\n\tDelete another record?(Y/N)\t");
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
