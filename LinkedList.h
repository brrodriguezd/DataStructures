#include "Nodo.h"

template <class T> class LinkedList {
private:
  Nodo<T> *head;

public:
  LinkedList() { this->head = NULL; }
  void PushFront(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
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
  }
  void PushBack(T dato) {
    if (!this->head) {
      this->PushFront(dato);
    } else {
      Nodo<T> *nodo = new Nodo<T>(dato);
      Nodo<T> *recorrer = this->head;
      while (recorrer->getNext()) {
        recorrer = recorrer->getNext();
      }
      recorrer->setNext(nodo);
    }
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
      this->head = this->head->getNext();
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getData() == dato) {
        recorrer->setNext(recorrer->getNext()->getNext());
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No existe el dato");
  }
  bool Empty() {
    if (!this->head) {
      return true;
    }
    return false;
  }
  void AddBefore(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    data->setNext(nodo);
    if (nodo == this->head) {
      this->head = data;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      if (recorrer->getNext() == nodo) {
        recorrer->setNext(data);
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No existe el dato");
  }
  void AddAfter(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    data->setNext(nodo->getNext());
    nodo->setNext(data);
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
    LinkedList<T> listainv;
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      listainv.PushFront(recorrer->getData());
      recorrer = recorrer->getNext();
    }
    listainv.Display();
  }
};