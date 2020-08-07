/*	viewbooks is  function of this progarm that display books list.
	
	
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
void viewbooks(void);
void viewbooks(void)  //show the list of book persists in library
{
	int i=0,j;
	system("cls");
	printf("\n\n\t*****************Book List************************");
	printf("\n\n\tCATEGORY        ID    BOOK NAME  AUTHOR       QTY      PRICE   RackNo \n\n");
	j=4;
	fp=fopen("DataBase.dat","rb");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		printf("\t%s\t",a.cat);
		printf("%d\t",a.id);
		printf("%s\t",a.name);
		printf("%s\t\t",a.Author);
		printf("%d\t",a.quantity);
		printf("%.2f\t",a.Price);	
		printf("%d\t",a.rackno);
		printf("\n\n");
		j++;
		i=i+a.quantity;
	}
	printf("\n\tTotal Books =%d\n",i);
	fclose(fp);
	returnfunc();
}
