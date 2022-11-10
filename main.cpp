#include "arboles.h"
#include "listas.h"

int main() {
  AVL<int> arbol;
  arbol.AVLinsert(5);
  arbol.AVLinsert(2);
  arbol.AVLinsert(8);
  arbol.AVLinsert(1);
  arbol.AVLinsert(4);
  arbol.AVLinsert(6);
  arbol.AVLinsert(10);
  arbol.AVLinsert(7);
  arbol.levelTraversal();
  std::cout<<'\n';
  arbol.AVLdelete(arbol.Find(7));
  arbol.levelTraversal();
  std::cout<<'\n';
  arbol.AVLdelete(arbol.Find(10));
  arbol.levelTraversal();
  std::cout<<'\n';
  arbol.AVLdelete(arbol.Find(8));
  arbol.levelTraversal();
  std::cout<<'\n';
  arbol.AVLdelete(arbol.Find(6));
  arbol.levelTraversal();
  std::cout<<'\n';
  arbol.AVLdelete(arbol.Find(2));
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