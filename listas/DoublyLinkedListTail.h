#include "../Nodo.h"

template <class T> class DoublyLinkedListTail {
private:
  Nodo<T> *head;
  Nodo<T> *tail;

public:
  DoublyLinkedListTail() {
    this->head = nullptr;
    this->tail = nullptr;
  }
  void PushFront(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->head) {
      this->head = this->tail = nodo;
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
    if (!this->head) {
      this->tail = nullptr;
      return;
    }
    this->head->setPrev(nullptr);
  }
  void PushBack(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->tail) {
      this->head = this->tail = nodo;
      return;
    }
    this->tail->setNext(nodo);
    nodo->setPrev(this->tail);
    this->tail = nodo;
  }
  T TopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacia");
    }
    return this->tail->getDato();
  }
  void PopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacia");
    }
    this->tail = this->tail->getPrev();
    if (!this->tail) {
      this->head = nullptr;
      return;
    }
    this->tail->setNext(nullptr);
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
    if (this->head->getDato() == dato) {
      this->PopFront();
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getDato() == dato) {
        if (recorrer->getNext() == this->tail) {
          recorrer->setNext(nullptr);
          this->tail = recorrer;
          return;
        }
        recorrer->getNext()->getNext()->setPrev(recorrer);
        recorrer->setNext(recorrer->getNext()->getNext());
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("no se encontro el dato");
  }
  bool Empty() { return !this->head; }
  
  void AddBefore(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    if (nodo == this->head) {
      this->head = data;
    } else {
      nodo->getPrev()->setNext(data);
    }
    data->setPrev(nodo->getPrev());
    nodo->setPrev(data);
    data->setNext(nodo);
  }
  void AddAfter(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    if (nodo == this->tail) {
      this->tail = data;
    } else {
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
    if (this->tail) {
      Nodo<T> *recorrer = this->tail;
      while (recorrer) {
        std::cout << recorrer->getDato() << " ";
        recorrer = recorrer->getPrev();
      }
    }
    std::cout << '\n';
  }
};