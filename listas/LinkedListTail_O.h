#include "../nodos.h"

template <class T> class LinkedListTail_O {
private:
  NodoNext<T> *head;
  NodoNext<T> *tail;

public:
  LinkedListTail_O() {
    this->head = NULL;
    this->tail = NULL;
  }
  void Insert(T dato) {
    NodoNext<T> *nodo = new NodoNext<T>(dato);
    if (!this->tail) {
      this->tail = this->head = nodo;
      return;
    }
    if (!(this->head->getData() < dato)) {
      nodo->setNext(this->head);
      this->head = nodo;
      return;
    }
    NodoNext<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (!(recorrer->getNext()->getData() < dato)) {
        break;
      }
      recorrer = recorrer->getNext();
    }
    nodo->setNext(recorrer->getNext());
    recorrer->setNext(nodo);
    if (!nodo->getNext()) {
      this->tail = nodo;
    }
  }
  T TopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    return this->head->getData();
  }
  void PopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    this->head = this->head->getNext();
    if (!this->head) {
      this->tail = NULL;
    }
  }
  T TopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacio");
    }
    return this->tail->getData();
  }
  void PopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (this->tail == this->head) {
      this->tail = this->head = NULL;
      return;
    }
    NodoNext<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(NULL);
    this->tail = recorrer;
  }
  NodoNext<T> *Find(T dato) {
    NodoNext<T> *recorrer = this->head;
    while (recorrer) {
      if (recorrer->getData() == dato) {
        return recorrer;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("no está en la lista");
  }
  void Erase(T dato) {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    NodoNext<T> *recorrer = this->head;
    if (this->head->getData() == dato) {
      this->PopFront();
      return;
    }
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getData() == dato) {
        if (recorrer->getNext() == this->tail) {
          recorrer->setNext(NULL);
          this->tail = recorrer;
          return;
        }
        recorrer->setNext(recorrer->getNext()->getNext());
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("no se encontro el dato");
  }
  bool Empty() {
    if (!this->head) {
      return true;
    }
    return false;
  }

  void Display() {
    if (this->head) {
      NodoNext<T> *recorrer = this->head;
      while (recorrer) {
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getNext();
      }
    }
    std::cout << '\n';
  }

  void DisplayBackwards() {}
};