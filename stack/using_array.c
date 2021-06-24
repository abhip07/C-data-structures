// Stack Using Arrays (Static Memory allocation)

#include<stdio.h>
#include<stdlib.h>

#define N 10

/// Initializing an empty stack for 10 elements
int stack[N];
int top = -1;

int Is_Full(){
    if (top == (N-1))
        return 1;
    return 0;
}


int Is_Empty(){
    if (top == -1)
        return 1;
    return 0;
}

// Pushing elements into the satck
void Push(int x){
    if (Is_Full()){
        printf("Stack Overflow :(\n");
        return ;
    }

    top++;
    stack[top] = x;
}

// Popping elements from stack
void Pop(){
    if (Is_Empty()){
        printf("Stack Underflow:(\n");
        return ;
    }
    int t = stack[top];
    printf("%d is Popped\n", t);
    top--;
}

// Top element of the tack
void Top(){
    printf("%d\n", stack[top]);
}

// Displaying the stack

void Display(){
    if (Is_Empty()){
        printf("Stack Underflow:(\n");
        return ;
    }
    printf("The Stack is : \n");
    for (int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");

}


// Driver Code

int main(){
    Push(90);
    Push(43);
    Push(69);
    Push(12);
    Push(97);
    Push(54);
    Push(4);
    Push(32);
    Push(12);
    Push(28);
    Display();

    Pop();
    Pop();
    Pop();
    Pop();
    printf("After Popping, ");
    Display();

}
/* Results : 
 
28 12 32 4 54 97 12 69 43 90

28 is Popped
12 is Popped
32 is Popped
4 is Popped
After Popping, stack :
54 97 12 69 43 90

*/
