#include <stdio.h>
#include <stdlib.h>
int getnode(int);
void display();
void insertatend();
void insertatbeg();
void insertatany();
void deleteatbeg();
void deleteatend();
void deleteatany();
int x, pos, n, item;
struct node
{
    int data;
    // struct node *llink;
    struct node *link;
};
struct node *prev, *head, *news, *p, *ptr;
struct node *q1;
struct node *header, *header1;
int main()
{
    int a;
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
void display(struct node *head1)
{
    struct node *ptr;
    ptr = head1->link;
    // ptr=header->link;
    while (ptr != header)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
void deleteatbeg(){
    ptr=header->link;
    header->link=ptr->link;
    free(ptr);
}
void deleteatany(){
    ptr=header->link;
    struct node *ptr1;
    ptr1=malloc(sizeof(struct node));
    for(int i=1;i<pos;i++)
    {
        ptr1=ptr;
        ptr=ptr->link;
    }
    ptr1->link=ptr->link;
    free(ptr);
}
void deleteatend(){
    struct node *ptr1;
    ptr1=malloc(sizeof(struct node));
    ptr=header->link;
    while(ptr->link!=header)
    {
        ptr1=ptr;
        ptr=ptr->link;
    }
    ptr1->link=header;
    free(ptr);
}
void insertatany()
{
    ptr = header->link;
    for (int i = 1; i < pos-1; i++)
    {
        ptr = ptr->link;
    }
    news = malloc(sizeof(struct node));
    news->data = item;
    news->link = ptr->link;
    ptr->link = news;
}
void insertatbeg()
{
    news = malloc(sizeof(struct node));
    news->data = item;
    news->link = header->link;
    header->link = news;
}
void insertatend()
{
    ptr = header->link;
    while (ptr->link != header)
    {
        ptr = ptr->link;
    }
    news = malloc(sizeof(struct node));
    news->data = item;
    news->link = header;
    ptr->link = news;
}
int getnode(int n)
{
    header = malloc(sizeof(struct node));
    head = NULL;
    for (int i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->link = NULL;

        if (head == NULL)
            head = p;
        else
            prev->link = p;
        prev = p;
    }
    p->link = header;
    header->link = head;
    display(header);
    return 0;
}