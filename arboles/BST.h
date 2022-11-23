#pragma once
#include "Tree.h"

template <class T> class BST : public Tree<T> {
protected:
  Nodo<T> *Find(T dato, Nodo<T> *root) {
    if (!root) {
      throw std::runtime_error("está vacia");
    }
    if (root->getDato() == dato) {
      return root;
    }
    if (root->getDato() > dato) {
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
  LinkedListTail<Nodo<T> *> RangeSearch(T x, T y, Nodo<T> *root) {
    if (!root) {
      throw std::runtime_error("está vacia");
    }
    LinkedListTail<Nodo<T> *> lista;
    auto *nodo = Find(x, root);
    while (nodo->getDato() <= y) {
      if (nodo->getDato() >= x) {
        std::cout << nodo->getDato();
        lista.PushBack(nodo);
      }
      if (nodo == Next(nodo)) {
        break;
      }
      nodo = Next(nodo);
    }
    return lista;
  }
  void Insert(T dato, Nodo<T> *root) {
    Nodo<T> *insertar = new Nodo<T>(dato);
    if (!root) {
      root = this->root = insertar;
      return;
    }
    Nodo<T> *nodo = Find(dato, root);
    insertar->setParent(nodo);
    if (nodo->getDato() < dato) {
      nodo->setRight(insertar);
    } else {
      nodo->setLeft(insertar);
    }
  }

  Nodo<T> *RightAncestor(Nodo<T> *nodo) {
    if (nodo->getParent()) {
      if (nodo->getDato() < nodo->getParent()->getDato()) {
        return nodo->getParent();
      }
      return RightAncestor(nodo->getParent());
    }
    throw std::runtime_error("no hay ancestro derecho");
  }
  Nodo<T> *LeftAncestor(Nodo<T> *nodo) {
    if (nodo->getParent()) {
      if (nodo->getDato() > nodo->getParent()->getDato()) {
        return nodo->getParent();
      }
      return LeftAncestor(nodo->getParent());
    }
    throw std::runtime_error("no hay ancestro izquierdo");
  }
  Nodo<T> *LeftDescendant(Nodo<T> *nodo) {
    if (nodo->getLeft()) {
      return LeftDescendant(nodo->getLeft());
    }
    return nodo;
  }
  Nodo<T> *RightDescendant(Nodo<T> *nodo) {
    if (nodo->getRight()) {
      return RightDescendant(nodo->getRight());
    }
    return nodo;
  }

  void RotateLeft(Nodo<T> *nodo) {
    auto parent = nodo->getParent();
    auto nodo2 = nodo->getRight();
    if (!nodo2) {
      throw std::runtime_error("no hay nodo a la izquierda");
    }
    Nodo<T> *peso = nodo2->getLeft() ? nodo2->getLeft() : nullptr;
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
  void RotateRight(Nodo<T> *nodo) {
    auto parent = nodo->getParent();
    auto nodo2 = nodo->getLeft();
    if (!nodo2) {
      throw std::runtime_error("no hay nodo a la derecha");
    }
    Nodo<T> *peso = nodo2->getRight() ? nodo2->getRight() : nullptr;
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

public:
  BST(Nodo<T> *nodo = nullptr) : Tree<T>{nodo} {}
  Nodo<T> *Find(T dato) { return Find(dato, this->root); }
  Nodo<T> *Next(Nodo<T> *nodo) {
    if (nodo->getRight()) {
      return LeftDescendant(nodo->getRight());
    } else {
      return RightAncestor(nodo);
    }
  }
  Nodo<T> *Prev(Nodo<T> *nodo) {
    if (nodo->getLeft()) {
      return RightDescendant(nodo->getLeft());
    } else {
      return LeftAncestor(nodo);
    }
  }
  // LinkedList -> Devuelve con el orden invertido
  LinkedListTail<Nodo<T> *> RangeSearch(T x, T y) {
    return RangeSearch(x, y, this->root);
  }

  void Insert(T dato) { return Insert(dato, this->root); }
  void Delete(Nodo<T> *nodo) {
    if (!nodo->getRight()) {
      if (nodo->getLeft()) {
        nodo->getLeft()->setParent(nodo->getParent());
        *nodo = *(nodo->getLeft());
        return;
      }
      nodo->getParent()->getRight() == nodo
          ? nodo->getParent()->setRight(nullptr)
          : nodo->getParent()->setLeft(nullptr);
      return;
    }
    Nodo<T> *desc = Next(nodo);
    nodo->setDato(desc->getDato());
    if (desc->getRight()) {
      *desc = *(desc->getRight());
    } else {
      desc->getParent()->getRight() == desc
          ? desc->getParent()->setRight(nullptr)
          : desc->getParent()->setLeft(nullptr);
    }
  }

  void RotateLeft() { return RotateLeft(this->root); }
  void RotateRight() { return RotateRight(this->root); }
};
