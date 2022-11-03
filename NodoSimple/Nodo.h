#pragma once
#include <iostream>

template <class T> class Nodo {
private:
  Nodo<T> *next;
  T data;

public:
  Nodo(T dato) {
    this->data = dato;
    this->next = NULL;
  }
  void setNext(Nodo<T> *nodo) { this->next = nodo; }
  Nodo<T> *getNext() { return this->next; }
  void setDato(T dato) { this->data = dato; }
  T getData() { return this->data; }
};