/* 
 *Breadth First Traversal or Breadth First Search is a 
recursive algorithm for searching all the vertices of a 
graph or tree data structure.

* Here, we will use Queue data structure to print each element 
of tehe graph.

*/

#include<stdio.h>
#include<stdlib.h>

#define size 25  // size of queue

// defining structure of a queue
typedef struct queue{
    int front;
    int rear;
    int elements[size];
} Queue;

// struct of node in the graph 
typedef struct node{
    int vertex;
    struct node* next;
}Node;

// Structure for a graph
typedef struct graph{
    int vert_number;
    Node** adj_vert;
    int* visited;
} Graph;

// creating an empty queue
Queue* create_queue(void){
    Queue* queue = malloc(sizeof(Queue));

    queue->front = -1;
    queue->rear = -1;

    return queue;
}

// enqueing elements in the queue
void enqueue(Queue* queue, int item){
    if (queue->rear == size - 1){
        printf("The Queue is Full :(\n");
        return ;
    }
    else{
        // if queue is empty
        if (queue->front==-1)
            queue->front = queue->rear = 0;
        int rear = queue->rear++;
        queue->elements[rear] = item;
    }
}

int dequeue(Queue* queue){
    int item;
    if (queue->rear == -1){
        printf("The Queue is empty\n");
        item = -1;
    }

    else{
        item = queue->elements[queue->front];
        queue->front++;

        if (queue->front >= queue->rear){
            queue->front = queue->rear = -1;
        }
    }

    return item;
}

void print(Queue* queue){
    int front = queue->front;

    if (queue->rear == -1){
        printf("The Queue is Empty :(\n");
        return;
    }
    else{
        while (front < queue->rear){
            printf("%d ", queue->elements[front]);
            front++;

        }
    }
    printf("\n");
}


// creating a node
Node* create_node(int item){
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->vertex = item;
    new_node->next = NULL;

    return new_node;
}

// breadth first traversal
void bfs(Graph* graph, int vertex){
    // here, item will be our starting vertex for BFS
    Queue* queue = create_queue();
    
    graph->visited[vertex] = 1;
    enqueue(queue, vertex);
    
    // while queue is not empty
    while (queue->rear != -1){
        // print(queue);
        int current = dequeue(queue);
        printf("%d ", current);

        Node* temp = graph->adj_vert[current];

        while (temp){
            int adj_vert = temp->vertex;

            if (graph->visited[adj_vert] == 0){
                graph->visited[adj_vert] = 1;
                enqueue(queue, adj_vert);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}


// creating a graph
Graph* create_graph(int vertices){
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vert_number = vertices;
   
    // allocating memory to adjacent vertices to given vertices
    graph->adj_vert = malloc(vertices * sizeof(Node));
    graph->visited = malloc(vertices * sizeof(int));
    
    for(int i=0; i < vertices; i++){
        graph->adj_vert[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void add_edge(Graph* graph, int source, int dest){

    Node* new_node = create_node(dest);
  
    // from source to destination
    new_node->next = graph->adj_vert[source];
    graph->adj_vert[source] = new_node;

    // from destination to source (since is graph is undirected)
    new_node = create_node(source);
    new_node->next = graph->adj_vert[dest];
    graph->adj_vert[dest] = new_node;
}

 // Driver Code
int main(){
    Graph* graph = create_graph(6);

    add_edge(graph, 0, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 4, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 4, 0);
    add_edge(graph, 3, 2);

    bfs(graph, 0);

    return 0;
}

/*
* Results : 
0 4 2 3 1

*/
