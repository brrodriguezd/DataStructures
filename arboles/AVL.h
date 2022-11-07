#include "BST.h"

template <class T> class AVL : public BST<T> {
protected:
public:
  void AVLinsert(T dato) {
    BST<T>::Insert(dato, this->root);
    NodoArbol<T> *nodo = BST<T>::Find(dato);
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
    nodo->setHeight(Tree<T>::height(nodo));
  }
  void RebalanceRight(NodoArbol<T> *nodo) {
    auto subn = nodo->getLeft();
    if (subn->getRight()->getHeight() > subn->getLeft()->getHeight()) {
      BST<T>::RotateLeft(subn);
    }
    BST<T>::RotateRight(subn);
  }
  void RebalanceLeft(NodoArbol<T> *nodo) {
    auto subn = nodo->getRight();
    if (subn->getRight()->getHeight() > subn->getRight()->getHeight()) {
      BST<T>::RotateRight(subn);
    }
    BST<T>::RotateLeft(subn);
  }
  void AVLdelete(NodoArbol<T> *nodo) {
    if (!nodo->getRight()) {
      if (nodo->getLeft()) {
        nodo = nodo->getLeft();
        return;
      }
      nodo = NULL;
      return;
    }
    NodoArbol<T> *desc = Next(nodo);
    nodo->setDato(desc->getData());
    auto parent = desc->getParent();
    *desc = *(desc->getRight());
    Rebalance(parent);
  }
};