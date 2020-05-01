#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
	char bookId[10];
	char bookName[20];
	float price;
	int qty;
	char genre[10];
	struct book *next;
}*top=NULL, *front=NULL, *rear=NULL, *disp=NULL;

void push();
void display();
void purchase();

void main()
{
   int choice;
   printf("\n BOOK STORE \n");
   do{
      printf("\n      MENU      \n");
      printf("1. Display\n2. Purchase\n3.Add Books(admin only)\n4.EXIT\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
	 {
	 case 1:display();break;
	 case 2: purchase(); break;
	 case 3: push(); break;
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }   
   }while(choice>=1&&choice<=3);
}

void push()
{
   struct book *newNode;
   newNode = (struct book*)malloc(sizeof(struct book));
   printf("\n Enter the Book Id: ");
   scanf("%s", &newNode->bookId);
   printf("\n Enter the Book Name: ");
   scanf("%s", &newNode->bookName);
   printf("\n Enter the price: ");
   scanf("%f", &newNode->price);
   printf("\n Enter the qty.: ");
   scanf("%d", &newNode->qty);
   printf("\n Enter the genre(in lowercase): ");
   scanf("%s", &newNode->genre);
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   printf("\nItem Added!!!\n");
}


void purchase()
{   char id[10];
    char ch;
    int qt;
	printf("\n Enter BookId of the BOOK to be puchased: ");
	scanf("%s", id);
	printf("\n Enter no. of books to be puchased: ");
	scanf("%d", &qt);
	struct book *temp=top;
	struct book *p=top;
	if(temp==NULL)
	printf("\n No Books Available!");
	
	while(temp!=NULL)
	{
		if(strcmp(temp->bookId,id)==0)
		{
			if(qt<temp->qty)
			{
				temp->qty=temp->qty-qt;
				printf("\n Purchase Successful!");
				printf("\n current available number of book with id %s is %d",id,temp->qty);
				break;
			}
			
			if(qt>=temp->qty)
			{
				printf("\n Qty. Available: %d", temp->qty);
				printf("\n Procced Purchase?\n 1.yes\n2.no (1/2)");
				scanf("%d", &ch);
				if(ch==1)
				{
				while(strcmp(p->bookId,temp->bookId)!=0)
				{p=p->next;
				}
					p->next=temp->next;
					struct book *queueNode;
                    queueNode = (struct book*)malloc(sizeof(struct book));
                    strcpy(queueNode->bookId,temp->bookId);
                    strcpy(queueNode->bookName,temp->bookName);
                    queueNode->price=temp->price;
                    queueNode->qty=temp->qty;
                    strcpy(queueNode->genre,temp->genre);
                    queueNode->next=NULL;
                    if(front == NULL)
                    front = rear = queueNode;
                    else
					{
                    rear -> next = queueNode;
                    rear = queueNode;
                    }
                    printf("\n Purchase Successful!");
                    printf("\nItem transferred to ordering queue!!!\n");
                    if(temp==top)
                    {top=top->next;
                     free(temp);
                    }
                    else
                    {p=top;
                     while(p->next!=temp)
                    {p=p->next;
                    }
                    p->next=temp->next;
					free(temp);
			      	}
					break;
				}
				
			}
		}
		temp=temp->next;
	}
}


void display()
{   disp=top;
	printf("\n FICTION \n");
	int v=0;
	while(disp!=NULL)
	{
		if(strcmp(disp->genre,"fiction")==0)
		{
			printf("\n Book id: %s", disp->bookId);
			printf("\n Book name: %s", disp->bookName);
			printf("\n Book price: %f", disp->price);
			printf("\n Book qty in stock: %d", disp->qty);
			printf("\n");
			v=1;
		}
	disp=disp->next;
	}
	if(v==0)
	printf("\n No Books available! \n");
	
	disp=top;
	printf("\n NON-FICTION \n");
	v=0;
	while(disp!=NULL)
	{
		if(strcmp(disp->genre,"non-fiction")==0)
		{
			printf("\n Book id: %s", disp->bookId);
			printf("\n Book name: %s", disp->bookName);
			printf("\n Book price: %f", disp->price);
			printf("\n Book qty in stock: %d", disp->qty);
			printf("\n");
			v=1;
		}
	disp=disp->next;
	}
	if(v==0)
	printf("\n No Books available! \n");
	
	disp=top;
	printf("\n CRIME \n");
	v=0;
	while(disp!=NULL)
	{
		if(strcmp(disp->genre,"crime")==0)
		{
			printf("\n Book id: %s", disp->bookId);
			printf("\n Book name: %s", disp->bookName);
			printf("\n Book price: %f", disp->price);
			printf("\n Book qty in stock: %d", disp->qty);
			printf("\n");
			v=1;
		}
	disp=disp->next;
	}
	if(v==0)
	printf("\n No Books available! \n");
	
	disp=top;
	printf("\n COMICS \n");
	v=0;
	while(disp!=NULL)
	{
		if(strcmp(disp->genre,"comics")==0)
		{
			printf("\n Book id: %s", disp->bookId);
			printf("\n Book name: %s", disp->bookName);
			printf("\n Book price: %f", disp->price);
			printf("\n Book qty in stock: %d", disp->qty);
			printf("\n");
			v=1;
		}
	disp=disp->next;
	}
	if(v==0)
	printf("\n No Books available! \n");
	
	disp=front;
	printf("\n ORDERING QUEUE \n");
	if(front==NULL)
	printf("\n No Books to order! \n");
	while(disp!=NULL)
	{
	    printf("\n Book id: %s", disp->bookId);
		printf("\n Book name: %s", disp->bookName);
		printf("\n Book genre: %s", disp->genre);
		printf("\n Book price: %f", disp->price);
		printf("\n Book qty. in stock %d", 0);
		printf("\n");
	    disp=disp->next;
	}
	
    
}

