#include "../nodos.h"

template <class T = int> class BST {
private:
  Nodo<T> *root;

public:
  BST(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    this->root = nodo;
  }
  BST(Nodo<T> *nodo) { this->root = nodo; }
  void Insert(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->root) {
      this->root = nodo;
      return;
    }
  }
  int Height(Nodo<T> *tree) {
    if (!tree) {
      return 0;
    }
    return 1 + std::max(Height(tree->getLeft()), Height(tree->getRight()));
  }
  int Size(Nodo<T> *tree) {
    if (!tree) {
      return 0;
    }
    return 1 + Size(tree->getLeft()) + Size(tree->getRight());
  }
};