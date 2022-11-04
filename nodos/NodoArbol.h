#pragma once
#include "Nodo.h"

template <class T> class NodoArbol : public Nodo<T> {
private:
  NodoArbol<T> *left;
  NodoArbol<T> *right;

public:
  NodoArbol(T dato) : Nodo<T>{dato} {
    this->left = NULL;
    this->right = NULL;
  }
  void setLeft(NodoArbol<T> *nodo) { this->left = nodo; }
  NodoArbol<T> *getLeft() { return this->left; }
  void setRight(NodoArbol<T> *nodo) { this->right = nodo; }
  NodoArbol<T> *getRight() { return this->right; }
};