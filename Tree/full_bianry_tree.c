/* In Full Binary Tree, 
 * -> Each Parent node has either 2 or no children
 *  -> It is also called Proper Binary Tree*/

#include<stdio.h>
#include<stdlib.h>

// Initializing the node elements
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *root = NULL;

Node *create_node(int item){
    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

int Is_Full(Node *root){
    if (root == NULL)
        return 1;

    // Ensuring node has no childeren
    if ((root->left == NULL) && (root->right == NULL))
        return 1;

    // Ensuring that the node has two children
    if((root->left != NULL) && (root->right != NULL))
        return (Is_Full(root->left) && Is_Full(root->right));

    return 0;
}

// Displaying data in Inorder Traversal
void Inorder(Node *root){

    if (root == NULL){
        return;
    }   
    Inorder(root -> left);
    printf("%d ", root-> data);
    Inorder(root -> right);
    return;
}

// Driver Code
int main(){
    root = create_node(43);
    root -> left = create_node(76);
    root -> right = create_node(15);
    root -> left -> left = create_node(87);
    root -> left -> right = create_node(98);
    root -> right -> left = create_node(55);
    root -> right -> right = create_node(32);

    printf("Tree is : \n");
    Inorder(root);
    
    printf("\nChecking if the tree is Full Binary Tree or not - \n");
    if (Is_Full(root)){
        printf("The Tree is Full Binary Tree\n");
    }

    else{
        printf("The Tree is not a Full Binary Tree\n");
    }
}

/*
 * Results : 
 
Tree is :
87 76 98 43 55 15 32
Checking if the tree is Full Binary Tree or not -
The Tree is Full Binary Tree

*/
