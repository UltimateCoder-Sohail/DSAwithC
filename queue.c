#include <stdio.h>
int size;
int rear=-1,front=-1;
int top=-1,item,size=4;
int a[4],n;
void display();
void enqueue();void dequeue();
int main()
{
    char ch;
    
    do{
    printf("enter 1 for enqueue, 2 for dequeue:\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        enqueue();
        printf("Queue after operation\n");
        display();
        break;
        case 2:
        dequeue();
           printf("Queue after operation\n");
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
    printf("\n");
    return 0;
}
void enqueue(){
    if(rear==size-1)
    {printf("Queue is FUll");}
    else {
         printf("Enter the item you want to insert?\n");
        scanf("%d",&item);
        if(front==-1)
        {
            front=0;
        }
    rear++;;
    a[rear]=item;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue is Empty");
    }
    else{
        item=a[front];
        front++;
        if(front>rear){
        front=-1;rear=-1;}
    }
}
void display()
{
    if(rear==-1)
    {
        printf("Queue underflows");
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}