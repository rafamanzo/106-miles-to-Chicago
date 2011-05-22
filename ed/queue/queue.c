#include<stdlib.h>
#include "../vertex.h"
#include "../digraph.h"
#include "../digraph_globals.h"
#include "item.h"
#include "queue.h"

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
