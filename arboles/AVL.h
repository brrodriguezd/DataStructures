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
    if ((nodo->getLeft()? nodo->getLeft()->getHeight() : 0) > (nodo->getRight() ? nodo->getRight()->getHeight() + 1 : 1)) {
      RebalanceRight(nodo);
    }
    if ((nodo->getRight()? nodo->getRight()->getHeight() : 0) > (nodo->getLeft() ? nodo->getLeft()->getHeight() + 1 : 1)) {
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
        nodo->getLeft()->setParent(nodo->getParent());
        *nodo = *(nodo->getLeft());
        return;
      }
      nodo->getParent()->getRight() == nodo ? nodo->getParent()->setRight(NULL)
                                            : nodo->getParent()->setLeft(NULL);
      return;
    }
    NodoArbol<T> *desc = BST<T>::Next(nodo);
    auto parent = desc->getParent();
    nodo->setDato(desc->getData());
    if (desc->getRight()) {
      *desc = *(desc->getRight());
    } else {
      parent->getRight() == desc ? parent->setRight(NULL)
                                 : parent->setLeft(NULL);
    }
    if (parent) {
      Rebalance(parent);
    }
  }
};