#include<stdio.h>
#include "ed/vertex.h"
#include "ed/digraph.h"
#include "ed/graph.h"

int main( int argc, const char* argv[]){
  int a, b, p, n, m, i;
  Graph G;

  scanf("%d %d", &n, &m);

  while(n > 0){
    G = GRAPHinit(n);    
    
    for(int i = 0; i < m; i++){
      scanf("%d %d %d", &a, &b, &p);
      GRAPHinsertE(G, a, b, 100 - p);
    }

    

    scanf("%d %d", &n, &m);    
  }
}
