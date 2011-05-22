#include "vertex.h"
#include "digraph.h"

void GRAPHinsertE(Graph G, Vertex v, Vertex w){
  DIGRAPHinsertA(G, v, w);
  DIGRAPHinsertA(G, w, v);
}
