/**********************************/
/* MAC0328 - Algoritmos em grafos */
/*                                */
/* rafamz                         */
/* macacada                       */
/* Rafael Reggiani Manzo          */
/* 6797150                        */
/**********************************/

#include<stdio.h>
#include<stdlib.h>

/*vertex.h*/
#define Vertex int

/*digraph.h*/
#define maxV 100
#define INFINITO 101

struct node{
  Vertex w;
  int cst;
  struct node *next;
};

typedef struct node *link;

struct digraph{
  int V;
  int A;
  link *adj;
};

typedef struct digraph *Digraph;

link NEW(Vertex w, link next, double cst);
Digraph DIGRAPHinit(int V);
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w, double cst);
void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
int DIGRAPHpath(Digraph G, Vertex s, Vertex t);
void dijkstra(Digraph G, Vertex s);
double getCost(Digraph G, Vertex v, Vertex w);

/*digrah_globals.h*/
int lbl[maxV];
Vertex parnt[maxV];
double cst[maxV];

/*item.h*/
typedef Vertex Item;

/*queue.h*/
void PQinit(int);
int PQempty();
void PQinsert(Item);
Item PQdelmin();
void PQdec(Item);
void PQfree();

/*graph.h*/
#define graph digraph
#define Graph Digraph
#define GRAPHinit DIGRAPHinit
#define GRAPHshow DIGRAPHshow

void GRAPHinsertE(Graph G, Vertex v, Vertex w, double cst);

/*chicago.h*/
double prob_safe(Graph G);

/*digraph.c*/
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
  for(actual = G->adj[v]; actual != NULL; actual = actual->next){
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
        cst[w]=cst[v]+p->cst;
        parnt[w] = v;
        PQdec(w);
      }
  }

  PQfree();
}

double getCost(Digraph G, Vertex v, Vertex w){
  link p;

  p = G->adj[v];

  while(p != NULL && p->w != w)
    p = p->next;

  if(p == NULL)
    return -1;
  else
    return p->cst;
}

/*queue.c*/
Item *q;
int inicio, fim;

void PQinit(int maxN) {
  q=(Item*)malloc(maxN*sizeof(Item));
  inicio = 0;
  fim = 0;
}

int PQempty() {
  return inicio==fim;
}

void PQinsert(Item item){
  q[fim++] = item;
}

Item PQdelmin() {
  int i, j;
  Item x;
 
  i= inicio;
  for (j=i+1; j < fim; j++)
   if (cst[q[i]] > cst[q[j]]) i = j;
 
  x = q[i];
  q[i] = q[--fim];
 
  return x;
}

void PQdec(Vertex v) {
  /* faz nada */
}
void PQfree() {
  free(q);
}

/*graph.c*/
void GRAPHinsertE(Graph G, Vertex v, Vertex w, double cst){
  DIGRAPHinsertA(G, v, w, cst);
  DIGRAPHinsertA(G, w, v, cst);
}

/*chicago.c*/
double prob_safe(Graph G){
  double prob;
  Vertex v;

  dijkstra(G, 0);

  v = G->V -1;
  prob = 1;

  while(v != 0){
    prob *= 1 - (getCost(G, parnt[v], v)/100);
    v = parnt[v];
  }

  return 100*(prob);  
}

/*main.c*/
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

    printf("\n%f percent\n", prob_safe(G));

    scanf("%d %d", &n, &m);    
  }

  return 0;
}
