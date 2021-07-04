#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

// Checking if List is empty
int Is_Empty(){
    if (head == NULL)
        return 1;

    return 0;

}

// calculating length of linked list
int length(){     // iterative
    int count = 0;
    Node *temp = head;

     while (temp -> next != NULL){
         count++;
         temp = temp -> next;
    }
    count++;
    printf("length is : %d\n", count);

    return 0;


}

// Displauing all elements of Linked lIst

void Display_List(){

    Node *temp = head;
    if (Is_Empty()){
        printf("List is Empty\n");
        return ;
    }


    while (temp -> next != NULL){
        printf("%d ->", temp -> data);
        temp = temp -> next;
    }

    printf("%d\n", temp -> data);
}


// Inserting Data at beginnig
void Insert_At_Beginning(int item){

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> next = head;
    head = new_node;
}

// Inserting At The end of Linked List
void Insert_At_End(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *temp = head;

    new_node -> data = item;
    new_node -> next = NULL;

    // If list is empty
    if (Is_Empty()){
        head = new_node;
        return ;
    }

    while(temp -> next != NULL)
        temp = temp -> next;

    temp -> next = new_node;

}

// Inserting after the Particular value In Linked List
void Insert_After_iValue(int ivalue, int item){

    Node *temp = head;

    while (temp != NULL && temp -> data != ivalue)
        temp = temp -> next;

    if (temp == NULL)
        printf("%d is not in List\n", ivalue);

    else{
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = item;
        new_node -> next = temp -> next;
        temp -> next = new_node;
    }

}

// Deleting First Element of Lnked List

void Delete_At_Beginning(){

    if (Is_Empty()){
        printf("List is Empty..!\n");
        return ;
    }

    else{
        Node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        free(temp);
    }
}

// Deleting LAst Velement of Linked Lsit
void Delete_At_End(){

    if (Is_Empty()){
        printf("List is Empty..!\n");
        return ;  // "return ;" terminates execution of function

    }
    // If there is single element in list
    Node *temp = head, *prev;

    if (temp -> next == NULL){
        temp = NULL;
        free(temp);
        return ;

    }

    while (temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }

    prev -> next = temp -> next; // Here prev -> next is temp itself
    temp -> next = NULL;
    free(temp);

}

// Deleting Given value from Linked List
void Delete_Particular_Value(int value){

    if (Is_Empty())
        printf("List is Empty..!");

    Node *temp = head, *prev;

    if (head -> data == value){
        head = head -> next;
        temp -> next = NULL;
        free(temp);
        return ;
    }

    while (temp != NULL && temp -> data != value){

        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL){
        printf("%d is not present in List\n", value);
    }
    else{

        prev -> next = temp -> next;
        temp -> next = NULL;
        free(temp);
    }

}

// Reversing the Linked List

void Reverse_Linked_List(){  // Iterative
        Node *current = head, *prev = NULL,  *next_node = head;

        while(next_node != NULL){
            next_node = current -> next;
            current -> next = prev;
            prev = current;
            current = next_node;

        }

        head = prev;

        printf("Reversed Linked list is : \n");
        Display_List();

}


int main(){
        Insert_At_Beginning(17);
        Insert_At_Beginning(32);
        Insert_At_Beginning(21);
        Insert_At_Beginning(7);
        Insert_At_Beginning(8);
        Insert_At_Beginning(2);


        Insert_At_End(99);
        Insert_At_End(62);
        Insert_At_End(42);
        Insert_At_End(58);
        Insert_At_End(74);
        Insert_At_End(53);


    Insert_After_iValue(99, 896);
    Insert_After_iValue(6, 854);
    Insert_After_iValue(58, 148);
    
    printf("The Linked List is : \n");
    Display_List();

    Delete_At_Beginning();
    Delete_At_Beginning();
    Delete_At_Beginning();



    Delete_At_End();
    Delete_At_End();


    Delete_Particular_Value(99);
    Delete_Particular_Value(57);
    
    printf("After Deleting some nodes, ");
    printf("Final List : \n");
    Display_List();
    // Length();

    Reverse_Linked_List();



    return 0;
}

/*
 * Results 

6 is not in List
The Linked List is :
2 ->8 ->7 ->21 ->32 ->17 ->99 ->896 ->62 ->42 ->58 ->148 ->74 ->53
57 is not present in List
After Deleting some nodes, Final List :
21 ->32 ->17 ->896 ->62 ->42 ->58 ->148
Reversed Linked list is :
148 ->58 ->42 ->62 ->896 ->17 ->32 ->21

*/
