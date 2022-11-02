#include "../Nodo.h"

template <class T> class DoublyLinkedList {
private:
  Nodo<T> *head;

public:
  DoublyLinkedList() { this->head = NULL; }
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
    return this->head->getData();
  }
  void PopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    this->head = this->head->getNext();
    if (this->head) {
      this->head->setPrev(NULL);
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
    return recorrer->getData();
  }
  void PopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (!this->head->getNext()) {
      this->head = NULL;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(NULL);
  }
  Nodo<T> *Find(T dato) {
    Nodo<T> *recorrer = this->head;
    while (recorrer->getData()) {
      if (recorrer->getData() == dato) {
        return recorrer;
      }
      recorrer = recorrer->getNext();
    }
    return NULL;
  }
  void Erase(T dato) {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (this->head->getData() == dato) {
      this->PopFront();
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getData() == dato) {
        if (recorrer->getNext()->getNext()) {
          recorrer->getNext()->getNext()->setPrev(recorrer);
          recorrer->setNext(recorrer->getNext()->getNext());
          return;
        }
        recorrer->setNext(NULL);
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No se encontro el dato");
  }
  bool Empty() {
    if (!this->head) {
      return true;
    }
    return false;
  }
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
        std::cout << recorrer->getData() << " ";
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
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getPrev();
      }
    }
    std::cout << '\n';
  }
};