#include<stdio.h>
#include<stdlib.h>

// Structure of the single node in linked-list
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node *head = NULL;

// Checking if the tree is empty
int Is_Empty(){
    if (head == NULL)
        return 1;
    return 0;
}

// Length of linked list
int Length(){
    Node *temp = head;
    if (Is_Empty()){
        printf("List is empty...!\n");
        return 1;
    }

    int count = 1;
    temp = temp -> next;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    printf("The length of list is : %d\n", count);
    return 0;
}

// Displaying the linkde-list
void Display_List(){
    Node *temp = head;

    if(Is_Empty()){
        printf("The List is empty\n");
        return ;    
    }

    while (temp -> next != NULL){
        printf("%d <-> ", temp -> data);
        temp = temp -> next;
    }

    printf("%d\n", temp -> data);
}

// Inserting at beginning of linkde-list
void Insert_At_Beginnig(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> next = head;
    new_node -> prev = NULL;
    head = new_node;
}

// Inserting at end of linkde-list
void Insert_At_End(int item){
    Node *new_node = (Node*)malloc(sizeof(Node)), *temp;

    new_node -> data = item;

    if(head == NULL){
        head = new_node;
        head -> next = NULL;
        head -> prev = NULL;
        return ;
    }
    temp = head;

    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = new_node;
    new_node -> prev = temp;
    new_node -> next = NULL;
}

// Inserting at given index (postion) in linkde-list
void Insert_At_Position(int pos, int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *temp = head;

    new_node -> data = item;
    new_node -> next = NULL;
    new_node -> prev = NULL;
   if(head == NULL){
        head = new_node;
        head -> next = NULL;
        head -> prev = NULL;
        return ;
    }
    int count = 1;
    while (temp != NULL && count != (pos - 1)){
        temp = temp -> next;
        count++;
    }
    
    if (temp == NULL){
        printf("%d is not present in list :(\n", pos);
        return ;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
    new_node -> prev = temp;
}

// Deleting first node in linkde-list
void Delete_From_Beginning(){
    if (Is_Empty()){
        printf("The List is Empty...!");
        return ;
    }
    else{
        Node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;
        free(temp);
    }

}

// Deleting last node in linkde list
void Delete_From_End(){
    if (Is_Empty()){
        printf("The List is Empty");
    }

    Node *temp = head, *previous;
    
    while(temp -> next != NULL){
        previous = temp;
        temp = temp -> next;
    }

    previous -> next = temp -> next;
    temp -> next = NULL;
    temp -> prev = NULL;
    free(temp);
}

// Deleting Specifies value from the linked-list
void Delete_Particular_Value(int value){
    
    if (Is_Empty()){
        printf("The list is Empty...!\n");
        return;
    }
    
    // if first noed is given value
    Node *temp = head , *previous;
    if (head -> data == value){
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        free(temp);
        return;
    }
    
    while (temp -> next != NULL && temp -> data != value){
        previous = temp;
        temp = temp -> next;
    }
    
    // After iterating through whole linked list
    if (temp == NULL){
        printf("%d is not present in list :(\n", value);
    }

    previous -> next = temp -> next;
    temp -> next = NULL;
    temp -> prev = NULL;
    free(temp);

}

// Driver code
int main(){
    Insert_At_Beginnig(43);
    Insert_At_Beginnig(98);
    Insert_At_Beginnig(23);

    Insert_At_End(12);
    Insert_At_End(32);
    Insert_At_End(69);

    Insert_At_Position(2, 45);
    Insert_At_Position(7, 98);
    Insert_At_Position(3, 6969);

    printf("The Linkde list is : \n");
    Display_List();

    Delete_From_Beginning();
    Delete_From_Beginning();
    
    Delete_From_End();
    Delete_From_End();
    
    Delete_Particular_Value(69);
    Delete_Particular_Value(43);
   
    printf("After Deleting some nodes : \n");   
    Display_List();

    return 0;
}

/*
 * Result 
 
The Linkde list is :
23 <-> 45 <-> 6969 <-> 98 <-> 43 <-> 12 <-> 32 <-> 98 <-> 69
After Deleting some nodes :
6969 <-> 98 <-> 12

*/
