#include <stdio.h>
#include <stdlib.h>
int getnode(int);
void display();
void displayrev();
void insertatbeg();
void insertatany();
void insertatend();
void deleteatbeg();
void deleteatany();
void deleteatend();
int x, pos, n,item;
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *prev, *head, *tail, *news, *p, *ptr,*ptr1,*ptr2;
struct node *q1;
struct node *header, *header1;
struct node *q, *r, *s;
int main()
{   int a;
char ch;
    printf("ENTER THE LIMIT ");
    scanf("%d", &n);
    getnode(n);
    do{
    printf("ENTER 1 FOR INSERT AT BEGINNING , 2 FOR INSERT AT ANY POSITION AND 3 FOR INSERT AT END , 4 FOR DELETE AT BEGINNING ,5 FOR DELETE AT ANY POSITION ,6 FOR DELETE AT END ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("ENTER THE VALUE YOU WANT TO INSERT ");
        scanf("%d", &item);
        insertatbeg();
        display(header);
        break;
    case 2:
        printf("ENTER THE VALUE YOU WANT TO INSERT ");
        scanf("%d", &item);
        printf("ENTER THE POSITON WHERE YOU WANT TO INSERT ");
        scanf("%d", &pos);
        insertatany();
        display(header);
        break;
    case 3:
        printf("ENTER THE VALUE YOU WANT TO INSERT ");
        scanf("%d", &item);
        insertatend();
        display(header);
        break;
    case 4:
    deleteatbeg();
    display(header);
    break;
    case 5:
    printf("ENTER THE POSITON WHERE YOU WANT TO DELETE ");
    scanf("%d", &pos);
    deleteatany();
    display(header);
    break;
    case 6:
    deleteatend();
    display(header);
    break;
    default:
        printf("WRONG CHOICE");
    }
    printf("DO YOU WANT TO DO AGAIN ? ");
    scanf("%c",&ch);
    }while(getchar()!='n');
    return 0;
}
void deleteatbeg(){
    ptr=header->rlink;
    ptr1=ptr->rlink;
    header->rlink=ptr1;
    ptr1->llink=header;
    free(ptr);
}
void deleteatany(){
    ptr=header->rlink;
    struct node *ptr1;
    ptr1=malloc(sizeof(struct node));
    for(int i=1;i<pos;i++)
    {
        ptr1=ptr;
        ptr=ptr->rlink;
    }
    ptr2=ptr->rlink;
    ptr1->rlink=ptr2;
    ptr2->llink=ptr1;
    free(ptr);
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
void insertatany()
{
    ptr = header->rlink;
    for (int i = 1; i < pos; i++)
    {
        ptr1=ptr;
        ptr = ptr->rlink;
    }
    news = malloc(sizeof(struct node));
    news->data = item;
    news->rlink = ptr;
    news->llink=ptr1;
    ptr1->rlink = news;
    ptr->llink=news;
}
void insertatbeg()
{   ptr=header->rlink;
    news = malloc(sizeof(struct node));
    news->data = item;
    news->rlink=ptr;
    news->llink = header;
    header->rlink = news;
}
void insertatend()
{
    ptr = header->rlink;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }
    news = malloc(sizeof(struct node));
    news->data = item;
    news->rlink = NULL;
    news->llink=ptr;
    ptr->rlink = news;
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