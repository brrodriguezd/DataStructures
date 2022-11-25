#include "../Nodo.h"

template <class T> class DoublyLinkedList {
private:
  Nodo<T> *head;

public:
  DoublyLinkedList() { this->head = nullptr; }
  void PushFront(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->head) {
      this->head = nodo;
      return;
    }
    this->head->setPrev(nodo);
    nodo->setNext(this->head);
    this->head = nodo;
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
    if (this->head) {
      this->head->setPrev(nullptr);
    }
  }
  void PushBack(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->head) {
      this->head = nodo;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(nodo);
    nodo->setPrev(recorrer);
  }
  T TopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      recorrer = recorrer->getNext();
    }
    return recorrer->getDato();
  }
  void PopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (!this->head->getNext()) {
      this->head = nullptr;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(nullptr);
  }
  Nodo<T> *Find(T dato) {
    Nodo<T> *recorrer = this->head;
    while (recorrer->getDato()) {
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
    if (this->head->getDato() == dato) {
      this->PopFront();
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getDato() == dato) {
        if (recorrer->getNext()->getNext()) {
          recorrer->getNext()->getNext()->setPrev(recorrer);
          recorrer->setNext(recorrer->getNext()->getNext());
          return;
        }
        recorrer->setNext(nullptr);
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No se encontro el dato");
  }
  bool Empty() { return !this->head; }
  
  void AddBefore(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    if (nodo->getPrev()) {
      nodo->getPrev()->setNext(data);
    } else {
      this->head = data;
    }
    data->setPrev(nodo->getPrev());
    nodo->setPrev(data);
    data->setNext(nodo);
  }
  void AddAfter(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    if (nodo->getNext()) {
      nodo->getNext()->setPrev(data);
    }
    data->setNext(nodo->getNext());
    nodo->setNext(data);
    data->setPrev(nodo);
  }
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
  void DisplayBackwards() {
    if (this->head) {
      Nodo<T> *recorrer = this->head;
      while (recorrer->getNext()) {
        recorrer = recorrer->getNext();
      }
      while (recorrer) {
        std::cout << recorrer->getDato() << " ";
        recorrer = recorrer->getPrev();
      }
    }
    std::cout << '\n';
  }
};