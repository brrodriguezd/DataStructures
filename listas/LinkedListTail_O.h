#include "../Nodo.h"

template <class T> class LinkedListTail_O {
private:
  Nodo<T> *head;
  Nodo<T> *tail;

public:
  LinkedListTail_O() {
    this->head = nullptr;
    this->tail = nullptr;
  }
  void Insert(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->tail) {
      this->tail = this->head = nodo;
      return;
    }
    if (!(this->head->getDato() < dato)) {
      nodo->setNext(this->head);
      this->head = nodo;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (!(recorrer->getNext()->getDato() < dato)) {
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
    return this->head->getDato();
  }
  void PopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    this->head = this->head->getNext();
    if (!this->head) {
      this->tail = nullptr;
    }
  }
  T TopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacio");
    }
    return this->tail->getDato();
  }
  void PopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (this->tail == this->head) {
      this->tail = this->head = nullptr;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(nullptr);
    this->tail = recorrer;
  }
  Nodo<T> *Find(T dato) {
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      if (recorrer->getDato() == dato) {
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
    Nodo<T> *recorrer = this->head;
    if (this->head->getDato() == dato) {
      this->PopFront();
      return;
    }
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getDato() == dato) {
        if (recorrer->getNext() == this->tail) {
          recorrer->setNext(nullptr);
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
  bool Empty() { return !this->head; }

  void Display() {
    if (this->head) {
      Nodo<T> *recorrer = this->head;
      while (recorrer) {
        std::cout << recorrer->getDato() << " ";
        recorrer = recorrer->getNext();
      }
    }
    std::cout << '\n';
  }

  void DisplayBackwards() {}
};