#include "Nodo.h"

template <class T> class NodoArbol : public Nodo<T> {
private:
  NodoArbol<T> *left;
  NodoArbol<T> *right;
  NodoArbol<T> *parent;
  NodoArbol<T> *height;

public:
  NodoArbol(T dato) : Nodo<T>{dato} {
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
  }
  void setLeft(NodoArbol<T> *nodo) { this->left = nodo; }
  NodoArbol<T> *getLeft() { return this->left; }
  void setRight(NodoArbol<T> *nodo) { this->right = nodo; }
  NodoArbol<T> *getRight() { return this->right; }
  void setParent(NodoArbol<T> *nodo) { this->parent = nodo; }
  NodoArbol<T> *getParent() { return this->parent; }
  void setHeight(NodoArbol<T> *nodo) { this->height = nodo; }
  NodoArbol<T> *getHeight() { return this->height; }
};