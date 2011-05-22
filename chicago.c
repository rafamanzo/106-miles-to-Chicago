#include "ed/vertex.h"
#include "ed/digraph.h"
#include "ed/graph.h"
#include "chicago.h"

double prob_safe(Graph G){
  double prob;
  Vertex v;

  dijkstra(G, 0);

  v = G->V -1;
  prob = 1;

  while(v != 0){
    
  }
}
