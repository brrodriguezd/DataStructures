#include "BST.h"
#include "Tree.h"
#include <iostream>

template <class T> class AVL : public BST<T> {
protected:
  void RebalanceRight(Nodo<T> *nodo) {
    auto subn = nodo->getLeft();
    if ((subn->getRight() ? subn->getRight()->getHeight() : 0) >
        (subn->getLeft() ? subn->getLeft()->getHeight() : 0)) {
      BST<T>::RotateLeft(subn);
      subn->setHeight(Tree<T>::height(subn));
    }
    BST<T>::RotateRight(nodo);
    nodo->setHeight(Tree<T>::height(nodo));
  }
  void RebalanceLeft(Nodo<T> *nodo) {
    auto subn = nodo->getRight();
    if ((subn->getLeft() ? subn->getLeft()->getHeight() : 0) >
        (subn->getRight() ? subn->getRight()->getHeight() : 0)) {
      BST<T>::RotateRight(subn);
      subn->setHeight(Tree<T>::height(subn));
    }
    BST<T>::RotateLeft(nodo);
    nodo->setHeight(Tree<T>::height(nodo));
  }

public:
  void Insert(T dato) {
    BST<T>::Insert(dato, this->root);
    Nodo<T> *nodo = BST<T>::Find(dato);
    Rebalance(nodo);
  }
  void Rebalance(Nodo<T> *nodo) {
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
  }
  void Delete(Nodo<T> *nodo) {
    if (!nodo->getRight()) {
      if (nodo->getLeft()) {
        nodo->getLeft()->setParent(nodo->getParent());
        *nodo = *(nodo->getLeft());
        Rebalance(nodo->getParent());
        return;
      }
      nodo->getParent()->getRight() == nodo
          ? nodo->getParent()->setRight(nullptr)
          : nodo->getParent()->setLeft(nullptr);
      Rebalance(nodo->getParent());
      return;
    }
    Nodo<T> *desc = BST<T>::Next(nodo);
    auto parent = desc->getParent();
    nodo->setDato(desc->getDato());
    if (desc->getRight()) {
      *desc = *(desc->getRight());
    } else {
      parent->getRight() == desc ? parent->setRight(nullptr)
                                 : parent->setLeft(nullptr);
    }
    if (parent) {
      Rebalance(parent);
    }
  }
};