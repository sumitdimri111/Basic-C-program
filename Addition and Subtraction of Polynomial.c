#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    float coeff;
    int pow;
    struct Node *next;
}node;

void display(node *poly)
{
	while(poly)
	{
		if(poly->coeff > 0)
		{
			printf("%.1f", poly->coeff);
			if(poly->pow >0)
				printf("x^%d ",poly->pow);
			if(poly->next && poly->next->coeff>0)
				printf("+");
		}
		poly = poly->next;
	}
	printf("\n");
}

node* addNode(float x, int y, node *poly)
{
	node *temp, *t;
	
		temp = (node*)malloc(sizeof(node));
		temp->coeff = x;
		temp->pow = y;
		temp->next = NULL;
	
	if(!poly)
		poly = temp;
	else
	{
		t = poly;
		while(t->next)
			t = t->next;
		t->next = temp;
	}
	return poly;
}


node* addPoly(node* poly1, node* poly2)
{
	node *poly = NULL;
	while(poly1 && poly2)
	{
		if(poly1->pow == poly2->pow)
		{
			poly = addNode(poly1->coeff+poly2->coeff, poly1->pow, poly);
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		
		else if(poly1->pow > poly2->pow)
		{
			poly = addNode(poly1->coeff, poly1->pow, poly);
			poly1 = poly1->next;
		}
		
		else if(poly1->pow < poly2->pow)
		{
			poly = addNode(poly2->coeff, poly2->pow, poly);
			poly2 = poly2->next;
		}
	}
	
	while(poly1 || poly2)
	{
		if(poly1)
		{
			poly = addNode(poly1->coeff, poly1->pow, poly);
			poly1 = poly1->next;
		}
		else
		{
			poly = addNode(poly2->coeff, poly2->pow, poly);
			poly2 = poly2->next;
		}
	}
	return poly;
}

node* subPoly(node* poly1, node* poly2, node* poly)
{
	node *temp = poly;
	while(poly1 && poly2)
	{
		if(poly1->pow == poly2->pow)
		{
			temp->coeff = poly1->coeff - poly2->coeff;
			temp = temp->next;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		
		else if(poly1->pow > poly2->pow)
		{
			temp->coeff = poly1->coeff;
			temp = temp->next;
			poly1 = poly1->next;
		}
		
		else if(poly1->pow < poly2->pow)
		{
			temp->coeff = poly2->coeff ;
			temp = temp->next;
			poly2 = poly2->next;
		}
	}
	
	while(poly1 || poly2)
	{
		if(poly1)
		{
			temp->coeff = poly1->coeff;
			temp = temp->next;
			poly1 = poly1->next;
		}
		else
		{
			temp->coeff = poly2->coeff ;
			temp = temp->next;
			poly2 = poly2->next;
		}
	}
	return poly;
}

int main()
{
	node *poly1 = NULL, *poly2 = NULL, *result=NULL;
	
	printf("Enter polynomial in decresing order of Power!!!\n");

	float x;
	int y;
	int flag;
	
	printf("\nEnter First poly!\n");
	while(1)
	{
		printf("Enter coeff and Power : ");
		scanf("%f%d",&x,&y);
		poly1 = addNode(x, y, poly1);
		printf("Do you Want to add more number in Equation? (Yes = 1 || No = 0) : ");
			scanf("%d",&flag);
		if(!flag)
			break;
	}
	
	printf("\nEnter Second poly!\n");
	while(1)
	{
		printf("Enter coeff and Power : ");
		scanf("%f%d",&x,&y);
		poly2 = addNode(x, y, poly2);
		printf("Want to add more number in Equation? (No = 0) : ");
			scanf("%d",&flag);
		if(!flag)
			break;
	}

	printf("\nFirst Equation : ");
		display(poly1);
	
	printf("Second Equation : ");
		display(poly2);
		
	result = addPoly(poly1, poly2);
		
	printf("Sum of Polynomial : ");
		display(result);
	
	result = subPoly(poly1, poly2, result);
	
	printf("Subtraction of polynomial : ");
		display(result);

	return 0;
}

