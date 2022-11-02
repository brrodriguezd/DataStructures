#include "../Nodo.h"

template <class T> class DoublyLinkedListTail {
private:
  Nodo<T> *head;
  Nodo<T> *tail;

public:
  DoublyLinkedListTail() {
    this->head = NULL;
    this->tail = NULL;
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
    return this->head->getData();
  }
  void PopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    this->head = this->head->getNext();
    if (!this->head) {
      this->tail = NULL;
      return;
    }
    this->head->setPrev(NULL);
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
    return this->tail->getData();
  }
  void PopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacia");
    }
    this->tail = this->tail->getPrev();
    if (!this->tail) {
      this->head = NULL;
      return;
    }
    this->tail->setNext(NULL);
  }
  Nodo<T> *Find(T dato) {
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
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
        if (recorrer->getNext() == this->tail) {
          recorrer->setNext(NULL);
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
  bool Empty() {
    if (!this->head) {
      return true;
    }
    return false;
  }
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
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getNext();
      }
    }
    std::cout << '\n';
  }
  void DisplayBackwards() {
    if (this->tail) {
      Nodo<T> *recorrer = this->tail;
      while (recorrer) {
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getPrev();
      }
    }
    std::cout << '\n';
  }
};