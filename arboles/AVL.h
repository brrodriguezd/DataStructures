#include "BST.h"
#include "Tree.h"
#include <iostream>

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
    if (nodo->getLeft()) {
      if ((nodo->getLeft()->getHeight()) >
          (nodo->getRight() ? (nodo->getRight()->getHeight() + 1) : 1)) {
        RebalanceRight(nodo);
      }
    }
    if (nodo->getRight()) {
      if ((nodo->getRight()->getHeight()) >
          (nodo->getLeft() ? (nodo->getLeft()->getHeight() + 1) : 1)) {
        RebalanceLeft(nodo);
      }
    }
    nodo->setHeight(Tree<T>::height(nodo));
    if (parent) {
      Rebalance(parent);
    }
    std::cout << nodo->getData() << ": " << nodo->getHeight() << ". ";
  }
  void RebalanceRight(NodoArbol<T> *nodo) {
    auto subn = nodo->getLeft();
    if ((subn->getRight() ? subn->getRight()->getHeight() : 0) >
        (subn->getLeft() ? subn->getLeft()->getHeight() : 0)) {
      BST<T>::RotateLeft(subn);
      subn->setHeight(Tree<T>::height(subn));
    }
    BST<T>::RotateRight(nodo);
    nodo->setHeight(Tree<T>::height(nodo));
  }
  void RebalanceLeft(NodoArbol<T> *nodo) {
    auto subn = nodo->getRight();
    if ((subn->getLeft() ? subn->getLeft()->getHeight() : 0) >
        (subn->getRight() ? subn->getRight()->getHeight() : 0)) {
      BST<T>::RotateRight(subn);
      subn->setHeight(Tree<T>::height(subn));
    }
    BST<T>::RotateLeft(nodo);
    nodo->setHeight(Tree<T>::height(nodo));
  }
  void AVLdelete(NodoArbol<T> *nodo) {
    if (!nodo->getRight()) {
      if (nodo->getLeft()) {
        nodo->getLeft()->setParent(nodo->getParent());
        *nodo = *(nodo->getLeft());
        Rebalance(nodo->getParent());
        return;
      }
      nodo->getParent()->getRight() == nodo ? nodo->getParent()->setRight(NULL)
                                            : nodo->getParent()->setLeft(NULL);
      Rebalance(nodo->getParent());
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