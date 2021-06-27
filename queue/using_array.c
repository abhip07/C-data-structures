// Statc memory allocation
#include<stdio.h>

#define N 10

int Queue[N];
int front = -1;
int rear = -1;

void Enqueue(int item){
    if (rear == (N-1)){
        printf("Can't Enqueue %d - The Queue is Full :(...\n", item);
        return ;
    }

    else if(front == -1 && rear == -1){
        front = 0;
        rear++;
        Queue[rear] = item;
    }

    else{
        rear++;
        Queue[rear] = item;
    }
}

void Dequeue(){
    if (rear == -1 && front == -1){
        printf("The Queue is Empty :(..\n");
    }
    
    else{
        front++;

        if (front > rear){
            front = rear == -1;
        }
     
    }
}

void Display(){
    if (rear == -1 && front == -1){
        printf("The Queue is Empty :(..\n");
    }
    printf("The Queue is : \n");
    while (front != rear){
        printf("%d ", Queue[front]);
        front++;
    }
    printf("%d\n", Queue[rear]);

}


int main(){
    Enqueue(13);
    Enqueue(97);
    Enqueue(77);
    Enqueue(75);
    Enqueue(38);
    Enqueue(95);
    Enqueue(652);
    Enqueue(54);
    Enqueue(33);
    Enqueue(43);
    Display();

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    
    printf("After dequeing 5 elements, ");
    Display();

    return 0;
}


/* 
Results: 

The Queue is :
13 97 77 75 38 95 652 54 33 43
After dequeing 5 elements, The Queue is :
38 95 652 54 33 43

*/
