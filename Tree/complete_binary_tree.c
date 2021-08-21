// Complete Binary Tree
/*
 -> In Complete Binary Tree, all levels are completely filled except lowest one.
 -> All leaf element must lean towards left.
 -> Last element might not have right child i.e 
    The complete binary tree doesn't have to be a full binary tree.
*/

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

int count_nodes(Node *root){
    if (root == NULL)
        return 0;
    return (1+count_nodes(root->left) + (count_nodes(root->right)));
}


int is_complete(Node *root, int index, int NumberofNodes){
    if (root == NULL)
        return 1;

    if (index >= NumberofNodes)
        return 0;
    
    // Traversing through tree and checking for complete condition
    return(is_complete(root->left, 2*index+1, NumberofNodes) &&
            is_complete(root->right, 2*index+2, NumberofNodes));
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

// Driver code
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
   
    int index = 0;
    int NumberofNodes = count_nodes(root);
    printf("\nChecking if the tree is Complete Binary Tree or not - \n");
    if (is_complete(root, index, NumberofNodes)){
        printf("The Tree is complete Binary Tree\n");
    }

    else{
        printf("The Tree is not a complete Binary Tree\n");
    }

}


/*
 *Results : 
Tree is :
87 76 98 43 55 15 32
Checking if the tree is Complete Binary Tree or not -
The Tree is complete Binary Tree


 */
