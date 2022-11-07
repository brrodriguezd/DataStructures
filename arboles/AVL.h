#include "../listas.h"
#include "../nodos.h"
#include "BST.h"

template <class T> class AVL : public BST<T> {
protected:
public:
  void AVLinsert(T dato) {
    BST<T>::Insert(dato, this->root);
    NodoArbol<T> *nodo = Find(dato);
    Rebalance(nodo);
  }
  void Rebalance(NodoArbol<T> *nodo) {
    auto parent = nodo->getParent();
    if (nodo->getLeft()->getHeight() > nodo->getRight()->getHeight() + 1) {
      RebalanceRight(nodo);
    }
    if (nodo->getRight()->getHeight() > nodo->getLeft()->getHeight() + 1) {
      RebalanceLeft(nodo);
    }
    nodo->setHeight(Height(nodo));
  }
  void RebalanceRight(NodoArbol<T> *nodo) {
    auto subn = nodo->getLeft();
    if (subn->getRight()->getHeight() > subn->getLeft()->getHeight()) {
      RotateLeft(subn);
    }
    RotateRight(subn);
  }
  void RebalanceLeft(NodoArbol<T> *nodo) {
    auto subn = nodo->getRight();
    if (subn->getRight()->getHeight() > subn->getRight()->getHeight()) {
      RotateRight(subn);
    }
    RotateLeft(subn);
  }
  void AVLdelete(NodoArbol<T> *nodo) {
    Delete(nodo);
    //auto parent = ;
    //Rebalance(M);
  }
};