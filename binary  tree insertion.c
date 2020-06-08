#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newnode(int item);
struct node *search();
struct node *insert(struct node *root,int item);
void inorder(struct node *root);
void postorder(struct node *root);
void preorder(struct node *root);
main()
{
    int data,a;
    struct node*root=NULL;
    root=insert(root,50);
    insert(root,20);
    insert(root,40);
    insert(root,30);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    inorder(root);
    a=search(data);
    printf("%d is the searched element",a);

}
struct node *newnode(int item)
{
 struct node*temp=(struct node*)malloc(sizeof(struct node));
 temp->data=item;
 temp->left=temp->right=NULL;
 return temp;
}
struct node *insert(struct node *node,int item)
{
    if(node==NULL)
        return newnode(item);
    if(item<node->data)
        node->left=insert(node->left,item);
    else if(item>node->data)
        node->right=insert(node->right,item);

    return node;

}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        preorder("%d",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
struct node *search( struct node *root,int data)
{
 printf("enter the number to search in the tree \n");
 scanf("%d",&data);
 if(root==NULL||root->data==data)
        return root;
 if(root->data<data)
        return search(root->right,data);
 else
    return search(root->left,data);
}


