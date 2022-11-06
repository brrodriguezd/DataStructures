#include "Nodo.h"

template <class T> class NodoNext : public Nodo<T> {
protected:
  NodoNext<T> *next;

public:
  NodoNext(T dato) : Nodo<T>{dato} { this->next = NULL; }
  void setNext(NodoNext<T> *nodo) { this->next = nodo; }
  NodoNext<T> *getNext() { return this->next; }
};