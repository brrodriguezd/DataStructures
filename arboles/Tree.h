#pragma once
#include "../Nodo.h"
#include "../listas.h"

template <class T> class Tree {
protected:
  Nodo<T> *root;

  int height(Nodo<T> *tree) {
    if (!tree) {
      return 0;
    }
    return 1 + std::max(height(tree->getLeft()), height(tree->getRight()));
  }
  int size(Nodo<T> *tree) {
    if (!tree) {
      return 0;
    }
    return 1 + size(tree->getLeft()) + size(tree->getRight());
  }

  void inOrderTraversal(Nodo<T> *tree) {
    if (!tree) {
      throw std::runtime_error("está vacio");
    }
    if (tree->getLeft()) {
      inOrderTraversal(tree->getLeft());
    }
    std::cout << tree->getDato() << " ";
    if (tree->getRight()) {
      inOrderTraversal(tree->getRight());
    }
  }
  void preOrderTraversal(Nodo<T> *tree) {
    if (!tree) {
      throw std::runtime_error("está vacio");
    }
    std::cout << tree->getDato() << " ";
    if (tree->getLeft()) {
      preOrderTraversal(tree->getLeft());
    }
    if (tree->getRight()) {
      preOrderTraversal(tree->getRight());
    }
  }
  void postOrderTraversal(Nodo<T> *tree) {
    if (!tree) {
      throw std::runtime_error("está vacio");
    }
    if (tree->getLeft()) {
      postOrderTraversal(tree->getLeft());
    }
    if (tree->getRight()) {
      postOrderTraversal(tree->getRight());
    }
    std::cout << tree->getDato() << " ";
  }
  void levelTraversal(Nodo<T> *tree) {
    if (!tree) {
      return;
    }
    LinkedListTail<Nodo<T> *> lista;
    lista.PushBack(tree);
    while (!lista.Empty()) {
      auto dato = lista.TopFront();
      std::cout << dato->getDato() << " ";
      lista.PopFront();
      if (dato->getLeft()) {
        lista.PushBack(dato->getLeft());
      }
      if (dato->getRight()) {
        lista.PushBack(dato->getRight());
      }
    }
  }

public:
  Tree(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    this->root = nodo;
  }
  Tree(Nodo<T> *nodo = nullptr) { this->root = nodo; }

  int height() { return height(this->root); }
  int size() { return size(this->root); }
  
  void inOrderTraversal() { inOrderTraversal(this->root); }
  void preOrderTraversal() { preOrderTraversal(this->root); }
  void postOrderTraversal() { postOrderTraversal(this->root); }
  void levelTraversal() { levelTraversal(this->root); }
};