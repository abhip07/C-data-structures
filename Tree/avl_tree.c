
/* AVL Tree (Adelson, Velski & Landis Tree)

- It is a self balancing binary search tree.
- In this tree, each node carries extra information called a Balance Factor.
- The value of Balance Factor is either -1, 0, or 1

# Balance Factor
- Balance factor is the difference in heights of left and right subtree of that node.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
    int height;
} Node;

// creating a new node
Node *new_node(int item){
    Node *new_node = (Node* )malloc(sizeof(Node));
    new_node -> data= item;
    new_node-> left = NULL;
    new_node->right = NULL;
    new_node -> height = 1;
    return new_node;
}

// Calculating the height of current node
int height(Node *node){
    if (node == NULL)
        return 0;
    return (node->height);
}

// Calculating the balance factor
int balance_factor(Node *node){
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

int max(int a, int b){
    return (a>b)?a:b;

    /*
     if(a > b){
        return a;
    }
    else{
        return b;
    }
    */

}

// Left Rotation
Node*  rotate_left(Node *node){
    Node* new_root = node -> right;
    Node* temp_node = new_root -> left;

    new_root->left = node;
    node -> right = temp_node;

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));
    
    return new_root;
}

// Right Rotation
Node* rotate_right(Node *node){
    Node *new_root = node -> left;
    Node *temp_node = new_root -> right;

    new_root -> right = node;
    node->left = temp_node;

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->left));

    return new_root;
}

Node *Insert(Node *root, int item){
    if (root == NULL)
        return new_node(item);

    if (root -> data < item)
        root->right = Insert(root->right, item);
    else if (root->data > item)
        root->left = Insert(root->left, item);
    else
     return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int Balance_Factor = balance_factor(root);

    // If height of left subtree is greater
    if (Balance_Factor > 1){
        if (item < root->left->data){
            return rotate_right(root);
        }
        else{
            root->left = rotate_left(root->left);  // left-right rotate
            return rotate_right(root);
        }
    }

    // If height of right subtree is greater
    if (Balance_Factor < -1){
        if(item > root->right->data){
            return rotate_left(root->right);
        }
        else{
            root->right = rotate_right(root->right); // right-left rotate
            return rotate_left(root);
        }
    }
    return root;
}

// Finding Inorder Sucessor
Node *sucessor(Node *node){
    while (node->left != NULL)
        node = node->left;

    return node;
}

Node *delete(Node *root, int item){
    if (root==NULL)
        return root;

    if (item < root->data)
        root->left = delete(root->left, item);
    
    else if (item > root->data)
        root->right = delete(root->right, item);
    
    // Deleting the root
    else{
        // If root has no children 
        if(root->right==NULL && root->left==NULL){
		    free(root);
		    root = NULL;
		}

        // If root has only right child
        else if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }

        // If root has only left child
        else if (root->right == NULL){
            Node *temp = root -> left;
            free(root);
            return temp;
        }

        // If both children exists
        // Swapping root with its Inorder Sucessor
        else{
            Node *temp = sucessor(root->right);
            root->data = temp->data;
            root -> right = delete(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int Balance_Factor = balance_factor(root);
    
    // If balance factor of left subtree is greater
    
    if (Balance_Factor > 1){
    // If balance factor of left child is greater
        if (balance_factor(root->left) >= 0){
            return rotate_right(root->left);
        }

    // if balance factor of right child is greater
        else{
            root->left = rotate_left(root->left);
            return rotate_right(root);
        }
    }

    // If balance factor of right subtree is greater
    if (Balance_Factor < -1){


    // if balance factor of right child is greater
        if(balance_factor(root->right) <= 0){
            return rotate_left(root->right);
        }

    // if balance factor of left child is greater
        else{
            root->right = rotate_right(root->right);
            return rotate_left(root);
        }
    }
    
    return root;
}

// Traversing therough tree
void Inorder(Node *root){
    if (root==NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

// Driver code
int main(){
    Node *root=NULL;
    root =  Insert(root, 21);
    root =  Insert(root, 54);
    root =  Insert(root, 47);
    root =  Insert(root, 87);
    root =  Insert(root, 23);
    root =  Insert(root, 90);
    root =  Insert(root, 65);
    root =  Insert(root, 71);
    root =  Insert(root, 89);
    root =  Insert(root, 59);
    root =  Insert(root, 77);
    printf("The Avl Tree in inorder traversal is :\n");
    Inorder(root);
    printf("\n");

    delete(root, 21);
    delete(root, 87);
    printf("After deleting 21 and 87: \n");
    Inorder(root);
    printf("\n");

    return 0;
}

/*
Results : 
The Avl Tree in inorder traversal is :
21 23 47 59 65 71 77 87 89 90
After deleting 21 and 87:
23 47 59 65 71 77 89 90
 
*/
