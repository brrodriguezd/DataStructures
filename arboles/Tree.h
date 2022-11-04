#include "../nodos.h"
#include "../listas.h"

template <class T> class Tree {
private:
  Nodo<T> *root;

public:
  Tree(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    this->root = nodo;
  }
  Tree(Nodo<T> *nodo) { this->root = nodo; }
  void Insert(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->root) {
      this->root = nodo;
      return;
    }
  }
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
      inOrderTraversal(this->root->left);
    }
    std::cout << tree->getData() << " ";
    if (tree->getRight()) {
      inOrderTraversal(this->root->left);
    }
  }
  void preOrderTraversal(Nodo<T> *tree) {
    if (!tree) {
      throw std::runtime_error("está vacio");
    }
    std::cout << tree->getData() << " ";
    if (tree->getLeft()) {
      preOrderTraversal(this->root->left);
    }
    if (tree->getRight()) {
      preOrderTraversal(this->root->left);
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
    std::cout << tree->getData() << " ";
  }
  void levelTraversal(Nodo<T> *tree){
    if(!tree){
      return;
    }
    LinkedListTail<T> lista;
    lista.PushBack(tree->getData());
    
  }
};