#include <stdio.h>
int size;
int top=-1,item,size=4;
int a[4],n;
void display();void push();void pop();
int main()
{
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
    a[top]=item;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow");
    }
    else{
        item=a[top];
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack underflows");
    }
    for(int i=top;i>=0;--i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}