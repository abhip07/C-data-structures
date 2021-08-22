/* In Perfect BInary Tree -
 * -> Every internal node has exactly 2 chlid nodes
 * -> All child nodes are at same level */

#include<stdio.h>
#include<stdlib.h>

// Initializing the node elements
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *root = NULL;

// creating a node
Node *create_node(int item){
    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

// Calculating depth of the node
int CalculateDepth(Node *node){
    int d = 0;
    while(node != NULL){
        d++;
        node = node -> left;
    }
    return d;
}

int level = 0;
int Is_Perfect(Node *root,int d, int level){
    if (root == NULL)
        return 1;
    
    // If only root is present in tree
    if ((root->left == NULL) && (root->right == NULL))
        return (d == level+1);  // depth is 1 and level is 0
   
    // If root has only one child
    if ((root->left == NULL) || (root->right) == NULL )
        return 0;
   
    // Iterate through whole tree to validate the perfect tree
    return (Is_Perfect(root->left, d, level+1) && Is_Perfect(root->right, d, level+1));
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
    
    printf("\nChecking if the tree is Perfect Binary Tree or not - \n");
    if (Is_Perfect(root, CalculateDepth(root), 0)){
        printf("The Tree is Full Binary Tree\n");
    }

    else{
        printf("The Tree is not a Full Binary Tree\n");
    }
}

/*
 
 *Results : 
 
Tree is :
87 76 98 43 55 15 32
Checking if the tree is Perfect Binary Tree or not -
The Tree is Full Binary Tree
  
*/

