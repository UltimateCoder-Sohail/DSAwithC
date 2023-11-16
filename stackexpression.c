#include <stdio.h>
int size;
int top=-1;
char item;
char a[5],n;
void display();void push(char);char pop();
int priority(char);
int main()
{   
    char e[]={'A','+','B','^','C','-','D','*','E','/','F','\0'};
    printf("%s",e);
    top=0;
    e[0]='(';int i=0;
    char x=' ';
    push('(');
    while(top>0)
    {
        item=e[i];
        x=pop();
        switch(item)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            push(x);
            printf("%d",item);
            break;
            case ')':
            while(x!='(')
            {
                printf("%d",x);
                x=pop();
            }
            int isp=priority(x);
            int icp=priority(item);
            if(isp>=icp)
            {
                while(isp>icp)
                {
                    printf("%d",x);
                    pop();
                }
                push(x);
                push(item);
            
            }
            else if(isp<icp){
                push(x);
                push(item);
            }
            else{
                printf("Invalid Expression");
            }
            i++;
        }
    }
    
}
int priority(char ch)
{
    switch(ch){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
    }
    return -1;
    }
void push(char c){
    if(top==size-1)
    {printf("Stack Overflow");}
    else {
    top=top+1;
    a[top]=item;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("stack underflow");
    }
    else{
        item=a[top];
        top--;
    }
    return item;
}