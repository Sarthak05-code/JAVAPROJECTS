#include <stdio.h>
#include <stdlib.h>
#include "type.h"   

struct bst
{
    struct bst *left;
    u32 data;
    struct bst *right;
};

typedef struct bst node;

/* Function declarations */
node *insert(node *, u32);
void pre_order(node *);
void search(node *, u32);
node *del(node *, u32);
node *findMin(node *);

int main(void)
{
    u32 num, choice;
    node *root = NULL, *temp;

    while (1)
    {
        printf("\n----------------------------");
        printf("\n 1. Insert a node");
        printf("\n 2. Pre-order Traversal");
        printf("\n 3. Search a node");
        printf("\n 4. Delete a node");
        printf("\n 5. Find the minimum node");
        printf("\n 6. Exit");
        printf("\n----------------------------");
        printf("\n Enter your choice: ");
        scanf("%u", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter data: ");
            scanf("%u", &num);
            root = insert(root, num);
            break;

        case 2:
            if (root == NULL)
                printf("\n The tree is empty");
            else
            {
                printf("\n Pre-order traversal:");
                pre_order(root);
            }
            break;

        case 3:
            if (root == NULL)
                printf("\n Tree is empty");
            else
            {
                printf("\n Enter number to search: ");
                scanf("%u", &num);
                search(root, num);
            }
            break;

        case 4:
            if (root == NULL)
                printf("\n Tree is empty");
            else
            {
                printf("\n Enter number to delete: ");
                scanf("%u", &num);
                root = del(root, num);
            }
            break;

        case 5:
            temp = findMin(root);
            if (temp == NULL)
                printf("\n Tree is empty");
            else
                printf("\n Minimum node is: %u", temp->data);
            break;

        case 6:
            exit(0);

        default:
            printf("\n Invalid choice!");
        }
    }

    return 0;
}

/* Insert a node */
node *insert(node *root, u32 num)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = num;
        root->left = root->right = NULL;
    }
    else if (num < root->data)
    {
        root->left = insert(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = insert(root->right, num);
    }
    else
    {
        printf("\n Duplicate value not allowed");
    }
    return root;
}

/* Pre-order traversal */
void pre_order(node *root)
{
    if (root != NULL)
    {
        printf(" %u", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

/* Search a node */
void search(node *root, u32 num)
{
    if (root == NULL)
    {
        printf("\n Search unsuccessful");
        return;
    }

    if (num == root->data)
    {
        printf("\n Search successful! Found %u", num);
    }
    else if (num < root->data)
    {
        search(root->left, num);
    }
    else
    {
        search(root->right, num);
    }
}

/* Delete a node */
node *del(node *root, u32 num)
{
    node *temp;

    if (root == NULL)
        return root;

    if (num < root->data)
    {
        root->left = del(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = del(root->right, num);
    }
    else
    {
        /* Node with two children */
        if (root->left != NULL && root->right != NULL)
        {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
        else
        {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            else
                root = root->left;

            free(temp);
        }
    }
    return root;
}

/* Find minimum node */
node *findMin(node *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}
