#pragma once
#include "../listas.h"
#include "../nodos.h"

template <class T> class Tree {
protected:
  NodoArbol<T> *root;

public:
  Tree(T dato) {
    NodoArbol<T> *nodoarbol = new NodoArbol<T>(dato);
    this->root = nodoarbol;
  }
  Tree(NodoArbol<T> *nodoarbol = NULL) { this->root = nodoarbol; }

  int height(NodoArbol<T> *tree) {
    if (!tree) {
      return 0;
    }
    return 1 + std::max(height(tree->getLeft()), height(tree->getRight()));
  }
  int size(NodoArbol<T> *tree) {
    if (!tree) {
      return 0;
    }
    return 1 + size(tree->getLeft()) + size(tree->getRight());
  }
  void inOrderTraversal() { inOrderTraversal(this->root); }
  void inOrderTraversal(NodoArbol<T> *tree) {
    if (!tree) {
      throw std::runtime_error("está vacio");
    }
    if (tree->getLeft()) {
      inOrderTraversal(tree->getLeft());
    }
    std::cout << tree->getData() << " ";
    if (tree->getRight()) {
      inOrderTraversal(tree->getRight());
    }
  }
  void preOrderTraversal() { preOrderTraversal(this->root); }
  void preOrderTraversal(NodoArbol<T> *tree) {
    if (!tree) {
      throw std::runtime_error("está vacio");
    }
    std::cout << tree->getData() << " ";
    if (tree->getLeft()) {
      preOrderTraversal(tree->getLeft());
    }
    if (tree->getRight()) {
      preOrderTraversal(tree->getRight());
    }
  }
  void postOrderTraversal() { postOrderTraversal(this->root); }
  void postOrderTraversal(NodoArbol<T> *tree) {
    if (!tree) {
      throw std::runtime_error("está vacio");
    }
    if (tree->getLeft()) {
      postOrderTraversal(tree->getLeft());
    }
    if (tree->getRight()) {
      postOrderTraversal(tree->getRight());
    }
    std::cout << tree->getData() << " ";
  }
  void levelTraversal() { levelTraversal(this->root); }
  void levelTraversal(NodoArbol<T> *tree) {
    if (!tree) {
      return;
    }
    LinkedListTail<NodoArbol<T> *> lista;
    lista.PushBack(tree);
    while (!lista.Empty()) {
      auto dato = lista.TopFront();
      std::cout << dato->getData()<<" ";
      lista.PopFront();
      if (dato->getLeft()) {
        lista.PushBack(dato->getLeft());
      }
      if (dato->getRight()) {
        lista.PushBack(dato->getRight());
      }
    }
  }
};