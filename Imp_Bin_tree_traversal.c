//IMPLEMENTATION OF BINARY TREES, TREE TRAVERSALS
#include <stdio.h>
#include <stdlib.h>
struct tnode
{
 int data;
 struct tnode *right;
 struct tnode *left;
};
struct tnode *CreateTree(struct tnode *, int);
void Inorder(struct tnode *);
void Preorder(struct tnode *);
void Postorder(struct tnode *);

int main()
{
    struct tnode *root = NULL;
    int choice, item, n, i;
    do
    { 
        printf("\n ********** BINARY TREE TRAVERSALS *********** \n");
        printf("\n1. Creation of Binary Tree");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        root = NULL;
        printf("\n\nHow Many Nodes ? ");
        scanf("%d",&n);
        for(i = 1; i <= n; i++)
        {
        printf("\nEnter data for node %d : ", i);
        scanf("%d",&item);
        root = CreateTree(root,item);
        }
        printf("\n Tree with %d nodes is ready to Use!!\n", n);
        break;
        case 2:
        printf("\nTraversal in INORDER \n");
        Inorder(root);
        break;
        case 3:
        printf("\nTraversal in PREORDER \n");
        Preorder(root);
        break;
        case 4:
        printf("\nTraversal in POSTORDER \n");
        Postorder(root);
        break;
        case 5:
        printf("\n\n Terminating \n\n");
        break;
        default:
        printf("\n\nInvalid Option !!! Try Again !! \n\n");
        break;
        }
        } 
        while(choice != 5);
    return 0;
}
struct tnode *CreateTree(struct tnode *root, int item)
{
    if(root == NULL)
    {
    root = (struct tnode *)malloc(sizeof(struct tnode));
    root->left = root->right = NULL;
    root->data = item;
    return root;
    }
    else
    {
    if(item < root->data )
    root->left = CreateTree(root->left,item);
    else if(item > root->data )
    root->right = CreateTree(root->right,item);
    else
    printf(" Duplicate Element !! Not Allowed !!!");
    return(root);
    }
}
void Inorder(struct tnode *root)
{
    if( root != NULL)
    {
    Inorder(root->left);
    printf(" %d ",root->data);
    Inorder(root->right);
    }
}
void Preorder(struct tnode *root)
{
    if( root != NULL)
    {
    printf(" %d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
    }
}
void Postorder(struct tnode *root)
{
    if( root != NULL)
    {
    Postorder(root->left);
    Postorder(root->right);
    printf(" %d ",root->data);
    }
}

