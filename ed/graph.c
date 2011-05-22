#include "vertex.h"
#include "digraph.h"
#include "graph.h"

void GRAPHinsertE(Graph G, Vertex v, Vertex w, double cst){
  DIGRAPHinsertA(G, v, w, cst);
  DIGRAPHinsertA(G, w, v, cst);
}
