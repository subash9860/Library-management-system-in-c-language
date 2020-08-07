
/*	editbooks is  function of this progarm that hepls to edit detail of books .
	
	
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

void editbooks(void);

FILE *fp;

void editbooks(void)  //edit information about book
{
	system("cls");
	int c=0;
	int d,e;
	printf("\n\n\t****Edit Books Section****");
	char another='y';
	while(another=='y')
	{
		system("cls");
		printf("\n\n\tEnter Book Id to be edited:\t");
		scanf("%d",&d);
		fp=fopen("DataBase.dat","rb+");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				printf("\n\n\tThe book is availble");
				printf("The Book ID:%d",a.id);
				printf("\n\n\tEnter new name:\t");
				scanf("%s",a.name);
				printf("\n\tEnter new Author:\t");
				scanf("%s",a.Author);
				printf("\n\tEnter new quantity:\t");
				scanf("%d",&a.quantity);
				printf("\n\tEnter new price:\t");
				scanf("%f",&a.Price);
				printf("\n\tEnter new rackno:\t");
				scanf("%d",&a.rackno);
				printf("\n\tThe record is modified");
				fseek(fp,ftell(fp)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fp);
				fclose(fp);
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
	returnfunc();
}
