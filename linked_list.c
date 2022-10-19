#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}linked_list;

void insertion_in_sequential_order(linked_list **aa_head,int data)
{
    linked_list *prev = NULL;
    linked_list *curr = *aa_head;
    linked_list *n = (linked_list *)malloc(sizeof(linked_list));
    n->data = data;
    n->next = NULL;
    while(curr!=NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    n->next = curr;
    if(prev == NULL)
    {
        *aa_head = n;
    }
    else
    {
        prev->next = n;
        
    }
}

void display(linked_list *aa_head)
{
     
    while(aa_head!=NULL)
    {
        printf("element is %d\n",aa_head->data);
        aa_head = aa_head->next;
    }
    
}

void delete_node(linked_list **aa_head, int data)
{
    
    linked_list *prev = NULL;
    linked_list *curr = *aa_head;
    while(curr!=NULL && curr->data!=data)
    {
        prev = curr;
        curr = curr->next;
    }
    if(curr->data == data)
    {
		printf("element deleted : %d\n",data);
        if(prev == NULL)
        {
            *aa_head = (*aa_head)->next; 
            free(curr);
        }
        else
        {
            prev->next = curr->next;
            free(curr);
        }
		
    }
    else if(curr == NULL)
    {
        printf("element to be deleted not found\n");
    }
    
}

void reverse(linked_list **aa_head)
{
    linked_list *prev = NULL;
    linked_list *curr = *aa_head;
    linked_list *next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    *aa_head = prev; 
}

void swap(linked_list *a, linked_list *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
}

void bubbleSort(linked_list *start) 
{ 
    int swapped, i; 
    linked_list *ptr1; 
    linked_list *lptr = NULL; 
  
    
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}  

int main()
 {
 	linked_list *p;
 	p=NULL;
 	int ch,x;
	printf("ENTER 0 TO END \nENTER 1 TO INSERT \nENTER 2 TO DELETE \nENTER 3 TO REVERSE \nENTER 4 TO DISPLAY\nENTER 5 TO SORT\n");
 	do
 	{
 		printf("\nEnter Choice : ");
 		scanf("%d",&ch);
 		switch(ch)
 		{
			case 0:break;
 			case 1:printf("ENTER DATA : ");
 				   scanf("%d",&x);
 				   insertion_in_sequential_order(&p,x);
 				   break;
 			case 2:printf("ENTER DATA TO DELETE: ");
				   scanf("%d",&x);
 				   delete_node(&p,x);
 				   break;
			case 3:reverse(&p);
				   printf("Linked list is reversed \n");
 				   break;
 			case 4:display(p);
 				   break;
            case 5:bubbleSort(p);
                   printf("Linked list is sorted \n");
                   break;
		 }
	 }while(ch!=0);
 }