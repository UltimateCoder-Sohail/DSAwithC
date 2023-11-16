#include <stdio.h>
#include <stdlib.h>
int getnode(int);
void display();
void displayrev();
void deleteatend();

int x, pos, n,item;
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *prev, *head, *tail, *news, *p, *ptr,*ptr1;
struct node *q1;
struct node *header, *header1;
struct node *q, *r, *s;
int main()
{   int a;
    printf("ENTER THE LIMIT ");
    scanf("%d", &n);
    getnode(n);
    deleteatend();
    display(header);
    return 0;
}
void deleteatend(){
    struct node *ptr1;
    ptr1=malloc(sizeof(struct node));
    ptr=header->rlink;
    while(ptr->rlink!=NULL)
    {
        ptr1=ptr;
        ptr=ptr->rlink;
    }
    ptr1->rlink=NULL;
    free(ptr);
}
void display(struct node *head1)
{
    struct node *ptr;
    ptr = head1->rlink;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);

        ptr = ptr->rlink;
    }
}
void displayrev()
{
    struct node *ptr;
    ptr = tail;
    printf("reverse traversal ");
    // printf("%d ",ptr->llink);
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->llink;
    }
}
int getnode(int n)
{
    header = malloc(sizeof(struct node));
    head = NULL;
    ptr = malloc(sizeof(struct node));

    for (int i = 0; i < n; i++)
    {   ptr->llink=NULL;
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        ptr->rlink=p;
        p->llink=ptr;
        p->rlink = NULL;
        if (head == NULL)
        {
            head = p;
            p->llink = NULL;
            ptr->llink=head;
        }
        else
        {
            prev->rlink = p;
            p->llink=prev;
        }
        prev = p;
    }
    tail = prev;
    header->rlink = head;
    header->llink=NULL;
    // header->llink = NULL;
    display(header);
    displayrev();
    return 0;
}