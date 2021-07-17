#include<stdio.h>
#include<stdlib.h>

#define size 10

typedef struct node{
    int value;
    struct node *next;
}Node;

// Initialize all keys(indexes) of hash table as NULL
Node *table[size];

void init(){
    for (int i=0; i<size; i++)
        table[i] = NULL;
}

// Hash Function
int hash(int data){
    return data % size;
}

// Inserting new elememt in hash table
void Insert(int item){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = item;
    new_node-> next = NULL;

    // Calculating Hash Key
    int key = hash(item);

    // NO collision
    if (table[key] == NULL)
        table[key] = new_node;
    
    // If collision occures
    else{
        // Adding the new_node at the begining of chain
        Node *temp = table[key];
        new_node->next = temp;
        table[key] = new_node;
    }
}

// deleting an item from hashtable
void delete(int item){
    int key = hash(item);

    // If first node in chain is to be deleted
    Node *temp = table[key];
    if (temp->value == item){
        table[key] = table[key]->next;
        free(temp);
    }

    else{
        while(temp){
            if(temp->value == item){
                Node* x = temp;
                temp = temp->next;
                free(x);
            }
            temp=temp->next;
        }
    }
}

// searching for an element in Hash Table
void search(int item){
    int key = hash(item);
    Node *temp = table[key];

    while(temp){
        if(temp->value == item)
            printf("Found\n");
        temp = temp->next;
    }
}

// Displaying the hash table
void display(){
    for (int i=0; i<size; i++){
        Node *temp = table[i];
        printf("table[%d] : ", i);

        while(temp){
            printf("%d --> ", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Drive Code

int main(){
    init();

    Insert(85);
    Insert(59);
    Insert(77);
    Insert(18);
    Insert(13);
    Insert(18);
    Insert(21);
    Insert(20);
    Insert(90);
    Insert(22);
    Insert(66);
    Insert(74);
    
    printf("checking if 22 is present : ");
    search(22);

    display();
    delete(22);
    printf("\nAfter Deleting 22 :\n");
    display();
}

/*
 * Results: 
checking if 22 is present : Found
table[0] : 90 --> 20 --> NULL
table[1] : 21 --> NULL
table[2] : 22 --> NULL
table[3] : 13 --> NULL
table[4] : 74 --> NULL
table[5] : 85 --> NULL
table[6] : 66 --> NULL
table[7] : 77 --> NULL
table[8] : 18 --> 18 --> NULL
table[9] : 59 --> NULL

After Deleting 22 :
table[0] : 90 --> 20 --> NULL
table[1] : 21 --> NULL
table[2] : NULL
table[3] : 13 --> NULL
table[4] : 74 --> NULL
table[5] : 85 --> NULL
table[6] : 66 --> NULL
table[7] : 77 --> NULL
table[8] : 18 --> 18 --> NULL
table[9] : 59 --> NULL

 */
