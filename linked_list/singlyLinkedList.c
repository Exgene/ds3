#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *next;
} *node;
typedef struct
{
    node front; // struct NODE* front;
} list;

node getnode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    n->next = NULL;
    return n;
}

void display(list *a);

void insertFront(list *a, int x);

void insertRear(list *a, int x);

void deleteFront(list *a);

void deleteRear(list *a);

void deletePosition(list *a, int key);

int main()
{
    list a;
    a.front = NULL;

    while (1)
    {
        int choice;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &choice);

        /*
        switch(choice)
        case(1):
        case(2):
        case(3):
        default:
        */

        if (choice == 1)
        {
            int data;
            scanf("%d", &data);

            insertRear(&a, data);
        }
        else if (choice == 2)
        {
            display(&a);
        }
        else if (choice == 3)
        {
            int key;
            scanf("%d", &key);
            deletePosition(&a, key);
        }
        else
        {
            return 0;
        }
    }
}

void insertFront(list *a, int data)
{
    node cur = a->front;
    a->front = getnode(data);
    a->front->next = cur;
}

void display(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return;
    }

    while (cur != NULL)
    {
        printf("-> %d ", cur->d);
        cur = cur->next;
    }
    printf("\n");
}

void insertRear(list *a, int x)
{
    node cur = a->front;

    if (cur == NULL)
    {
        a->front = getnode(x);
        return;
    }

    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = getnode(x);
}

void deleteRear(list *a)
{
    node cur = a->front;

    // list empty condition
    if (cur == NULL)
    {
        return;
    }

    // only one element present
    if (cur->next == NULL)
    {
        a->front = NULL; // or a->front = a->front->next;

        free(cur);
        return;
    }

    while (cur->next->next != NULL)
    {
        cur = cur->next;
    }

    node temp = cur->next;

    cur->next = NULL; // or cur->next = cur->next->next

    free(temp);
}

void deletePosition(list *a, int key)
{
    node cur = a->front;

    // list empty condition
    if (cur == NULL)
    {
        return;
    }

    if (cur->next == NULL && key != 0)
    {
        printf("invalid key\n");
        return;
    }

    if (cur->next == NULL)
    {
        a->front = a->front->next;

        free(cur);
        return;
    }

    int pos = 1;

    while (cur->next->next != NULL && pos < key) // or use pos != key
    {
        cur = cur->next;
        pos++;
    }

    if (pos != key)
    {
        printf("invalid key\n");
        return;
    }

    node temp = cur->next;

    cur->next = cur->next->next;

    free(temp);
}

void deleteFront(list *a)
{
    node cur = a->front;

    // empty list condition
    if (cur == NULL)
    {
        // printf("empty list\n");
        return;
    }

    a->front = a->front->next;

    free(cur);
}