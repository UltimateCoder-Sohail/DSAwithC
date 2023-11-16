#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root,*p,*ptr,*head;
struct node* getnode();
void traversal();
int n,i;
int main()
{   i=0;
    // printf("ENTER THE HEIGHT OF THE TREE:");
    // scanf("%d",&n);
    root=0;
    root= getnode();
    // p=root;
    struct node *r;
    r=root->data;
    traversal(r);
}
void traversal(struct node *root)
{  
    if(root==0)
    {
        return;
    }
    printf("%d",root->data);
    traversal(root->left);
    traversal(root->right);
}
struct node* getnode(){
    printf("ENTER -1 IF NO NODE");
    scanf("%d",&i);
    if(i==-1)
    {return 0;}
    p=malloc(sizeof(struct node*));
    // scanf("%d",&p->data);
    printf("ENTER THE LEFT CHILD");
    scanf("%d",&p->data);
// p->left=getnode();
    printf("ENTER THE RIGHT CHILD");
    scanf("%d",&p->data);
 p->right=getnode();
 i++;
return p;
}