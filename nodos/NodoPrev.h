#pragma once
#include "Nodo.h"

template <class T> class NodoPrev : public Nodo<T> {
private:
  NodoPrev<T> *prev;
  NodoPrev<T> *next;

public:
  NodoPrev(T dato) : Nodo<T>{dato} {
    this->prev = NULL;
    this->next = NULL;
  }
  void setPrev(NodoPrev<T> *nodo) { this->prev = nodo; }
  NodoPrev<T> *getPrev() { return this->prev; }
  void setNext(NodoPrev<T> *nodo) { this->next = nodo; }
  NodoPrev<T> *getNext() { return this->next; }
};