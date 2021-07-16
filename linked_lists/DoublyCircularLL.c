#include<stdio.h>
#include<stdlib.h>

// initializint the structure of doubly circular linked list
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL, *tail = NULL;

// checking for empty condition
int Is_Empty(){
    if (head == NULL)
        return 1;

    return 0;

}

// calculating length of linked list
int Length(){     // iterative
    int count = 0;
    Node *temp = head;

     while (temp -> next != head){
         count++;
         temp = temp -> next;
    }
    count++;
    printf("length is : %d\n", count);
    return count;

    return 0;


}

// Displaying the linked list
void Display_List(){

    if (Is_Empty()){
        printf("List is Empty\n");
        return ;
    }

    Node *temp = head;
    
    printf("The Linked List is : \n");
    while (temp -> next != head){
        printf("%d ->", temp -> data);
        temp = temp -> next;
    }

    printf("%d\n", temp -> data);
}

// Inserting new nodes at the beginning of lnked list
void Insert_At_Beginning(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node -> data = item;
    new_node -> next = new_node -> prev = NULL;
    
    if (Is_Empty()){
        head = tail = new_node;
        head -> next = new_node;
        head -> prev = new_node;
        return;
    }

    else{
        tail -> next  = new_node;
        new_node -> next = head;
        new_node -> prev = tail;
        head = new_node;
        return;
    }
}

// Inserting new nodes at the end of lnked list
void Insert_At_End(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node -> data = item;
    new_node -> next = new_node -> prev = NULL;
    
   if (Is_Empty()){
        head = tail = new_node;
        head -> next = new_node;
        head -> prev = new_node;
        return;
    }

   else{
       tail -> next = new_node;
       new_node -> next = head;
       new_node -> prev = tail;
       tail = new_node;
   }
}

// Inserting new node at location after a node 'i'
void Insert_After_ivalue(int ivalue, int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *temp = head;
    
    new_node -> data =item;
    if (Is_Empty()){
        head = tail = new_node;
        head -> next = new_node;
        head -> prev = new_node;
        return;
    }
    
    while (temp != tail && temp -> data != ivalue){
        temp = temp -> next;
    }

    if (temp == tail){
        printf("%d is not present in List :(\n", ivalue);
    }

    else{

        new_node -> next = temp -> next;
        temp -> next = new_node;
        new_node -> prev = temp;
    }
}

// Deleting the node at beginning of lnked list
void Delete_At_Beginning(){

    if (Is_Empty()){
        printf("The List is Empty .. !\n");
        return;
    }

    else{
        Node *temp = head;
        head = head -> next;
        tail -> next = head;
        head -> prev = tail;
        temp -> next = temp -> prev = NULL;
        free(temp);
    }
}

// Deleting the node at end of lnked list
void Delete_At_End(){
    if (Is_Empty()){
        printf("The List is Empty .. !\n");
        return;
    }

    Node *temp = head;

    if (temp -> next == NULL){
        temp = NULL;
        temp ->next = temp -> prev = NULL;
        free(temp);
        return;
    }

    else{
        while(temp -> next != tail){
            temp = temp -> next;
        }

        temp -> next = tail -> next;
        tail -> next = tail -> prev = NULL;
        free(tail);
        tail = temp;
        
    }
    
}

// Deleting gien value from anywhere in linkde-list
void Delete_Particular_Value(int value){
    if (Is_Empty()){
        printf("The List is Empty .. !\n");
        return;
    }

    Node *temp = head, *previous;
    
    if (temp -> next == NULL){
        temp = NULL;
        temp -> next = temp -> prev = NULL;
        free(temp);
        return;
    }

    while (temp -> next != tail -> next && temp -> data != value){
        previous = temp;
        temp = temp -> next;
    }

    if (temp == tail){
        printf("%d is not present in list :(\n", value);
        return;
    }

    previous -> next = temp -> next;
    free(temp);
}

// Driver code
int main(){
    Insert_At_Beginning(54);
    Insert_At_Beginning(42);
    Insert_At_Beginning(5);
    Insert_At_Beginning(56);
    Insert_At_Beginning(69);
    Insert_At_Beginning(84);
    Insert_At_Beginning(82);
    Insert_At_Beginning(74);
    Insert_At_Beginning(159);

    Insert_At_End(95);
    Insert_At_End(25);
    Insert_At_End(152);
    Insert_At_End(74);

    Insert_After_ivalue(42, 654);
    Insert_After_ivalue(32, 213);
    Insert_After_ivalue(56, 1254);
    Insert_After_ivalue(152, 4);

    Display_List();
    
    printf("After Deleting: \n");

    Delete_At_Beginning();
    Delete_At_Beginning();
    Delete_At_Beginning();

    Delete_At_End();
    Delete_At_End();
    Delete_At_End();
    Display_List();
    Delete_Particular_Value(5);
    Delete_Particular_Value(69);
    Delete_Particular_Value(213);
    Delete_Particular_Value(6969);

    Display_List();




    return 0;
}

/*

 * Results 
32 is not present in List :(
The Linked List is :
159 ->74 ->82 ->84 ->69 ->56 ->1254 ->5 ->42 ->654 ->54 ->95 ->25 ->152
 ->4 ->74
After Deleting:
The Linked List is :
84 ->69 ->56 ->1254 ->5 ->42 ->654 ->54 ->95 ->25
213 is not present in list :(
6969 is not present in list :(
The Linked List is :
84 ->56 ->1254 ->42 ->654 ->54 ->95 ->25

 */
