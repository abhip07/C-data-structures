// Maximum heap implementation

#include<stdio.h>

#define N 100

int heap[N], size;

// Initializing 0th indexed element as 0 (We will not it anywhere) for the 
// sake of simplicity when we will deal with child nodes

void Init(){
    size = 0;
    heap[0] = 0;
}

void Swap_up(int index);

void Insert(int item){
    size++;
    heap[size] = item;
    Swap_up(size);
}

// compairing and swapping recently inserted element, upward in tree
void Swap_up(int index){
    int temp;
    while (index/2 > 0){
        if (heap[index] > heap[index/2]){
            temp = heap[index];
            heap[index] = heap[index/2];
            heap[index/2] = temp;
        }
        index = index/2;
    }
}

void Swap_down(int index);


void Delete_value_at_index(int index){
    index++;   // Because We have initilized 0th index as 0
    int temp = heap[index];
    heap[index] = heap[size];
    heap[size] = temp;
    size--;
    Swap_down(index);
}

// compairing and swapping recently inserted element, down in tree
void Swap_down(int index){
    int temp, bigger_child;

    while (size >= index * 2){
        if (index*2 == size){
            bigger_child = index * 2;
        }

        else{
            if (heap[2*index] > heap[2*index+1]){
                bigger_child = 2*index;
            }

            else{
                bigger_child = 2*index+1;
            }
        }

        if (heap[index] < heap[bigger_child]){
            temp = heap[index];
            heap[index] = heap[bigger_child];
            heap[bigger_child] = temp;
        }

        index = bigger_child;
    }
}

void max(){
    printf("The maximum element is : %d\n", heap[1]);
}

void Display(){
    printf("The Heap  is :\n");
    for(int i = 1 ; i <= size ; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main(){
    Init();

    Insert(43);
    Insert(71);
    Insert(23);
    Insert(90);
    Insert(57);
    Insert(76);
    Insert(21);
    Insert(54);
    Insert(30);
    Insert(86);
    Insert(98);

    Display();

    Delete_value_at_index(0);
    Delete_value_at_index(5);
    Display();
}

/*
 * Result : 

 The Heap  is :
98 90 76 54 86 23 21 43 30 57 71
The Heap  is :
90 86 76 54 71 57 21 43 30

*/
