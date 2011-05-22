#include<stdio.h>
#include "ed/vertex.h"
#include "ed/digraph.h"
#include "ed/graph.h"
#include "chicago.h"

int main( int argc, const char* argv[]){
  int a, b, p, n, m, i;
  Graph G;

  scanf("%d %d", &n, &m);

  while(n > 0){
    G = GRAPHinit(n);    
    
    for(i = 0; i < m; i++){
      scanf("%d %d %d", &a, &b, &p);
      GRAPHinsertE(G, a - 1, b - 1, 100 - p);
    }

    printf("%f percent\n", prob_safe(G));

    scanf("%d %d", &n, &m);    
  }

  return 0;
}
