#include<stdio.h>
/*
 * Depth first Search or Depth first traversal is a 
recursive algorithm for searching all the vertices of a 
graph or tree data structure.

*/

#include<stdlib.h>
#include<stdlib.h>
#include<stdbool.h> // necessary for using bool datatype

// size of stack
#define size 10

// structure of vertex in the graph
typedef struct Vertex{
    char name;
    bool visited;
}vertex;

// Initializing stack for dfs
int stack[size];
int top=-1;

// Array of vertices 
vertex* vertices_list[size];

//adjacency matrix
int adj_matrix[size][size];

// total vertices
int vert_count = 0;

// Pushing elements in stack
void push(int item){
    stack[++top] = item;
}

// popping an element from stack
int pop(){
    return stack[--top];
}

// top of the stack
int peek(){
    return stack[top];
}

int is_empty(){
    return top==-1;
}

// Adding vertex in the vertex list of graph
void add_vertex(char label){
    vertex* new_vertex = (vertex*)malloc(sizeof(vertex));
    new_vertex -> name = label;
    new_vertex -> visited = false;
    
    vertices_list[vert_count++] = new_vertex;
}

// add edge to adjacency matrix (edge array)
void add_edge(int start, int end){
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

// displaying vertex
void display_vertex(int index){
    printf("%c \n", vertices_list[index]->name);
}

// unvisited vartices
int unvisited(int index){
    for (int i=0; i<vert_count; i++){
        if(adj_matrix[index][i] == 1 &&
                vertices_list[i]->visited == false){
            return i;
        }
    }

    return -1;
}

void DFS(){

    // marking first vertex as visited
    vertices_list[0]->visited = true;
    // displaying first vertex
    display_vertex(0);
    
    // pushing index of visited vertex in stack
    push(0);

    while(!is_empty()){
        // getting unvisited vertex from top
        int not_visited = unvisited(peek());
        
        // if no unvisited vertex
        if (not_visited == -1)
            pop();
        else{
            vertices_list[not_visited]->visited = true;
            display_vertex(not_visited);
            push(not_visited);
        }
    }

    for (int i=0; i<vert_count; i++){
        vertices_list[i]->visited = false;
    }
}

// Driver Code
int main(){

// Initializing each element of adjacency matrix as zero
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            adj_matrix[i][j] = 0;
    }

    add_vertex('A'); // 0
    add_vertex('X'); // 1
    add_vertex('W'); // 2
    add_vertex('G'); // 3
    add_vertex('U'); // 4
    
    add_edge(0, 2); // A - X
    add_edge(3, 2); // G - W
    add_edge(1, 4); // X - U
    add_edge(4, 3); // U - G
    add_edge(2,1); // X - A
    add_edge(4, 0); // U - A

    printf("Depth Firsr Search : \n");
    DFS();

    return 0;

}

/*
* Results : 
Depth Firsr Search :
A
W
X
U
G

*/
