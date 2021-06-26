// Dynamic Memory Allocation

#include<stdio.h>
#include<stdlib.h>

// Initializing the node in stack
typedef struct node{
    int data;
    struct node *next;
}Node;

Node *top = NULL;

void Push(int x){
    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node -> data = x;
    new_node -> next = top;
    top = new_node;
}

void Pop(){
    Node *temp =  top;
    if (top == NULL){
        printf("The List is Empty :(\n");
    }
    
    top = temp -> next;
    printf("Popped item = %d\n", temp -> data);
    free(temp);
}

// Printing value of topmost element in stack
void Peek(){
    if (top == NULL){
        printf("The List is Empty :(\n");
    }
    else{
        printf(" -- The top element is: %d\n", top -> data);
    }

}

void Display(){
    Node *temp = top;
    
    if (top == NULL){
        printf("The List is Empty :(\n");
    }
    printf("The Stack is : \n");
    while (temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    Push(43);
    Push(53);
    Push(19);
    Push(21);
    Push(94);
    Push(26);
    Push(57);
    Push(76);

    Display();
    Pop();
    Pop();
    Pop();
    Pop();

    Display();
}


/* 
 Results : 
 
The Stack is :
76 57 26 94 21 19 53 43
Popped item = 76
Popped item = 57
Popped item = 26
Popped item = 94
The Stack is :
21 19 53 43

*/
