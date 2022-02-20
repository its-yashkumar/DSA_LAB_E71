#include<stdio.h>
#include<math.h>
#define MAX 10

#define INFINITY 999
void Dijkstra(int Graph[7][7], int n, int start) {
  int cost[7][7], distance[7], pred[7];
  int visited[7], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];
        
    }
  }    

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++){
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }
    }
    visited[nextnode] = 1;
    for (i = 0; i < n; i++){
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    }    
    count++;
  }
printf("\n\nShortest distance from delhi to kolkata is: %d",distance[2]);
  
}


void floyyd(int dist[7][7],int rows){
    for (size_t k = 0; k < 7; k++)
    {
        for (size_t i = 0; i < 7; i++)
        {
            for (size_t j = 0; j < 7; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    
                }
                
            }
            
        }
        
    }
    printf("\n\nShortest distance from delhi to kolkata is: %d",dist[0][2]);
    
    
    
}

int main(){
    int dist[7][7] = {
                        {0,5,INFINITY,INFINITY,INFINITY,10,2},
                        {5,0,7,INFINITY,INFINITY,INFINITY,INFINITY},
                        {INFINITY,7,0,6,INFINITY,INFINITY,8},
                        {INFINITY,INFINITY,6,0,4,INFINITY,INFINITY},
                        {INFINITY,INFINITY,INFINITY,4,0,3,INFINITY},
                        {10,INFINITY,INFINITY,INFINITY,3,0,INFINITY},
                        {2,INFINITY,8,INFINITY,INFINITY,INFINITY,0}
    };
    floyyd(dist,7);
    Dijkstra(dist,7,0);
}