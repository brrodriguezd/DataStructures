#pragma once
#include <iostream>

template <class T> class Nodo {
private:
  Nodo<T> *next;
  Nodo<T> *prev;
  T data;

public:
  Nodo(T dato) {
    this->data = dato;
    this->next = NULL;
    this->prev = NULL;
  }
  void setNext(Nodo<T> *nodo) { this->next = nodo; }
  Nodo<T> *getNext() { return this->next; }
  void setPrev(Nodo<T> *nodo) { this->prev = nodo; }
  Nodo<T> *getPrev() { return this->prev; }
  void setDato(T dato) { this->data = dato; }
  T getData() { return this->data; }
};