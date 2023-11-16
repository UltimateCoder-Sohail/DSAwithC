#include <stdio.h>
#include <stdlib.h>
int getnode(int);
void display();
int concat();
int x, pos, n;
struct node
{
    int data;
    struct node *link;
};
struct node *prev, *head, *news, *p, *ptr;
struct node *q1;
struct node *header, *header1;
struct node *q, *r, *s;
int main()
{
    printf("ENTER THE LIMIT OF LINKERLIST 1");
    scanf("%d", &n);
    getnode(n);
    header1=header;
    printf("ENTER THE LIMIT OF LINKEDLIST 2 ");
    scanf("%d", &n);
    getnode(n);
    concat();
    printf("THE CONCATENATED LIST IS:");
    display(header1);
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
concat()
{
    q=header1->link;
    while(q!=NULL)
    {
        q1=q;
        // printf(" %d",q->data);
        q=q->link;
    }

    q1->link=header->link;
    
    // q->link=header1;
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
    return 0;
}