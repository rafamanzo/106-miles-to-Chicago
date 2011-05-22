#include<stdlib.h>
#include<stdio.h>
#include "vertex.h"
#include "digraph.h"
#include "queue/item.h"
#include "queue/queue.h"

link NEW(Vertex w, link next, double cst){
  link n;

  n = malloc(sizeof(struct node));

  n->w = w;
  n->next = next;
  n->cst = cst;

  return n;
}

Digraph DIGRAPHinit(int V){
  Vertex v;
  Digraph G;

  G = malloc(sizeof(struct digraph));

  G->V = V;
  G->A = 0;

  G->adj = malloc(V*sizeof(link));
  
  for(v = 0; v < G->V; v++)
    G->adj[v] = NULL;

  return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w, double cst){
  link n;

  if(v == w) return;

  for(n = G->adj[v]; n != NULL; n = n->next)
    if(n->w == w) return;
  G->adj[v] = NEW(w, G->adj[v], cst);
  G->A++;
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w){
  link before, actual;

  if(v==w) return;

  before = NULL;
  for(actual = G->adj[v]; actual != NULL; acual = actual->next){
    if(actual->w == w){
      before->next = actual->next;
      free(actual);
      return;
    }else{
      before = actual;
    }
  }

} 

void DIGRAPHshow(Digraph G){
  Vertex v;
  link n;

  for(v = 0; v < G->V; v++){
    printf(" %2d:", v);
    for(n = G->adj[v]; n != NULL; n = n->next)
      printf(" %2d" , n->w);
    printf("\n");
  }
}

void pathR(Digraph G, Vertex v){
  link n;

  lbl[v] = 0;
  for(n = G->adj[v]; n != NULL; n = n->next)
    if(lbl[n->w] == -1){
      parnt[n->w] = v;
      pathR(G, n->w);
    }
}

int DIGRAPHpath(Digraph G, Vertex s, Vertex t){
  Vertex v;

  for(v = 0; v < G->V; v++){
    lbl[v] = -1;
    parnt[v] = -1;
  }

  parnt[s] = s;
  pathR(G, s);

  if(lbl[t] == -1) return 0;
  else return 1;
}

void dijkstra(Digraph G, Vertex s){
  Vertex v, w; link p;
  for (v = 0; v < G->V; v++) {
    cst[v] = INFINITO;
    parnt[v] = -1;
  }
  PQinit(G->V);
  cst[s] = 0;
  parnt[s] = s;
  PQinsert(s);
  while (!PQempty()) {
    v = PQdelmin();
    for(p=G->adj[v];p!=NULL;p=p->next)
      if(cst[w=p->w]==INFINITO){
        cst[w]=cst[v]+p->cst;
        parnt[w]=v;
        PQinsert(w);
      }else if(cst[w]>cst[v]+p->cst){
        cst[w]=cst[v]+p->cst
        parnt[w] = v;
        PQdec(w);
      }

      PQfree();
  }
}

double getCost(Digraph G, Vertex v, Vertex w){
  link p;

  while(p->
}
