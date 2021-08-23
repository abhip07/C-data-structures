/* In Binary Search Tree :
    for any node except leaf nodes - 
    -> All nodes of left subtree are smaller than that node
    -> All nodes of right subtree are grearer than that node
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;


// creating node
Node *create_node(int item){
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

Node *Insert(Node *root, int item){
    // If tree is empty 
    if (root == NULL) root = create_node(item);

    else if (item < root -> data)
        root -> left = Insert(root -> left, item);
    
    else root -> right = Insert(root -> right, item);
    
    return root;
}


Node *Inorder_Sucessor(Node *node){
    while (node -> left != NULL)
        node = node -> left;

    return node;
}

Node *Inorder_Predecessor(Node *node){
    while (node -> right != NULL)
        node -> right = node -> right;
    return node;
}

Node *Delete(Node *root, int item){
    if(root == NULL){
        return root;
    }
    if(item < root->data){
        root -> left = Delete(root->left, item);
    }

    else if(item > root->data){
        root -> right = Delete(root->right, item);
    }

    // Deleting the root
    else{
        // If root has no children
        if (root -> left == NULL && root -> right == NULL){
            root = NULL;
            free(root);
        }
        // If tree has only one child
        else if (root->left == NULL){
            Node *temp = root;
            root = root -> right;
            free(temp);
        }

        else if (root->right == NULL){
            Node *temp = root;
            root = root -> left;
            free(temp);
 
        }
        
        // If both children exists
        // Swapping root with its Inorder Sucessor
        else {
            Node *temp = Inorder_Sucessor(root->right);
            root -> data = temp -> data;
            root -> right = Delete(root -> right, temp -> data);
        }



        /*
          Using Inorder Predecessor
         *  Node *temp = Inorder_Predecessor(node->>left);
         *  node->data = temp -> data;
         *  root -> right = Delete(root -> right, temp -> data);
        
        */
    }
    return root;
}

// Traversing the Tree

void Inorder(Node *root){
    if (root == NULL)
        return;
    Inorder(root -> left);
    printf("%d ", root->data);
    Inorder(root -> right);
    
}

void Preorder(Node *root){
    if (root == NULL)
        return;

    printf("%d ", root -> data);
    Preorder(root -> left);
    Preorder(root -> right);
}

void Postorder(Node *root){
    if (root == NULL)
        return;
    Postorder(root -> left);
    Postorder(root -> right);
    printf("%d ", root -> data);
}

// Driver code
int main(){
    
    Node *root = NULL;
    root = Insert(root, 32);
    root = Insert(root, 108);
    root = Insert(root, 76);
    root = Insert(root, 55);
    root = Insert(root, 12);
    root = Insert(root, 54);
    root = Insert(root, 89);
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 2);
    root = Insert(root, 65);
    
    printf("Postorder Traversal :\n");
    Postorder(root);
    printf("\n");
    printf("Inorder Traversal(sorted form)\n");
    Inorder(root);
    printf("\n");
    Delete(root, 108);
    Delete(root, 8);
    printf("After deleting 108, 8 : \n");
    Postorder(root);
    printf("\n");
    printf("Inorder Traversal(sorted form)\n");
    Inorder(root);
    printf("\n");

    return 0;
}

/*

 * Results : 
Postorder Traversal :
2 3 8 12 54 65 55 89 76 108 32
Inorder Traversal(sorted form)
2 3 8 12 32 54 55 65 76 89 108
After deleting 108, 8 :
2 3 12 54 65 55 89 76 32
Inorder Traversal(sorted form)
2 3 12 32 54 55 65 76 89



*/
