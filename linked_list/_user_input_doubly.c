#include <stdio.h>
#include "doubly.h"

int main()
{
    list a;
    a.front = NULL;

    int ch, x;

    while (1)
    {
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            scanf("%d", &x);
            insertFront(&a, x);
            break;
        case 2:
            display(&a);
            break;
        case 3:
            scanf("%d", &x);
            deleteElement(&a, x);
            break;
        default:
            return 0;
        }
    }

    return 0;
}