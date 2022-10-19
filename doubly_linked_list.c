#include <stdio.h>
#include <stdlib.h>
typedef struct dll
{
    int data;
    struct dll *prv;
    struct dll *nxt;
} DLL;
void insert(DLL **aah, int n)
{
    DLL *cur, *prev, *t;
    t = (DLL *)malloc(sizeof(DLL));
    t->data = n;
    t->prv = NULL;
    t->nxt = NULL;
    for (cur = *aah, prev = NULL; cur ; cur = cur->nxt)
        prev = cur;
    t->nxt = cur;
    if (cur)
        cur->prv = t;
    if (prev)
    {
        prev->nxt = t;
        t->prv = prev;
    }
    else
        *aah = t;
}
void deletion(DLL **aah, int n)
{
    DLL *cur, *prev;
    int found = 0;
    if (*aah == NULL)
    {
        printf("Empty list \n");
        return;
    }
    for (cur = *aah, prev = NULL; cur; cur = cur->nxt)
    {
        if (n == cur->data)
        {
            found = 1;
            if (prev)
            {
                prev->nxt = cur->nxt;
                if (cur->nxt)
                    (cur->nxt)->prv = prev;
            }
            else
            {
                *aah = cur->nxt;
                if (cur->nxt)
                    (cur->nxt)->prv = NULL;
            }
            free(cur);
            printf("Successfully deleted the item %d\n", n);
            return;
        }
        else

            prev = cur;
    }
    if (found == 0)
        printf("Item not found\n");
}
void display(DLL *ah)
{
    DLL *cur;
    if (ah == NULL)
    {
        printf("Empty list\n");
        return;
    }
    for (cur = ah; cur; cur = cur->nxt)
        printf("\t %d", cur->data);
    printf("\n");
}

void reverse_display(DLL *ah)
{
    DLL *cur;
    if (ah == NULL)
    {
        printf("Empty list\n");
        return;
    }
    for (cur = ah; cur->nxt; cur = cur->nxt)
        ;
    for (; cur; cur = cur->prv)
        printf("\t %d", cur->data);
    printf("\n");
}
void main()
{
    DLL *l = NULL;
    printf("Enter 1 : insert\nEnter 2 : delete\nEnter 3 : display\nEnter 4 : reverse display\nEnter 5 : exit\n");
    int ch, n, d;
    while (1)
    {
        printf("enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter element to insert : ");
            scanf("%d", &n);
            insert(&l, n);
            break;
        case 2:
            printf("enter element to delete : ");
            scanf("%d", &d);
            deletion(&l, d);
            break;
        case 3:
            display(l);
            break;
        case 4:
            reverse_display(l);
            break;
        case 5:
            exit(1);
            break;
        }
    }
}
