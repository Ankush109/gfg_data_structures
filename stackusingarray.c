#include<stdio.h>
#include<stdlib.h>
#define MAX 4

typedef struct 
{
    int *a;
    int top;
}Stack;

int isEmpty(Stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Stack *s)
{
    if(s->top == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void initialisation(Stack *s)
{
    s->a = (int *)malloc(MAX*sizeof(int));
    s->top = -1;
}

void push(Stack *s, int n)
{
    if(!isFull(s))
    {
        int *a_top = &(s->top);
        int m = ++(*a_top);
        (s->a)[m] = n;
    }
    else
    {
        printf("Stack is full insertion not possible \n\n");
    }
}

void pop(Stack *s)
{
    if(!isEmpty(s))
    {
        int *a_top = &(s->top);
        printf("deleted element : %d\n\n",(s->a)[*a_top]);
        (*a_top)--;
    }
    else
    {
        printf("Stack is empty , deletion not possible \n\n");
    }
}

void display(Stack *s)
{
    printf("Stack is \n");
    int i;
    for(i=0;i<=(s->top);i++)
    {
        printf("%d\n",(s->a)[i]);
    }
    printf("\n");
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initialisation(s);
    printf("Enter 1 to insert element \nEnter 2 to delete \nEnter 3 to display \nEnter 4 to exit\n");
    while(1)
    {
        
        int ch;
        printf("enter choice : ");
        scanf("%d",&ch);
	int n;
        switch(ch)
        {
            case 1: 
                    printf("enter element : ");
                    scanf("%d",&n);
                    printf("\n");
                    push(s,n);
                    break;
            
            case 2: pop(s);
                    break;

            case 3: display(s);
                    break;

            case 4: exit(1);
                    break;
            
        }
    }
}
