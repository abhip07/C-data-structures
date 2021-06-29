#include<stdio.h>

#define N 10
int Stack1[N], Stack2[N];
int top1 = -1, top2 = -1;
int count = 0;

// Pushing elements in first stack
void Push1(int item){
    if (top1 == (N-1)){
        printf("Stack Ovetflow :(\n");    
    }

    else{
        top1++;
        Stack1[top1] = item;
    }
}

int Pop1(){
    if (top1 == -1 && top2 == -1){
        printf("The Stack is empty:(\n");
    }
    
    else{
        return Stack1[top1--];  // Post Decrement i.e decrement after returning value
    }

    return 0;
}

// pushing elements in second stack
void Push2(int item){
    if (top1 == (N-1)){
        printf("Stack Ovetflow :(\n");    
    }

    else{
        top2++;
        Stack2[top2] = item;
    }
}

int Pop2(){
    if (top1 == -1 && top2 == -1){
        printf("The Stack is empty:(\n");
    }
    
    else{
        return Stack2[top2--];  // Post Decrement i.e decrement after returning value
    }
    return 0;
}


void Enqueue(int item){
    Push1(item);
    count++;
}


void Dequeue(){
    int temp1, temp2;
    if (top1 == -1 && top2 == -1){
        printf("The Stack is empty:(\n");
    }

    // Popping all elements from Stack1 and pushing them in Stack2
    for (int i=0; i<count; i++){
        temp1 = Pop1();
        Push2(temp1);
    }

    // Popping top element from Stack2
    temp2 = Pop2();
    count--;

    // Pushing elements back in Stack1 from Satck2
    for (int i=0; i<count; i++){
        temp1 = Pop2();
        Push1(temp1);
    }

}

void Display(){
    printf("The Queue is : \n");
    for(int i = 0; i <= top1; i++){
        printf("%d ", Stack1[i]);
    }
    printf("\n");
}

// Driver code
int main(){
    Enqueue(21);
    Enqueue(65);
    Enqueue(34);
    Enqueue(89);
    Enqueue(87);
    Enqueue(67);
    Enqueue(43);
    Enqueue(99);
    Enqueue(78);
    Enqueue(32);

    Display();

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    printf("After Dequeing,");
    Display();
}

/*
 
Results  : 

The Queue is :
21 65 34 89 87 67 43 99 78 32
After Dequeing,The Queue is :
87 67 43 99 78 32
 
 */
