#include <stdio.h>
#include <stdlib.h>
int getnode(int);
void display();
struct node *reverse();
int x, pos, n;
struct node
{
    int data;
    struct node *link;
};
struct node *prev, *head, *news, *p, *ptr;
struct node *q1;
struct node *header;
struct node *q, *r, *s;
int main()
{
    printf("ENTER THE LIMIT");
    scanf("%d", &n);
    getnode(n);
    return 0;
}
void display(struct node *head1)
{
    struct node *ptr;
    ptr = head1->link;
    // ptr=header->link;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
struct node *reverse()
{
    q = header->link;
    r = NULL, s = NULL;
    while (q != NULL)
    {
        s = q->link;
        q->link = r;

        r = q;
        // q->link=r;
        q = s;
    }
    q = r;
    return q;
}
int getnode(int n)
{

    header = malloc(sizeof(struct node));
    head = NULL;
    for (int i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        q1 = malloc(sizeof(struct node));
        q = NULL;
        scanf("%d", &p->data);
        p->link = NULL;
        if (head == NULL)
            head = p;
        else
            prev->link = p;
        prev = p;
    }
    header->link = head;
    display(header);
    reverse();
    q1->link = q;
    printf("The reverse linkedlist is ");
    display(q1);
    return 0;
}