#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void disp(struct node* n); // function to display linked list

void push(struct node* n, int num); // function to add data in beginning of linked list

void remove_(struct node* n); // function to remove element from linked list

void append(struct node* n, int num); // function to add element in end of linked list

int main()
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node*third = NULL;
	
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head -> data = 11;
	second -> data = 22;
	third -> data = 33;

	head -> next = second;
	second -> next = third;
	third -> next = NULL;

	disp(head);	

	push(head, 25);	
	push(head, 23);
	push(head, 24);

	disp(head);

	remove_(head);
	remove_(head);
	remove_(head);
	remove_(head);

	disp(head);

	append(head, 100);
	append(head, 200);
	append(head, 250);
	
	disp(head);

return 0;
}

void disp(struct node* n)
{
	while(n != NULL)
	{
	printf("%d ", n -> data);
	n = n -> next;
	}
	printf("\n");
}

void push(struct node* ref,int data)
{
	struct node* new_data = (struct node*)malloc(sizeof(struct node*));
	new_data -> data = ref -> data;
	new_data -> next = ref -> next;
	ref -> data = data;
	ref -> next = new_data;
}

void remove_(struct node* ref)
{
	struct node* new_data = (struct node*)malloc(sizeof(struct node*));
	new_data = ref -> next;
	ref -> data = new_data -> data;
	ref -> next = new_data -> next;
	free(new_data);
}

void append(struct node* ref, int num)
{
	struct node* new = (struct node*)malloc(sizeof(struct node*));
	while(ref -> next != NULL)
	{
	ref = ref -> next;
	}
	ref -> next = new;
	new -> data = num;
	new -> next = NULL;
} 	
	
	
/*/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

output of program will be:

11 22 33
24 23 25 11 22 33
22 33
22 33 100 200 250

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////*/



