#include <stdio.h>
#include <stdlib.h>

typedef struct ll{
    int data;
    struct ll *nxt;
} Queue;

void enqueue(Queue **qp, int data){
    if(*qp == NULL){
        Queue *temp = (Queue *) malloc(sizeof(Queue));
        temp->data = data;
        temp->nxt = NULL;
        *qp = temp;
        return;
    }
    enqueue(&(*qp)->nxt, data);
}

int dequeue(Queue **qp){
    int data = (*qp)->data;
    *qp = (*qp)->nxt;
    return data;
}

int isEmpty(Queue *qp){
    return (qp == NULL);
}

void initialise(int v, int graph[v][v], int visited[v]){
    int i,j;
    for(i = 0; i<v; i+=1){
        visited[v] = 0;
        for(j = 0; j<v; j+=1){
            graph[i][j] = 0;
        }
    }
}

void printgraph(int v, int graph[v][v]){
    int i,j;
    for(i = 0; i<v; i+=1){
        for(j = 0; j<v; j+=1){
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

void creategraph(int v, int graph[v][v]){
    int connect,i,j;
    for(i = 0; i<v; i+=1){
        for(j = 0; j<v; j+=1){
            if(i == j) continue;
            printf("Connection from %d to %d (1 to connect, 0 to disconnect) -> ", i, j);
            scanf("%d", &connect);
            graph[i][j] = connect;
        }
    }
}

void bfs(int v, int graph[v][v], int visited[v], int start, Queue *qp){
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    visited[start] = 1;
    int i;
    enqueue(&qp, start);
    while(!isEmpty(qp)){
        int n = dequeue(&qp);
        printf("%d ", n);
        visited[n] = 1;
        for(i = 0; i<v; i+=1){
            if(graph[n][i] == 1 && !visited[i]) enqueue(&qp, i);
        }
    }
    printf("\n");
}

int main(){
    Queue *qp = NULL;
    int v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    int graph[v][v], visited[v];
    initialise(v, graph, visited);
    creategraph(v, graph);
    bfs(v, graph, visited, start, qp);
    printgraph(v, graph);
    return 0;
}
