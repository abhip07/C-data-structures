
/* 
Adjacency List : 

    -> An adjacency list represents a graph as an array of linked lists.

    ->The index of the array represents a vertex and each element in its 
linked list represents the other vertices that form an edge with the vertex.

*/
#include<stdio.h>
#include<stdlib.h>

// To represent adjacency list node
typedef struct node{
    int data;
    struct node* next;
} Node;

// To  represent adjacency list
struct adj_list{
    Node* head;  // this is the  pointer to the head of the node
};

// To represent graph
typedef struct graph{
    int vertices;
    struct adj_list* adjacent;  // A graph is array of adjacency lists.
} Graph;

// To create node (vertice) in the node
Node* create_node(int item){
    Node* new_node = (Node*) malloc(sizeof(Node));  
    
    new_node->data = item;
    new_node->next = NULL;

    return new_node;
}

// To create the grph of given nvumber of 'Vertices'
Graph* create_graph(int Vertices){
    Graph* graph = (Graph*) malloc(sizeof(Graph));

    graph->vertices = Vertices;

    // creating adjacency list having size = number of vertices
    graph->adjacent = (struct adj_list*) malloc(Vertices * 
            sizeof(struct adj_list));
   
    // Initializing each adjacency list as NULL by making head NULL
    for (int i = 0; i < Vertices; i++)
        graph->adjacent[i].head = NULL;
     // here, '.head' is used, because struct adj_list is not a pointer

    return graph;
}

// Adding edges to an undircted graph
void add_edge(Graph *graph, int source, int destination){
    
    Node *new_node = create_node(destination);

    new_node->next = graph->adjacent[source].head;
    graph->adjacent[source].head = new_node;

    // Since graph is undireced,create an edge from destination to source.
    new_node = create_node(source);
    new_node->next = graph->adjacent[destination].head;
    graph->adjacent[destination].head = new_node;
}


void disply(Graph *graph){
    int x = graph->vertices;
    for (int i = 0; i < x; ++i){
        Node *walk = graph->adjacent[i].head;
        
        printf("%d : ", i);
        
        while(walk){
            printf("%d -> ", walk->data);
            walk = walk->next;
        }
        
        printf("\n");
    }
}


// Driver code
int main(){
    int vertices = 5;
    Graph* graph = create_graph(vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 3);
    add_edge(graph, 1, 1);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 1);
    add_edge(graph, 4, 2);
    add_edge(graph, 4, 1);
    add_edge(graph, 3, 4);

    disply(graph);
}

/*
* Results : 

0 : 3 -> 1 ->
1 : 4 -> 3 -> 4 -> 1 -> 1 -> 0 ->
2 : 4 -> 3 ->
3 : 4 -> 1 -> 2 -> 0 ->
4 : 3 -> 1 -> 2 -> 1 ->

*/
