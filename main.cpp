#include "arboles.h"
#include "listas.h"
#include <iostream>

int main() {
  BST<int> arbol;
  arbol.Insert(5);
  arbol.Insert(2);
  arbol.Insert(8);
  arbol.Insert(1);
  arbol.Insert(4);
  arbol.Insert(6);
  arbol.Insert(10);
  arbol.Insert(7);
  arbol.RotateRight(arbol.Find(5));
  arbol.RotateLeft(arbol.Find(2));
  arbol.inOrderTraversal();
  std::cout<<'\n';
  arbol.preOrderTraversal();
  std::cout<<'\n';
  arbol.postOrderTraversal();
  std::cout<<'\n';
  arbol.levelTraversal();
  return 0;
}
/*
      5
  2       8
1   4   6   10
          7

    2
1       5
      4   8
        6   10
         7
1 2 4 5 6 7 8 10 
5 2 1 4 8 6 7 10 
1 4 2 7 6 10 8 5 
5 2 8 1 4 6 10 7
*/