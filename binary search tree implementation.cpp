#include<iostream>
#include<stdlib.h>

using namespace std;

/* Dukhu Mia */

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};

treeNode *Insert(treeNode *node,int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
//temp = (treeNode *)malloc(sizeof(treeNode));
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
    /* Else there is nothing to do as the data is already in the tree. */
    return node;
}

treeNode * Delete(treeNode *node, int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout<<"\n value Not Found \n";
    }
    else if(data < node->data)
    {
        node->left = Delete(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delete(node->right, data);
    }
    else
    {
        if(node->right && node->left)
        {
            node -> data = temp->data;
            /* As we replaced it with some other node, we have to delete that node */
            node -> right = Delete(node->right,temp->data);
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); /* temp is longer required */
        }
    }
    return node;
}

treeNode * Find(treeNode *node, int data)
{
    if(node==NULL)
    {
        /* value is not found */
        return NULL;
    }
    if(data > node->data)
    {
        /* Search in the right sub tree. */
        return Find(node->right,data);
    }
    else if(data < node->data)
    {
        /* Search in the left sub tree. */
        return Find(node->left,data);
    }
    else
    {
        /* value Found */
        return node;
    }
}

void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}

void Postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
}


int main()
{
    treeNode *root = NULL,*temp;
    int ch;

    while(1)
    {
        cout << "\n\n-*- Binary Search Tree Main Manu -*-";
        cout << "\n\t 1.Insert";
        cout << "\n\t 2.Delete";
        cout << "\n\t 3.Inorder";
        cout << "\n\t 4.Preorder";
        cout << "\n\t 5.Postorder";
        cout << "\n\t 6.Search";
        cout << "\n\t 7.Exit\n\n";

        cout<<"\n Enter Your option: ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"\n Enter the value to be inserted: ";
            cin>>ch;
            root = Insert(root, ch);
            cout<<"\n\n All your values are: ";
            Inorder(root);
            break;

        case 2:
            cout<<"\n Enter the value to be deleted: ";
            cin>>ch;
            root = Delete(root,ch);
            cout<<"\n After deletion value are: ";
            Inorder(root);
            break;

        case 3:
            cout<<"\n Inorder Travesals is: ";
            Inorder(root);
            break;

        case 4:

            break;

        case 5:
            cout<<"\n Postorder Traversals is: ";
            Postorder(root);
            break;

        case 6:
            cout<<"\n Enter the value to be searched: ";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL)
            {
                cout<<"\n value is not found ";
            }
            else
            {
                cout<<"\n value "<<temp->data<<" is Found \n ";
            }
            break;

        case 7:
            exit(0);
            break;

        default:
            cout<<"\n Invalid option! Please Enter correct option: ";
            break;
        }
    }
    return 0;
}
