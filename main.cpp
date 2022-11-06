#include "arboles.h"
#include "listas.h"

int main() {
  BST<int> arbol;
  arbol.Insert(5);
  arbol.Insert(2);
  arbol.Insert(8);
  arbol.Insert(1);
  arbol.Insert(4);
  arbol.Insert(6);
  arbol.levelTraversal();
  return 0;
}
/*
      5
  2       8
1    4  6

1 2 4 5 6 8
5 2 1 4 8 6
1 4 2 6 8 5

*/