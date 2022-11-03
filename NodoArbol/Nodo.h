#pragma once
#include <iostream>

template <class T> class Nodo {
private:
  Nodo<T> *left;
  Nodo<T> *right;
  T data;

public:
  Nodo(T dato) {
    this->data = dato;
    this->left = NULL;
    this->right = NULL;
  }
  void setLeft(Nodo<T> *nodo) { this->left = nodo; }
  Nodo<T> *getLeft() { return this->left; }
  void setRight(Nodo<T> *nodo) { this->right = nodo; }
  Nodo<T> *getRight() { return this->right; }
  void setDato(T dato) { this->data = dato; }
  T getData() { return this->data; }
};