// Singly Circular Lnked List

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = NULL, *tail = NULL;

int Is_Empty(){
    if (tail == NULL){
        return 1;
    }
    return 0;
}

int Length(){
    int count = 0;
    Node *temp = head;

    while (temp -> next != head){
        count++;
        temp = temp -> next;
    }

    count++;
    printf("Length of list is : %d\n", count);
    return count;
}

void Display_List(){
    if (Is_Empty()){
        printf("The list is empty");
        return ;
    }
    printf("The Linked List is : \n");

    Node *temp = head;
    printf("%d ->", temp -> data);
    while (temp -> next != tail){
        temp = temp -> next;
        printf("%d ->", temp -> data);
    }
    temp = temp -> next;
    printf("%d\n", temp -> data);
}


void Insert_At_Beginning(int item){

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> next = NULL;

    // If List Is Empty
    if(head == NULL){
        head = new_node;
        tail = new_node;
        head -> next = new_node;
        return ;
    }

    // If list is not empty
    if(tail != NULL){
        tail -> next = new_node;
        new_node -> next = head;
        head = new_node;
        return ;
    }


}

void Insert_At_End(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node -> data = item;
    new_node -> next = NULL;
    // If List is empty

    if (tail == NULL){
       head = new_node;
       tail = new_node;
       head -> next = new_node;
       return ;
    }

    // If list is not empty

    if (tail != NULL){
        tail -> next = new_node;
        new_node -> next = head;
        tail = new_node;
    }
}

void Insert_After_iValue(int ivalue, int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *temp = head;

    new_node -> data = item;
    new_node -> next = NULL;

    // If List is empty
    if (tail == NULL){
       head = new_node;
       tail = new_node;
       head -> next = new_node;
       return ;
    }

    while (temp != tail && temp -> data != ivalue){
        temp = temp -> next;
    }

    if (temp == tail)
        printf("%d is not in List\n", ivalue);

    else{

        new_node -> next = temp -> next;
        temp -> next = new_node;
    }
}

void Delete_At_Beginning(){
    if (head == NULL && tail == NULL){
        printf("List is Empty");
    }

    else{
            Node *temp = head;
            head = head -> next;
            tail -> next = head;
            temp -> next = NULL;
            free(temp);
    }
}


void Delete_At_End(){
    if (Is_Empty()){
        printf("List is Empty");
        return ;
    }

    Node *temp = head, *prev;

    // If only one element in list
    if (temp -> next == NULL){
        temp = NULL;
        free(temp);
        return ;
    }

    while (temp -> next != tail -> next){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = tail -> next;
    tail = prev;
    free(temp);
}

void Delete_Particular_Value(int value){

    if (Is_Empty()){
        printf("List is Empty");
        return ;
    }

    Node *temp = head, *prev;

     if (temp -> next == NULL){
        temp = NULL;
        free(temp);
        return ;
    }

    while (temp -> next != tail -> next  && temp -> data != value){
        prev = temp;
        temp = temp -> next;
    }

    if (temp == tail){
        printf("%d is not present in List\n", value);
    }

    else{
        prev -> next = temp -> next;
        free(temp);
    }
}

// Reversing Singly Circular Lnked list
void Reverse_Linked_List(){
    Node *temp = head, *prev, *next_node = temp -> next;

    if (Is_Empty()){
        printf("List is empty\n");
        return ;
    }


    if (temp -> next == NULL){
        printf("%d -> ", temp -> data);
        return ;
    }


    while (temp != tail){
        prev = temp;
        temp = next_node;
        next_node = temp -> next;
        temp -> next = prev;
    }

    next_node -> next = tail;
    tail = next_node;

    printf("After Reversing ,");
    Display_List();
    printf("Tail Node : %d\n", tail -> data);
}

// Driver code
int main(){
    Insert_At_Beginning(43);
    Insert_At_Beginning(21);
    Insert_At_Beginning(8);
    Insert_At_Beginning(98);
    Insert_At_Beginning(41);
    Insert_At_Beginning(35);

    Insert_At_End(99);
    Insert_At_End(62);
    Insert_At_End(42);
    Insert_At_End(58);
    Insert_At_End(74);
    Insert_At_End(53);

    Insert_After_iValue(99, 896);
    Insert_After_iValue(6, 854);
    Insert_After_iValue(58, 148);

    printf("Before Deleting, ");
    Display_List();

    printf("Tail Node : %d\n", tail -> data);

    Delete_At_Beginning();
    Delete_At_Beginning();
    Delete_At_Beginning();

    Delete_At_End();
    Delete_At_End();

    Delete_Particular_Value(99);
    Delete_Particular_Value(57);
    Delete_Particular_Value(69);

    Display_List();
    Length();

    Reverse_Linked_List();

    return 0;

}

/*
 * Results
 
6 is not in List
Before Deleting, The Linked List is :
35 ->41 ->98 ->8 ->21 ->43 ->99 ->896 ->62 ->42 ->58 ->148 ->
74 ->53
Tail Node : 53
57 is not present in List
69 is not present in List
The Linked List is :
8 ->21 ->43 ->896 ->62 ->42 ->58 ->148
Length of list is : 8
After Reversing ,The Linked List is :
8 ->148 ->58 ->42 ->62 ->896 ->43 ->21 ->8
Tail Node : 8
 
 */
