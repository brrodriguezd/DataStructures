#pragma once
#include "Tree.h"

template <class T> class BST : public Tree<T> {
protected:
public:
  BST(NodoArbol<T> *nodo = NULL) : Tree<T>{nodo} {}
  NodoArbol<T> *Find(T dato) { return Find(dato, this->root); }
  NodoArbol<T> *Find(T dato, NodoArbol<T> *root) {
    if (!root) {
      throw std::runtime_error("está vacia");
    }
    if (root->getData() == dato) {
      return root;
    }
    if (root->getData() > dato) {
      if (root->getLeft()) {
        return Find(dato, root->getLeft());
      } else {
        return root;
      }
    } else {
      if (root->getRight()) {
        return Find(dato, root->getRight());
      } else {
        return root;
      }
    }
  }

  NodoArbol<T> *Next(NodoArbol<T> *nodo) {
    if (nodo->getRight()) {
      return LeftDescendant(nodo->getRight());
    } else {
      return RightAncestor(nodo);
    }
  }
  // LinkedList -> Devuelve con el orden invertido
  LinkedListTail<NodoArbol<T> *> RangeSearch(T x, T y) {
    return RangeSearch(x, y, this->root);
  }
  LinkedListTail<NodoArbol<T> *> RangeSearch(T x, T y, NodoArbol<T> *root) {
    if (!root) {
      throw std::runtime_error("está vacia");
    }
    LinkedListTail<NodoArbol<T> *> lista;
    NodoArbol<T> *nodo = Find(x, root);
    while (nodo.getData() < y) {
      if (nodo.getData() >= x) {
        lista.PushBack(nodo);
      }
      nodo = Next(nodo);
    }
    return lista;
  }

  void Insert(T dato) { return Insert(dato, this->root); }
  void Insert(T dato, NodoArbol<T> *root) {
    NodoArbol<T> *insertar = new NodoArbol<T>(dato);
    if (!root) {
      root = this->root = insertar;
      return;
    }
    NodoArbol<T> *nodo = Find(dato, root);
    insertar->setParent(nodo);
    if (nodo->getData() < dato) {
      nodo->setRight(insertar);
    } else {
      nodo->setLeft(insertar);
    }
  }

  void Delete(NodoArbol<T> *nodo) {
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
    NodoArbol<T> *desc = Next(nodo);
    nodo->setDato(desc->getData());
    if (desc->getRight()) {
      *desc = *(desc->getRight());
    } else {
      desc->getParent()->getRight() == desc ? desc->getParent()->setRight(NULL)
                                            : desc->getParent()->setLeft(NULL);
    }
  }

  NodoArbol<T> *RightAncestor(NodoArbol<T> *nodo) {
    if (nodo->getData() < nodo->getParent()->getData()) {
      return nodo;
    }
    if (nodo->getParent()) {
      return RightAncestor(nodo->getParent());
    }
    throw std::runtime_error("no hay ancestro derecho");
  }
  NodoArbol<T> *LeftAncestor(NodoArbol<T> *nodo) {
    if (nodo->getData() > nodo->getParent()->getData()) {
      return nodo;
    }
    if (nodo->getParent()) {
      return LeftAncestor(nodo->getParent());
    }
    throw std::runtime_error("no hay ancestro izquierdo");
  }
  NodoArbol<T> *LeftDescendant(NodoArbol<T> *nodo) {
    if (nodo->getLeft()) {
      return LeftDescendant(nodo->getLeft());
    }
    return nodo;
  }
  NodoArbol<T> *RightDescendant(NodoArbol<T> *nodo) {
    if (nodo->getRight()) {
      return LeftDescendant(nodo->getRight());
    }
    return nodo;
  }
  void RotateLeft() { return RotateLeft(this->root); }
  void RotateLeft(NodoArbol<T> *nodo) {
    auto parent = nodo->getParent();
    auto nodo2 = nodo->getRight();
    if (!nodo2) {
      throw std::runtime_error("no hay nodo a la izquierda");
    }
    NodoArbol<T> *peso = nodo2->getLeft() ? nodo2->getLeft() : NULL;
    nodo2->setParent(parent);
    if (!nodo->getParent()) {
      this->root = nodo2;
    } else {
      if (parent->getLeft() == nodo) {
        parent->setLeft(nodo2);
      } else {
        parent->setRight(nodo2);
      }
    }
    nodo->setParent(nodo2);
    nodo2->setLeft(nodo);
    if (peso) {
      peso->setParent(nodo);
    }
    nodo->setRight(peso);
  }
  void RotateRight() { return RotateLeft(this->root); }
  void RotateRight(NodoArbol<T> *nodo) {
    auto parent = nodo->getParent();
    auto nodo2 = nodo->getLeft();
    if (!nodo2) {
      throw std::runtime_error("no hay nodo a la derecha");
    }
    NodoArbol<T> *peso = nodo2->getRight() ? nodo2->getRight() : NULL;
    nodo2->setParent(parent);
    if (!nodo->getParent()) {
      this->root = nodo2;
    } else {
      if (parent->getLeft() == nodo) {
        parent->setLeft(nodo2);
      } else {
        parent->setRight(nodo2);
      }
    }
    nodo->setParent(nodo2);
    nodo2->setRight(nodo);
    if (peso) {
      peso->setParent(nodo);
    }
    nodo->setLeft(peso);
  }
};