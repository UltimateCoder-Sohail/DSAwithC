#include <stdio.h>
#include <stdlib.h>
int getnode(int);
void display();
void merge();
void newnode();
int x, pos, n;
struct node
{
    int coeff;
    int exp;
    struct node *link;
};
struct node *prev, *head, *news, *p, *ptr,*ptr1,*ptr2,*ptr3;
struct node *q1;
struct node *header, *header1,*header3,*header2;
struct node *q, *r, *s;
int main()
{
    printf("ENTER THE LIMIT OF POLYNOMIAL 1: ");
    scanf("%d", &n);
    getnode(n);
    header1=header;
    printf("ENTER THE LIMIT OF POLYNOMIAL 2 ");
    scanf("%d", &n);
    getnode(n);
    header2=header;
    merge();
    printf("THE MERGE LIST IS:");
    display(header3);
    return 0;
}
void display(struct node *head1)
{
    struct node *ptr;
    ptr = head1->link;
    // ptr=header->link;
    while (ptr != NULL)
    {
        printf("%d ", ptr->coeff);
        printf("%d",ptr->exp);
        ptr = ptr->link;
    }
}
void newnode()
{
    news=malloc(sizeof(struct node));
}
void merge()
{   
    header3=malloc(sizeof(struct node));
    header3->link=news;
    ptr1=header1->link;
    ptr2=header2->link;
    ptr3=header3;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->exp<ptr2->exp)
        {
            newnode();
            news->exp=ptr1->exp;
            news->coeff=ptr1->coeff+ptr2->coeff;
            news->link=NULL;
            ptr3->link=news;
            ptr3=news;
            ptr1=ptr1->link;
        }
        else if(ptr1->exp==ptr2->exp)
        {
             newnode();
            news->exp=ptr2->exp;
            news->coeff=ptr2->coeff;
            news->link=NULL;
            ptr3->link=news;
            ptr3=news;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
           
        }
        else{
             newnode();
            news->exp=ptr2->exp;
            news->coeff=ptr2->coeff;
            news->link=NULL;
            ptr3->link=news;
            ptr3=news;
            ptr2=ptr2->link;
           
        }
        
       
    }
    while(ptr1!=NULL)
    {
        
        newnode();
        news->exp=ptr1->exp;
        news->coeff=ptr1->coeff;
        news->link=NULL;
        ptr3->link=news;
        ptr3=news;
        ptr1=ptr1->link;
       
    }
    while(ptr2!=NULL)
    {
        newnode();
        news->exp=ptr2->exp;
        news->coeff=ptr2->coeff;
        news->link=NULL;
        ptr3->link=news;
        ptr3=news;
        ptr2=ptr2->link;
    }
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
        printf("enter the coefficient");
        scanf("%d", &p->coeff);
        printf("enter the degree");
        scanf("%d",&p->exp);
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