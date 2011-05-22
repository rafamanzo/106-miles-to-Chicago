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
