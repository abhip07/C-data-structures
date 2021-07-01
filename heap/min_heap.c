// Implementing minimum heap 

#include<stdio.h>

#define N 100

int heap[N], size;

// Initializing 0th indexed element as 0 (We will not it anywhere) for the 
// sake of simplicity when we deal with child nodes

void Init(){
    heap[0] = 0;
    size = 0;
}


// defining functions for future use
void Swap_up(int index);
void Swap_down(int index);


// Inserting an element in heap
void Insert(int item){
    size++;
    heap[size] = item;  // Inserting as last element
    Swap_up(size);
}

// compairing and swapping recently inserted element, down in tree
void Swap_up(int index){
    int temp;
    while(index / 2 > 0){
        if(heap[index] < heap[index/2]){
            temp = heap[index];
            heap[index] = heap[index/2];
            heap[index/2] = temp;
        }
        index = index / 2;
    }
}

// deleting an element from heap
void Delete_value_at_index(int index){
    index++; // Because we initialized 0th index as 0
    int temp = heap[index];
    heap[index] = heap[size];
    heap[size] = temp; // swapped last element with element to be deleted
    size--;
    Swap_down(index);
}


// comparing and swapping the element down which we have replace while deletion
void Swap_down(int index){
    int temp, smaller_child;

    while(size >= index*2){
        if (index*2 == size){
            smaller_child = index * 2;
        }

        else{
            if(heap[2*index] < heap[2*index+1]){
                smaller_child = 2*index;
            }
            else{
                smaller_child = 2*index+1;
            }
        }

        if(heap[index] > heap[smaller_child]){
            temp = heap[index];
            heap[index] = heap[smaller_child];
            heap[smaller_child] = temp;
        }
        
        index = smaller_child;
    }

}


void root(){
    printf("The root of heap is : %d\n", heap[1]);
}

void Display(){
    printf("The heap is :\n");
    for(int i = 1; i <= size; i++){
        printf("%d ", heap[i]);
    }

    printf("\n");
}


// Driver Code
int main(){
    Init();

    Insert(34);
    Insert(16);
    Insert(23);
    Insert(76);
    Insert(87);
    Insert(67);
    Insert(65);
    Insert(34);
    Insert(10);
    Insert(42);

    Display();

    printf("After Deleting Elements, ");
    Delete_value_at_index(1);
    Delete_value_at_index(5);
    Delete_value_at_index(3);

    Display();
    root();
}

/*
 
 * Results
 
The heap is :
10 16 23 34 42 67 65 76 34 87
After Deleting Elements, The heap is :
10 34 23 76 42 87 65
The root of heap is : 10

*/
