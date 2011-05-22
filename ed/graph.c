#include "vertex.h"
#include "digraph.h"

void GRAPHinsertE(Graph G, Vertex v, Vertex w, double cst){
  DIGRAPHinsertA(G, v, w, cst);
  DIGRAPHinsertA(G, w, v, cst);
}
