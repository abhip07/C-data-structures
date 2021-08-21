#include<stdio.h>
#include<stdlib.h>

// Initializing the parameters of a single node
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

// initializing the root as null
Node *root = NULL;

// creating a new node

Node *create_node(int item){
    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

// traversing a tree using -> DFS

// Inroder Traversal
void Inorder(Node *root){

    if (root == NULL){
        return;
    }   
    Inorder(root -> left);
    printf("%d ", root-> data);
    Inorder(root -> right);
    return;
}

// Preorder Traversal
void Preorder(Node *root){

    if (root == NULL){
        return;
    }   
    printf("%d ", root-> data);
    Preorder(root -> left);
    Preorder(root -> right);
    return;
}

// Postorder Traversal
void Postorder(Node *root){

    if (root == NULL){
        return;
    }   
    Postorder(root -> left);
    Postorder(root -> right);
    printf("%d ", root-> data);
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
    root -> right -> right -> left = create_node(66);
    root -> left -> left -> right = create_node(33);

    printf("Inorder Traversal: \n");
    Inorder(root);
    printf("\n");

    printf("Preorder Traversal: \n");
    Preorder(root);
    printf("\n");

    printf("Postorder Traversal: \n");
    Postorder(root);
    printf("\n");
}

/*
 * RESULT : 
Inorder Traversal:
87 33 76 98 43 55 15 66 32
Preorder Traversal:
43 76 87 33 98 15 55 32 66
Postorder Traversal:
33 87 98 76 55 66 32 15 43


*/
