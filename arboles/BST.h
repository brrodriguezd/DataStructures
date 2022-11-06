#include "../listas.h"
#include "../nodos.h"
#include "Tree.h"

template <class T> class BST : public Tree<T> {
private:
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
      try {
        return RightAncestor(nodo);
      } catch (std::runtime_error &e) {
        std::cerr << "no hay siguiente";
      };
    }
  }
  LinkedList<T> RangeSearch(T x, T y, NodoArbol<T> *root = NULL) {
    if (!root) {
      root = this->root;
      if (!root) {
        throw std::runtime_error("está vacia");
      }
    }
    LinkedList<NodoArbol<T>> lista;
    NodoArbol<T> *nodo = Find(x, root);
    while (nodo.getData() < y) {
      if (nodo.getData() >= x) {
        lista.PushBack(nodo);
      }
      nodo = Next(nodo);
    }
    return lista;
  }
  void Insert(T dato, NodoArbol<T> *root = NULL) {
    NodoArbol<T> *insertar = new NodoArbol<T>(dato);
    if (!root) {
      if (!this->root) {
        this->root = insertar;
        return;
      }
      root = this->root;
    }
    NodoArbol<T> *nodo = Find(dato, root);
    insertar->setParent(nodo);
    if(nodo->getData() < dato){
        nodo->setRight(insertar);
    }else{
        nodo->setLeft(insertar);
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
};