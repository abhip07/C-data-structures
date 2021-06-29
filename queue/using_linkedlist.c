// Dynaic Memory Allocation

#include<stdio.h>
#include<stdlib.h>

// structure of a single item in queue
typedef struct node{
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void Enqueue(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    
    new_node -> data = item;
    new_node -> next = NULL;

    if (front == NULL && rear == NULL){
        front = rear = new_node;

        return;
    }

    else{
        rear -> next = new_node;
        rear = new_node;
    }
}

void Dequeue(){
    if (front == NULL && rear == NULL){
        printf("The Queue is Empty ;(...\n");
        return;
    }

    else if (front -> next == NULL){
        Node *temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
        return;
    }

    else{
        Node *temp = front;
        front = temp -> next;
        free(temp);

    }

}

int Display(){
    Node *temp = front;

    printf("The Queue is : \n");
    while (temp != NULL){
        printf("%d ", temp ->data);
        temp = temp -> next;
    }

    printf("\n");

    return 0;
}

// Driver code
int main(){
    Enqueue(12);
    Enqueue(76);
    Enqueue(65);
    Enqueue(45);
    Enqueue(32);
    Enqueue(99);
    Enqueue(23);
    Enqueue(65);

    Display();

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    printf("After Dequeing, ");

    Display();
}

/*
 The Queue is :
12 76 65 45 32 99 23 65
After Dequeing, The Queue is :
32 99 23 65

*/
