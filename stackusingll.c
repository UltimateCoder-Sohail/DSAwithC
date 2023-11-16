#include <stdio.h>
#include <stdlib.h>
int size;
int top=-1,item,size=4;
int a[4],n;
struct node {
    int data;
    struct node *link;
};
void newnode();
struct node *ptr,*news,*header;
void display();void push();void pop();
int main()
{  
header=malloc(sizeof(struct node));
    header->link=news;
    ptr=header;
    char ch;
    
    do{
    printf("enter 1 for push operation in stack , 2 for pop operation in stack:\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        push();
        printf("Stack after operation\n");
        display();
        break;
        case 2:
        pop();
           printf("Stack after operation\n");
        display();
        break;
        default:
        printf("Wrong choice\n");
    }
    printf("do you want to do again?");
    scanf("%c",&ch);
    }
    while((getchar())!='n');
    display();
    printf("\n\n");
    return 0;
}
void push(){
    if(top==size-1)
    {printf("Stack Overflow");}
    else {
         printf("Enter the item you want to insert?\n");
        scanf("%d",&item);
    top=top+1;
    newnode();
    news->data=item;
            news->link=NULL;
            ptr->link=news;
            ptr=news;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow");
    }
    else{
        item=ptr->data;
        top--;
    }
}
void newnode()
{
    news=malloc(sizeof(struct node));
           

}
void display()
{
    if(top==-1)
    {
        printf("stack underflows");
    }struct node *p;
    p=header->link;
    for(int i=top;i>=0;--i)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}