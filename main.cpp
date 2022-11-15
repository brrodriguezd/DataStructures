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
  arbol.Insert(10);
  arbol.Insert(7);
  arbol.levelTraversal();
  auto nodo = arbol.Find(3);
  auto lista = arbol.RangeSearch(3, 8);
  lista.Display();
  std::cout << '\n';
  arbol.Delete(arbol.Find(1));
  std::cout << '\n';
  arbol.levelTraversal();
  std::cout << '\n';
  arbol.Delete(arbol.Find(2));
  std::cout << '\n';
  arbol.levelTraversal();
  std::cout << '\n';
  arbol.Delete(arbol.Find(4));
  std::cout << '\n';
  arbol.levelTraversal();
  std::cout << '\n';
  arbol.Delete(arbol.Find(6));
  std::cout << '\n';
  arbol.levelTraversal();
  std::cout << '\n';
  arbol.Delete(arbol.Find(2));
  std::cout << '\n';
  arbol.levelTraversal();
  std::cout << '\n';
  return 0;
}