/*
 In Adjaceny Matrix:
    -> The size of the matrix is VxV where V is the number of vertices in the graph
    
    ->The value of an entry Aij is either 1 or 0 
depending on whether there is an edge from vertex i to j.

*/

#include<stdio.h>

#define V 4  // V=Vertices

// Initializing all graph nodes as zero
void init(int arr[][V]){
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            arr[i][j] = 0;
}

// creating a graph node
void insert(int arr[][V], int row, int col){
    arr[row][col] = 1;
    arr[col][row] = 1;
}

// Displaying the graph in the form of matrix
void Display(int arr[][V]){
    
    for (int i =0; i < V; i++){
        printf("%d:  ", i);

        for (int j = 0; j < V; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

// Driver Code
int main(){
    //Declaring the adjacency matrix
    int adj[V][V];

    // Initializing all values as zero
    init(adj);

    insert(adj, 0, 1);
    insert(adj, 3, 2);
    insert(adj, 1, 4);
    insert(adj, 1, 2);
    insert(adj, 4, 1);
    insert(adj, 4, 4);

    Display(adj);


}

/*

 Results : 

0:  0 1 0 0
1:  1 0 1 0
2:  1 1 0 1
3:  0 0 1 0

*/
