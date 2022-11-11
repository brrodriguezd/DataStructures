#pragma once
#include <iostream>

template <class T> class Nodo {
private:
  Nodo<T> *left;
  Nodo<T> *right;
  Nodo<T> *parent;
  Nodo<T> *prev;
  Nodo<T> *next;
  int height;
  T dato;

public:
  Nodo(T dato) {
    this->dato = dato;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->prev = nullptr;
    this->next = nullptr;
    this->height = 0;
  }
  void setDato(T dato) { this->dato = dato; }
  T getDato() { return this->dato; }
  void setNext(Nodo<T> *nodo) { this->next = nodo; }
  Nodo<T> *getNext() { return this->next; }
  void setPrev(Nodo<T> *nodo) { this->prev = nodo; }
  Nodo<T> *getPrev() { return this->prev; }
  void setLeft(Nodo<T> *nodo) { this->left = nodo; }
  Nodo<T> *getLeft() { return this->left; }
  void setRight(Nodo<T> *nodo) { this->right = nodo; }
  Nodo<T> *getRight() { return this->right; }
  void setParent(Nodo<T> *nodo) { this->parent = nodo; }
  Nodo<T> *getParent() { return this->parent; }
  void setHeight(int height) { this->height = height; }
  int getHeight() { return this->height; }
};