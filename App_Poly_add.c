//Appplication of List - Polynomial Addition
#include<stdio.h>
#include<malloc.h>

struct link
{
	int coeff;
	int pow;
	struct link*next;
};
struct link *poly1=NULL,*poly2=NULL,*poly=NULL;

void create(struct link *node)
{
	char ch;
	do
	{
		printf("\n Enter Coefficient :");
		scanf("%d", &node->coeff);
		printf("Enter Exponent:");
		scanf("%d",&node->pow);
		node->next=(struct link*)malloc(sizeof(struct link));
		node=node->next;
		node->next=NULL;
		printf("\n Continue(y/n):");
	 	scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
}
void show(struct link *node)
{
	while(node->next!=NULL)
	{
		printf("%dx^%d",node->coeff,node->pow);
		node=node->next;
		if(node->next!=NULL)
			printf(" + ");
	}
}
void polyadd(struct link *poly1,struct link *poly2,struct link *poly)
{
	while(poly1->next&&poly2->next)
	{
		if(poly1->pow>poly2->pow)
		{
		    	poly->pow=poly1->pow;
			poly->coeff=poly1->coeff;
			poly1=poly1->next;
		}
		else if(poly1->pow<poly2->pow)
		{
			poly->pow=poly2->pow;
			poly->coeff=poly2->coeff;
         poly2=poly2->next;
		}
		else
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff+poly2->coeff;
			poly1=poly1->next;
			poly2=poly2->next;
		}
		poly->next=(struct link*)malloc(sizeof(struct link));
		poly=poly->next;
		poly->next=NULL;
	}
	while(poly1->next||poly2->next)
	{
		if(poly1->next)
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff;
			poly1=poly1->next;
		}
		if(poly2->next)
		{
			poly->pow=poly2->pow;
			poly->coeff=poly2->coeff;
			poly2=poly2->next;
		}
		poly->next=(struct link*)malloc(sizeof(struct link));
		poly=poly->next;
		poly->next=NULL;
	}
}
int main()
{
	poly1=(struct link*)malloc(sizeof(struct link));
	poly2=(struct link*)malloc(sizeof(struct link));
	poly= (struct link*)malloc(sizeof(struct link));
	printf("Enter 1st polynomial:");
	create(poly1);
	printf("\n Enter 2nd polynomial:");
	create(poly2);
	printf("\n poly1:");
	show(poly1);
	printf("\n poly2:");
	show(poly2);
	polyadd(poly1,poly2,poly);
	printf("\n Added polynomial:");
	show(poly);
}
